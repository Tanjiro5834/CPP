#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    string input;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> input;

    tm timeStruct = {};
    istringstream ss(input);
    ss >> get_time(&timeStruct, "%Y-%m-%d");

    if (ss.fail()) {
        cout << "Invalid date format." << endl;
        return 1;
    }

    timeStruct.tm_hour = 0;
    timeStruct.tm_min = 0;
    timeStruct.tm_sec = 0;

    time_t timestamp = mktime(&timeStruct);
    cout << "Unix timestamp: " << timestamp << endl;
    return 0;
}
