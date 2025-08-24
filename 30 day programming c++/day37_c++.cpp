#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    auto now = system_clock::now();
    auto today = floor<days>(now);
    auto tomorrow = today + days{1};
    auto remaining = duration_cast<microseconds>(tomorrow - now);
    cout << "Remaining microseconds today: " << remaining.count() << endl;
    return 0;
}
