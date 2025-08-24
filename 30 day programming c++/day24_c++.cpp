#include <bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<char,int>map;
	string word = "the quick brown fox jumps over the lazy dog.";
	for(char c : word){
		map[c]++;
	}
	cout << endl;
	for(const auto& ch : map){
		cout << "Letter: " << ch.first << " " << "Count: " << ch.second << endl;
	}
}