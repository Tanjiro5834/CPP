#include <iostream>

int sum(int x, int y);

using namespace std;

int sum(int x, int y){return x + y;}

int main(){
	int a = 4, b = 6;
	int r = sum(a, b);
	cout << r;
}