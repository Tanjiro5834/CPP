#include <iostream>
using namespace std;

int main(){
	int year1, month1, day1;
    int year2, month2, day2;

    cout << "Enter first date (YYYY MM DD): ";
    cin >> year1 >> month1 >> day1;

    cout << "Enter second date (YYYY MM DD): ";
    cin >> year2 >> month2 >> day2;

    // Convert both dates to a comparable integer format: YYYYMMDD
    int date1 = year1 * 10000 + month1 * 100 + day1;
    int date2 = year2 * 10000 + month2 * 100 + day2;

    // Ternary operator to compare and output result
    (date1 > date2) ? cout << "First date is later.\n" :
    (date1 < date2) ? cout << "Second date is later.\n" :
                      cout << "Both dates are the same.\n";
}