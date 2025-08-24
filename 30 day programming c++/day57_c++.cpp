#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;
int main(){
	vector<int> tokens;
	int number;
	cout << "Enter a future date: ";
	
	string future;
	getline(cin, future);
	
	istringstream iss(future);
	while(iss >> number){
		tokens.push_back(number);
	}
	
	if(tokens.size() < 3){
        cout << "Invalid date format. Please enter YYYY MM DD." << endl;
        return 1;
    }
	
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
	
	tm inputDate = {};  
	
    inputDate.tm_year = tokens[0] - 1900;      
    inputDate.tm_mon = tokens[1] - 1;
    inputDate.tm_mday = tokens[2];
    
    inputDate.tm_hour = 0;
	inputDate.tm_min  = 0;
	inputDate.tm_sec  = 0;

    time_t inputTime = mktime(&inputDate);
    
    if (inputTime == -1) {
        cout << "Invalid date!" << endl;
    } else {
        double seconds = difftime(inputTime, now);
        int days = seconds / 86400;
        
        if (seconds <= 0) {
		    cout << "Date must be in the future." << endl;
		} else {
		    cout << "There are " << days << " days remaining until " << future << "." << endl;
		}

	}
	return 0;
}