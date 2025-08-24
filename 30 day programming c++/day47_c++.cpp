#include <iostream>
using namespace std;
int main(){
	string words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
	int size = sizeof(words) / sizeof(words[0]);
	for(int i = 0; i <= size; i++){
		cout << words[i] << endl;
	}
}