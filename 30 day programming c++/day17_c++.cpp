#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
	unordered_set<char> uniqueChar;
	vector<char> orderedUnique;
	
	string word = "tekken 7";
	for(char c : word){
		if(uniqueChar.find(c) == uniqueChar.end()){
			uniqueChar.insert(c);
			orderedUnique.push_back(c);
		}
	}
	for(char i : orderedUnique) cout << i << " ";
}