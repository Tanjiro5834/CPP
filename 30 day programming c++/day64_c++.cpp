#include <iostream>
#include <string>
using namespace std;
int main(){
	string email = "nathz@gmail.com";
	size_t target = email.find("@");
	
	if(target != string::npos){
		string domain = email.substr(target + 1);
		cout << "domain: " << domain;
	}
}