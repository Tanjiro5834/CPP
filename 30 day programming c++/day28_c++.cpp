#include <iostream>
#include <cmath>

int square(int x);
using namespace std;

int square(int x){
	int result = sqrt(x);
	return result;
}
int main(){
	int n = 25;
	cout << square(n) << endl;
}