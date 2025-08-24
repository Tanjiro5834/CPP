#include <iostream>
#include <sstream>

using namespace std;
int main(){
	string s = "good thing";
	stringstream ss(s);
	
	string word;
	while(ss >> word) cout << word << endl;
	
	cout << endl;
}