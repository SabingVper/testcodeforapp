#include <iostream>
#include <vector>

struct User
{
    std::string name;
    std::vector<double> accounts;
    int transcationStart;
    int lastLine;

    void add(int acc, double amount) {
        accounts.at(acc) = accounts.at(acc) + amount;
    }
    void remove(int acc, double amount) {
        accounts.at(acc) = accounts.at(acc) - amount;
    }
    void transfer(int acc1, int acc2, double amount) {
        accounts.at(acc1) = accounts.at(acc1) - amount;
        accounts.at(acc2) = accounts.at(acc2) + amount;
    }
    double getAmount(int acc) {
        return accounts.at(acc);
    }

};