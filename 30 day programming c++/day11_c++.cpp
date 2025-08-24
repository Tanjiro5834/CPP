#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	string word = "awesome";
	vector<char> arr(word.begin(), word.end());
	
	for(size_t i = 0; i < arr.size(); ++i){
		cout << arr[i];
		if(i != arr.size() - 1)	cout << ", ";
	}
}