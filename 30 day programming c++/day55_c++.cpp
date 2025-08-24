#include <iostream>
#include <cmath>
using namespace std;

double cubeSolver(double base, double exp){
	return pow(base, exp);
}
int main(){
	double base = 10, exponent = 3;
	cout << "Cube of " << base << ": " << cubeSolver(base, exponent);
}