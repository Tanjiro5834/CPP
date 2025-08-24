#include <iostream>
using namespace std;

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(arr) / sizeof(arr[0]);
	int count = 0;
	for(int i : arr){
		count++;
		cout << i;
		if(count != size) cout << " ";
	}
	return 0;
}