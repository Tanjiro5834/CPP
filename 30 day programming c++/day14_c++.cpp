#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(){
	string name = "john";
	int length = sizeof(name) / sizeof(name[0]);
	
	char arr[length + 1];
	strcpy(arr, name.c_str());
	arr[0] = toupper(arr[0]);
	string str(arr);
	cout << str;
	
	return 0;
}