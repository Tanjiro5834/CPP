#include <iostream>
using namespace std;
int main(){
	int x = 10, y = 3;
	while(x - y >= 0){
		if(x - y < 0) break;
		cout << "x = " << x << endl;
		x -= y;
	}
	cout << x << endl;
}