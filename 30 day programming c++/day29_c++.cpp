#include <iostream>

int greatest(int x, int y, int z);
using namespace std;

int greatest(int x, int y, int z){
	if(x > y || x > z){
		return x;
	}else if(y > x || y > z){
		return y;
	}else if(z > x || z > y){
		return z;
	}
	return 0;
}
int main(){
	int x = 10, y = 2, z = 5;
	cout << greatest(x, y, z);
}