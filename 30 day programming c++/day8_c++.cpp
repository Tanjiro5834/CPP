#include <iostream>
#include <string>
using namespace std;

int main(){
	bool value = true;
	string str = "boolean value is ";
	string convert = value ? "true" : "false";
	cout << str << " " << convert;
}