#include "Admin_Operator.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>


using namespace std;

// Constructor
Database_Operator::Database_Operator() {
    driver = sql::mysql::get_mysql_driver_instance();
    con = nullptr;
}

// Destructor
Database_Operator::~Database_Operator() {
    if (con) {
        delete con;
    }
}

bool Database_Operator::connect(const string& host, const string& user, const string& password, const string& database) {
    try {
        con = driver->connect(host, user, password);
        con->setSchema(database);
        cout << "Connected to the database successfully!" << endl;
        return true;
    } catch (sql::SQLException &e) {
        cerr << "Error connecting to the database: " << e.what() << endl;
        return false;
    }
}

// Insert data into the database
void Database_Operator::insert(const int &flightNo, const string &flightName, const string &from, 
                               const string &destination, const string &flightTime, 
                               const float &amount, const char &availability) {
    try {
        sql::PreparedStatement *pstmt = con->prepareStatement(
            "INSERT INTO flights (flightNo, flightName, fromLocation, destination, flightTime, amount, availability) "
            "VALUES (?, ?, ?, ?, ?, ?, ?)");

        // Set values in prepared statement
        pstmt->setInt(1, flightNo);
        pstmt->setString(2, flightName);
        pstmt->setString(3, from);
        pstmt->setString(4, destination);
        pstmt->setString(5, flightTime);
        pstmt->setDouble(6, amount);
        pstmt->setString(7, string(1, availability));

        // Execute query
        pstmt->executeUpdate();

        cout << "Flight data inserted successfully!" << endl;

        delete pstmt;  // Clean up
    } catch (sql::SQLException &e) {
        cerr << "Error inserting flight data: " << e.what() << endl;
    }
}


// Fetch data from the database
void Database_Operator::fetch() {
    try {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM frs_db");

        while (res->next()) {
            cout << "ID: " << res->getInt("id") << " "
                      << "Name: " << res->getString("name") << " "
                      << "Email: " << res->getString("email") << std::endl;
        }

        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error fetching data: " << e.what() << std::endl;
    }
}

// Update data in the database
void Database_Operator::update(int id, const string& newEmail) {
    try {
        sql::Statement *stmt = con->createStatement();
        string query = "UPDATE users SET email='" + newEmail + "' WHERE id=" + std::to_string(id);
        stmt->execute(query);
        cout << "Data updated successfully!" << std::endl;
        delete stmt;
    } catch (sql::SQLException &e) {
        cerr << "Error updating data: " << e.what() << std::endl;
    }
}

// Delete data from the database
void Database_Operator::remove(int id) {
    try {
        sql::Statement *stmt = con->createStatement();
        string query = "DELETE FROM users WHERE id=" + std::to_string(id);
        stmt->execute(query);
        cout << "Data deleted successfully!" << std::endl;
        delete stmt;
    } catch (sql::SQLException &e) {
        cerr << "Error deleting data: " << e.what() << std::endl;
    }
}