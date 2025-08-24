#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_ATTEMPTS 5
#define PASSWORD_LENGTH 8

class User {
public:
    string username;
    string fullname;
    string password;
    static vector<User> userData;  // Static to share the user data across all instances

    User(string n, string f, string p){
        username = n;
        fullname = f;
        password = p;
    }

    // default constructor
    User(){
        username = "unknown";
        fullname = "unknown";
        password = "empty";
    }

    string getUsername() const {
        return username;
    }

    string getFullname() const {
        return fullname;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(string p){
        password = p;
    }

    void toString(){
        cout << "Username: " << username << ", Full name: " << fullname << ", Password: " << password << endl;
    }

    void registerUser() {
        string username, fullname, password;
        while(true){
        	cout << "Enter your preferred username: ";
	        getline(cin, username);
	        cout << "Full name: ";
	        getline(cin, fullname);
	        
	        // check duplicate or existing credentials
	        bool nameExists = false;
	        for(const User &user: userData){
	            if(user.fullname == fullname){
	                cerr << "Name already exists, Try again.\n";
	                nameExists = true;
	                continue;
	            }
	        }
			
			if(!nameExists){
				cout << "Password: ";
				getline(cin, password);
				
				User newUser(username, fullname, password);
		        userData.push_back(newUser);  
		        cout << "User registered.\n";
		        break;
			}
		}
    }

    void loginUser() {
        bool loggedIn = false;
        string username, password;

        int attemptCount = 0;
        while(attemptCount < MAX_ATTEMPTS){
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);

            attemptCount++;
            for (auto it = userData.begin(); it != userData.end(); ++it) {
                if(username == it->getUsername() && password == it->getPassword()){
                    loggedIn = true;
                    cout << "Logged in successfully.\n";
                    break;
                } else {
                    cout << "Invalid username or password. Attempts remaining: " << (MAX_ATTEMPTS - attemptCount) << endl;
                }
            }
            if(loggedIn) break;
        }
    }
};

vector<User> User::userData;

int main() {
    int choice;
    User user;  
    while (true) {  
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();  

        switch(choice){
            case 1:
                user.registerUser();
                break;
            case 2:
                user.loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0; 
            default:
                cout << "Invalid choice.\n";
        }
    }
}
