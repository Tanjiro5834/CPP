#include <iostream>
#include <ctime>
using namespace std;
int main(){
	time_t ts;
	time(&ts);
	cout << ctime(&ts);
	return 0;
}