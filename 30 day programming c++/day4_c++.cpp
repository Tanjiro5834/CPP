#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string word = "this is a sample text";
    int len = word.length();
    
    //to upper
    for(int i = 0; i < len; i++) word[i] = toupper(word[i]);
    
    //to lower using transform
    string word2 = "AWESOME";
    transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
    
    cout << word << "\n" << word2;
    return 0;
}