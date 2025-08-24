#include <iostream>
#include <string>
using namespace std;

int input;
string output;

int main(){
	cout << "Enter a number from 0-10 to translate: ";
	cin >> input;
	
	output = to_string(input);
	if(input == 1) output = "isa";
	else if (input == 2) output = "dalawa";
    else if (input == 3) output = "tatlo";
    else if (input == 4) output = "apat";
    else if (input == 5) output = "lima";
    else if (input == 6) output = "anim";
    else if (input == 7) output = "pito";
    else if (input == 8) output = "walo";
    else if (input == 9) output = "siyam";
    else if (input == 10) output = "sampu";
    else output = "Invalid input";
	cout << "Translation: " << output;
	return 0;
}