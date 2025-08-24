#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    auto now = system_clock::now();
    auto duration = now.time_since_epoch();

    auto seconds = duration_cast<seconds>(duration);
    auto milliseconds = duration_cast<milliseconds>(duration);

    cout << "Unix Timestamp in seconds: " << seconds.count() << endl;
    cout << "Unix Timestamp in milliseconds: " << milliseconds.count() << endl;

    return 0;
}
