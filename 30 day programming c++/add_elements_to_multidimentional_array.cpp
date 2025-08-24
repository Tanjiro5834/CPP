#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    arr.back().push_back(10);
    
    for(const auto &row : arr){
    	for(int c : row){
    		cout << c << " ";
		}
	}
}