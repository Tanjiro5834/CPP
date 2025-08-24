#include <iostream>
using namespace std;
int main(){
	int n;
	cout << "Enter a number: ";
	cin >> n;
	
	if(n < 0){
		cout << "too small, not allowed.";
	}else if(n > 100){
		cout << "too high, not allowed.";
	}else if(n >= 100){
		cout << "Invalid number! Please enter a number between 0-100.";
	}else{
		cout << "accepted!";
	}
}