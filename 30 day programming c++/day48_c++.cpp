#include <iostream>
#include <string>

void eng();
void kor();
using namespace std;

void eng(){
	cout << "one\ntwo\nthree\nfour\nfive\nsix\nseven\neight\nnine\nten\n";
}

void kor(){
	cout << "hana\n"
              << "dul\n"
              << "set\n"
              << "net\n"
              << "daseot\n"
              << "yeoseot\n"
              << "ilgop\n"
              << "yeodeol\n"
              << "ahop\n"
              << "yeol\n";
}

int main(){
	string chosen;
	cout << "Choose a language, English/Korean: ";
	getline(cin, chosen);
	if(chosen == "english"){
		eng();
	}else if(chosen == "korean"){
		kor();
	}
}