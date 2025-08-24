#ifndef USER_OPERATOR_H
#define USER_OPERATOR_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User_Operator {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

public:
    User_Operator();
    ~User_Operator();
    bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
    void fetchAvailableSeats();
    void reserveSeat(int seatNumber, const string& name, const string& ticketType);
    void cancelReservation(int seatNumber);
};

#endif // USER_OPERATOR_H
