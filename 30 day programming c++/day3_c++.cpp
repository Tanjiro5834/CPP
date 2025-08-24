#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    //using algorithm
    string word = "i'm learning programming for 30 days!";
    word.erase(remove(word.begin(), word.end(), ' '),word.end());
    cout << word << endl;

    //using manual loop
    string result;
    for(char c : word){
        if(!isspace(c)) result += c;
    }
    cout << result;
    return 0;
}