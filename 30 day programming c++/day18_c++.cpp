#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
	vector<char> unique;
	unordered_set<char> seen;
	
	string word;
	cout << "Enter a word: ";
	getline(cin, word);
	
	for(char c : word){
		if(seen.find(c) == seen.end()){
			seen.insert(c);
			unique.push_back(c);
		}
	}
	for(char ch : unique) cout << ch << " ";
	return 0;
}