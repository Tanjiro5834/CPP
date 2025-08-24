#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int main() {
    auto now = system_clock::now();
    auto yesterday = now - hours(24);
    time_t t = system_clock::to_time_t(yesterday);
    cout << "Yesterday's date: " << put_time(localtime(&t), "%Y-%m-%d") << endl;
    return 0;
}
