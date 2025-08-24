#include <iostream>
using namespace std;

int main(){
    string txt = "number";
    int num = 5;
    
    char str[50];
    sprintf(str, "%d", num);
    
    cout << txt << " " << str;
    return 0;
}