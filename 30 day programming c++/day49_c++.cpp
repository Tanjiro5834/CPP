#include <iomanip>
#include <iostream>
#include <ctime>
#include <map>
using namespace std;

void print(const string& label, int offsethours){
	time_t now = time(nullptr);
	tm* utc_tm = gmtime(&now);
	utc_tm->tm_hour += offsethours;
    std::mktime(utc_tm);
    cout << label << ": " << put_time(utc_tm, "%I:%M %p") << endl;
}

int main() {
	map<string, int> tz = {{"New York", -4},{"Manila", 8},{"Tokyo", 9}};
	int count = 0;
	for(auto it = tz.begin(); it != tz.end() && count < 3; ++it){
		print(it->first, it->second);
		count++;
	}
}
