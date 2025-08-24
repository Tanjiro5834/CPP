#include <iostream>
#include <string>
using namespace std;

string reverse(string str){
	if(str.size() == 0){
		return str;
	}
	
	return reverse(str.substr(1)) + str[0];
}

int main(){
	string str = "great job";
	cout << reverse(str);
}