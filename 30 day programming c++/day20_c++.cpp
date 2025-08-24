#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int first = 1, second = 1;
	while(true){
		cout << "Press any key to show fibonacci sequence one by one: ";
		char key = _getch();
		
		cout << first << " " << endl;
		int nxt = first + second;
		first = second;
		second = nxt;
	}
}