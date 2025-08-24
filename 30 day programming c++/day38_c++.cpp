#include <iostream>

using namespace std;

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    cout << year << (isLeap ? " is " : " is not ") << "a leap year." << endl;

    return 0;
}
