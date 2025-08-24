#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<string> arr = {"apple", "banana", "strawberry"};
	for(string a : arr){
		cout << a << " ";
	}
	
	//remove last item
	arr.pop_back();
	
	cout << "\n";
	
	for(string x : arr){
		cout << x << " ";
	}
}