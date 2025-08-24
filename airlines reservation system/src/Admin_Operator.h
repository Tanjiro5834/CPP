#ifndef DATABASE_OPERATOR_H
#define DATABASE_OPERATOR_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <iostream>
#include <string>

using namespace std;

class Database_Operator {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

public:
    Database_Operator();
    ~Database_Operator();
    bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
    void insert(const int &flightNo, const string &flightName, const string &from, const string &destination, const string &flightTime, const float &amount, const char &availability);
    void fetch();
    void update(int id, const std::string& newEmail);
    void remove(int id);
};

#endif // DATABASE_OPERATOR_H