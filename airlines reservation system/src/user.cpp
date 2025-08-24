#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "User_Operator.h"

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PASSWORD = ""; 
const char* DATABASE = "rfs_db";

const int total_seat = 20;
vector<string> seats(total_seat, "X");

User_Operator db;

int connect(){
    if (!db.connect(HOST, USER, PASSWORD, DATABASE)) {
        cout << "Failed to connect to the database." << endl;
        return 1;
    }
}

void printSeats(){
    cout << "Available seats:\n";
    for(int i = 0 ; i < total_seat; i++){
        cout << setw(4) << (i + 1) << ". " << setw(10) << seats[i] << "  ";
        if ((i + 1) % 5 == 0) cout << endl;
    }
    cout << endl;
}

void reserveSeats(int seatNumber){
    if (seatNumber < 1 || seatNumber > total_seat) {
        cout << "Invalid seat number! Choose between 1 and " << total_seat << ".\n";
        return;
    }

    db.fetchAvailableSeats();

    string status = "reserved";
    if(seats[seatNumber - 1] == status){
        cout << "Seat " << seatNumber << " is already reserved." << endl;
    }else{
        seats[seatNumber - 1] = status;
        db.reserveSeat()
    }
}

void menu(){
    vector<string> choices = {"Reserve seat", "Available tickets", "Flight schedule", "Flight details"};
    for(size_t i = 0; i < choices.size(); i++){
        cout << (i + 1) << ". " << choices[i] << endl;
    }

    int choice;
    int seatChoice;
    while(true){
        cout << "Choose an option: ";
        cin >> choice;

        switch(choice){
            case 1:
            printSeats();

            cout << "Select your seats: ";
            cin >> seatChoice;
            cin.ignore();

            if(choice == 0){
                cout << "Enter valid seat." << endl;
            }

            reserveSeats(seatChoice);
            break;

            case 2:

        }
    }
}

int main(){

}