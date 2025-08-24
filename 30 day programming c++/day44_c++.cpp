#include <iostream>
#include <cmath>
using namespace std;
int main(){
	cout << "Enter a float number: ";
	float n;
	cin >> n;
	float rounded = round(n * 100.0) / 100.0;
	cout << rounded;
}