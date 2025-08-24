#include <bits/stdc++.h>
using namespace std;

int main(){
	string txt = "great,day,fantastic";
	stringstream ss(txt);
	
	string temp;
	char delimiter = ',';
	while(getline(ss, temp, delimiter)){
		cout << "\"" << temp << "\"" << " ";
	}
	return 0;
}