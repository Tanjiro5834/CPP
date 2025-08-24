#include <bits/stdc++.h>
using namespace std;

int main(){
	string i;
	cout << "Enter a number: ";
	getline(cin, i);
	
	for(char c : i){
		if(isdigit(c)){
			cout << "its a number!";
		}else{
			cout << "its not a number.";
		}
	}
}