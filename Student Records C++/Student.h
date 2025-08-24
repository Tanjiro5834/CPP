#include <iostream> //i/o
#include <vector> //database for the student
#include <string> //string manipulation and control
#include <random> 
#include <chrono>
#include <algorithm>

using namespace std;

//parent class 
class Student {
protected:
    string studentID;
    string name;
    int age;

public:
    Student(string id, string n, int a) : studentID(id), name(n), age(a) {}

    virtual void displayInfo() {  // Virtual for polymorphism
        std::cout << "ID: " << studentID << "\nName: " << name << "\nAge: " << age << std::endl;
    }

    virtual ~Student() {}  // Virtual destructor
};


//subclasses
class Undergraduate : public Student {
private:
    int yearLevel;
    string major;

public:
    Undergraduate(string id, string n, int a, int y, string m)
        : Student(id, n, a), yearLevel(y), major(m) {
    }

    void displayInfo() override {
        Student::displayInfo();  // Call base class method
        cout << "Year Level: " << yearLevel << "\nMajor: " << major << endl;
    }
};

class Graduate : public Student {
private:
    string researchTopic;
    string advisorName;

public:
    Graduate(string id, string n, int a, string topic, string advisor)
        : Student(id, n, a), researchTopic(topic), advisorName(advisor) {
    }

    void displayInfo() override {
        Student::displayInfo();
        cout << "Research Topic: " << researchTopic << "\nAdvisor: " << advisorName << endl;
    }
};


vector<Student*> studentDb;

string generateId() {
    static const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string id;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rng(seed);
    uniform_int_distribution<int> dist(0, chars.size() - 1);
}

void addStudent() {
    string type, name;
    int age, yearLevel;
    double grade;
    string major;

    cout << "Type of student e.g. graduate, undergraduate: ";
    getline(cin, type);

    if (!type.empty()) {
        if (type == "Undergraduate") {
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cout << "Major: ";
            getline(cin, major);
            cout << "Year level: ";
            cin >> yearLevel;
            studentDb.push_back(new Undergraduate(generateId(), name, age, yearLevel, major));
        }
        else if (type == "Graduate") {
            string topic, advisor;
            cout << "Research Topic: ";
            getline(cin, topic);
            cout << "Advisor: ";
            getline(cin, advisor);

            if (!topic.empty() && !advisor.empty()) {
                studentDb.push_back(new Graduate(generateId(), name, age, topic, advisor));
            }
        }
    }
}

int main() {
    cout << "1. Add student\n2. Display all students\n3. Search for a student\n4. Delete student\n5. Save and load to a file";

    int choice;
    cout << "YOUR CHOICE: ";
    cin >> choice;

    switch (choice) {
    case 1:
        addStudent();
    }
}