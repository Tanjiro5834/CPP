#include <iostream>
#include <string>
using namespace std;

int main(){
	float val = 3.4f;
	string str = "the float value is ";
	string toStr = to_string(val);
	cout << str << " " << toStr;
}