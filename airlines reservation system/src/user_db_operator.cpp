#include "User_Operator.h"

// Constructor
User_Operator::User_Operator() {
    driver = sql::mysql::get_mysql_driver_instance();
    con = nullptr;
}

// Destructor
User_Operator::~User_Operator() {
    if (con) {
        delete con;
    }
}

// Connect to the database
bool User_Operator::connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database) {
    try {
        con = driver->connect(host, user, password);
        con->setSchema(database);
        return true;
    } catch (sql::SQLException &e) {
        cout << "Error connecting to database: " << e.what() << endl;
        return false;
    }
}

// Fetch available seats (those that are not reserved)
void User_Operator::fetchAvailableSeats() {
    try {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT seat_number FROM seats WHERE seat_number NOT IN (SELECT selected_seat FROM user_table");

        if (res->rowsCount() == 0) {
            cout << "No available seats!" << endl;
        } else {
            cout << "Available seats:" << endl;
            while (res->next()) {
                int seatNumber = res->getInt("seat_number");
                cout << "Seat " << seatNumber << " is available." << endl;
            }
        }

        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        cout << "Error fetching data: " << e.what() << endl;
    }
}

// Reserve a seat by updating its status in the database
void User_Operator::reserveSeat(int seatNumber, const string& name, const string& ticketType) {
    try {
        sql::Statement *stmt = con->createStatement();
        string query = "UPDATE seats SET status = 'Reserved' WHERE seat_number = " + to_string(seatNumber) + " AND status = 'Available'";
        int affectedRows = stmt->executeUpdate(query);
        
        if (affectedRows > 0) {
            cout << "Seat " << seatNumber << " successfully reserved!" << endl;
        } else {
            cout << "Seat " << seatNumber << " is already reserved or does not exist." << endl;
        }

        delete stmt;
    } catch (sql::SQLException &e) {
        cout << "Error reserving seat: " << e.what() << endl;
    }
}

// Cancel a reservation (change the seat's status back to "Available")
void User_Operator::cancelReservation(int seatNumber) {
    try {
        sql::Statement *stmt = con->createStatement();
        string query = "UPDATE seats SET status = 'Available' WHERE seat_number = " + to_string(seatNumber) + " AND status = 'Reserved'";
        int affectedRows = stmt->executeUpdate(query);

        if (affectedRows > 0) {
            cout << "Reservation for seat " << seatNumber << " successfully canceled." << endl;
        } else {
            cout << "Seat " << seatNumber << " is not reserved or does not exist." << endl;
        }

        delete stmt;
    } catch (sql::SQLException &e) {
        cout << "Error canceling reservation: " << e.what() << endl;
    }
}
