#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

void printCurrentDate() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    cout << put_time(ltm, "%Y-%m-%d") << " ";
}

void printCurrentTime() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    cout << put_time(ltm, "%H:%M:%S") << endl;
}

int main() {
    cout << "Current Date and Time: ";
    printCurrentDate();
    printCurrentTime();
    return 0;
}
