#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Before" << endl;
	for(int i : array){
		cout << i << " ";
	}
	
	cout << "\n\n";
	
	array.emplace_back(10);
	
	cout << "After" << endl;
	for(int j : array){
		cout << j << " ";
	}
}