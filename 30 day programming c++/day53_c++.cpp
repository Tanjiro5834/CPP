#include <iostream>
#include <ctime>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
int main(){
	vector<tuple<int, string, string>> timeZones = {
        {-12, "BIT", "Baker Island"},
        {-11, "NUT / SST", "American Samoa"},
        {-10, "HAST", "Hawaii"},
        {-9, "AKST", "Alaska"},
        {-8, "PST", "California"},
        {-7, "MST", "Denver"},
        {-6, "CST", "Chicago"},
        {-5, "EST", "New York"},
        {-4, "AST", "Puerto Rico"},
        {-3, "BRT", "São Paulo"},
        {-2, "GST", "South Georgia"},
        {-1, "AZOT", "Azores"},
        {0, "GMT / UTC", "London"},
        {1, "CET", "Paris"},
        {2, "EET", "Athens"},
        {3, "MSK", "Moscow"},
        {4, "GST", "Dubai"},
        {5, "PKT", "Islamabad"},
        {6, "BST", "Dhaka"},
        {7, "ICT", "Bangkok"},
        {8, "CST", "Manila"},
        {9, "JST", "Tokyo"},
        {10, "AEST", "Sydney"},
        {11, "SBT", "Solomon Islands"},
        {12, "NZST", "Auckland"}
    };
    
    //local time
    time_t now = time(nullptr);
	tm* localTime = localtime(&now);
		
	//utc time
	tm* utcTime = gmtime(&now);
	int offset = localTime->tm_hour - utcTime->tm_hour; //subtract utc hr to local hr
	if (offset > 12) offset -= 24;
	if (offset < -12) offset += 24;
		
	//Philippine Time (UTC+8), and UTC is 02:00, and your local time is 10:00, then
	//offset = 10 - 2 = 8
    
    for(const auto& tz : timeZones){
		int tzOffset = get<0>(tz);
		if(tzOffset == offset){
			string sign = (tzOffset >= 0) ? "+" : "-";
			cout << "UTC" << sign << abs(tzOffset) << ":00"
             << " - " << get<1>(tz)
             << " - " << get<2>(tz) << endl;
        	break;	
		}
	}
}