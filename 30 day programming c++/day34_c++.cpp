#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    cout << "Formatted DateTime: " << put_time(ltm, "%a %b %d %Y %H:%M:%S") << endl;

    return 0;
}
