#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    string text = "test word";
    int len = text.length();
    
    char arr[len + 1];
    strcpy(arr, text.c_str());
    arr[0] = toupper(arr[0]);
    string str(arr);
    
    cout << str;
}