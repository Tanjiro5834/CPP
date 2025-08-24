#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(){
	cout << "Enter a number: ";
	string n;
	getline(cin, n);
	for(char i : n){
		if(!isdigit(i)) cout << "its not a number.";
		else{
			cout << "its a number.";
		}
	}
}