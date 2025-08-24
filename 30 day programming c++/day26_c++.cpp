#include <iostream>
using namespace std;

int mult(int x, int y);
int divide(int x, int y);
int subt(int x, int y);

int mult(int x, int y){return x*y;}
int divide(int x, int y){return x/y;}
int subt(int x, int y){return x-y;}

int main(){
	int x = 10, y = 8;
	int a = mult(x, y);
	int b = divide(x, y);
	int c = subt(x, y);
	cout << a << endl << b << endl << c;
}