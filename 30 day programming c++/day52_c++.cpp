#include <iostream>
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
    
    //remove 2 timezones
    for(int i = 0; i < 2; ++i) timeZones.pop_back();
    
    //print
    for(const auto&tz : timeZones){
    	int offset = get<0>(tz);
    	string sign = (offset >= 0) ? "+" : "-";
    	 cout << "UTC" << sign << abs(offset) << ":00"
         << " - " << get<1>(tz)
         << " - " << get<2>(tz) << endl; 
	}
}