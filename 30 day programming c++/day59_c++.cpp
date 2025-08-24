#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	string text = "laptop";
	cout << "Before: " << text << endl;
	
	reverse(text.begin(), text.end());
	
	cout << "After: " << text << endl;
}