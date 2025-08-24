#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main() {
    auto now = system_clock::now();
    time_t now_time_t = system_clock::to_time_t(now);
    tm *now_tm = localtime(&now_time_t);

    int seconds_passed = now_tm->tm_hour * 3600 + now_tm->tm_min * 60 + now_tm->tm_sec;
    int seconds_remaining = 86400 - seconds_passed;
    cout << "Remaining seconds today: " << seconds_remaining << endl;
    return 0;
} 
