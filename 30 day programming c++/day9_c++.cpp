#include <bits/stdc++.h> 
using namespace std;

int main(){
	vector<string> array;
	ostringstream os;
	
	array.push_back("coffee");
	array.push_back("milk");
	array.push_back("tea");
	
	for(size_t i = 0; i < array.size(); ++i){
		os << array[i];
		if(i < array.size() - 1) os << ", "; 
	}
	string concatenated = os.str();
	cout << concatenated << endl;
	return 0;
}