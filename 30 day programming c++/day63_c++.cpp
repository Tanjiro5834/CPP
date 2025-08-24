#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
	vector<char> ch = {'g', 'o', 'o', 'd'};
	for(char c : ch){
		string str(1, c);
		cout << str;
	}
}