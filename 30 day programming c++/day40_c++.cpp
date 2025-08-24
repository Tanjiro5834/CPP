#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    time_t now = time(nullptr);
    tm *utc = gmtime(&now);
    utc->tm_hour -= 4; // UTC-4 for EDT (approximation)
    mktime(utc); // normalize structure

    cout << "New York City time: " << put_time(utc, "%Y-%m-%d %H:%M:%S") << " (UTC-4 EDT approx)" << endl;
    return 0;
}
