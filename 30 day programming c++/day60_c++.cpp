#include <iostream>
using namespace std;

int main(){
	string word = "this is awesome programming";
	string reversed = "";
	
	cout << "Original: " << word << endl;
	
	for(int i = word.length() - 1; i >= 0; i--){
		reversed += word[i];
	}
	
	cout << "Reversed word: " << reversed;
}