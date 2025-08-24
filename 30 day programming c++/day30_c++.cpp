#include <iostream>
#include <ctime>
#include <cstdlib>
int roll();
using namespace std;

int roll(){
	int low = 1, high = 6;
	int value = low + rand() % (high - low + 1);
	return value;
}
int main(){
	srand(time(0));
	cout << "Random value from 1-6: " << roll();
	return 0;
}