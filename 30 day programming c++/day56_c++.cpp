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
	cout << "Enter a previous date: ";
	
	string prev;
	getline(cin, prev);
	
	//extract each lines then put to vector 
	istringstream iss(prev);
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
	
	//get the first index (year)
    inputDate.tm_year = tokens.front() - 1900;      
    inputDate.tm_mon = tokens[1] - 1;
    inputDate.tm_mday = tokens[2];

    time_t inputTime = mktime(&inputDate);
    
    if (inputTime == -1) {
        cout << "Invalid date!" << endl;
    } else {
        double seconds = difftime(now, inputTime);
        int days = seconds / 86400;
        cout << "That was " << days << " days ago." << endl;
	}
	return 0;
}