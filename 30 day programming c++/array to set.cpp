#include <set>
#include <iostream>
using namespace std;
int main(){
	int arr[] = {1, 2, 3, 4, 5, 1};
	set<int> s{1, 2, 3, 4, 5, 1};
	
	set<int> s1(begin(arr), end(arr));
	cout << "array to set: ";
	for(auto s : s1){
		cout << s << " ";
	}
}