#include "user.h"
#include <iostream>

User::User() {
    name = "tmp";
    accounts = std::vector<double>{};
    transcationStart = 0;
    lastLine = 0;
    transcationList = std::vector<Action>{};
}
User::User(std::string str, std::vector<double> vec, int start, int last, std::vector<Action> action) {
    name = str;
    accounts = vec;
    transcationStart = start;
    lastLine = last;
    transcationList = action;
}
User::~User() {
    std::cout << "User " << name << " has finshed" << std::endl;
}

void User::add(int acc, double amount) {
    accounts.at(acc) = accounts.at(acc) + amount;
}
void User::remove(int acc, double amount) {
    accounts.at(acc) = accounts.at(acc) - amount;
}
void User::transfer(int acc1, int acc2, double amount) {
    accounts.at(acc1) = accounts.at(acc1) - amount;
    accounts.at(acc2) = accounts.at(acc2) + amount;
}
double User::getAmount(int acc) {
    return accounts.at(acc);
}
std::string User::getName() {
    return name;
};
std::vector<double> User::getAccounts() {
    return accounts;
};
int User::getTranscationStart() {
    return transcationStart;
};
int User::getLastLine() {
    return lastLine;
};
std::vector<Action> User::getTranscationList() {
    return transcationList;
};
void User::setName(std::string str) {
    name = str;
};

void User::setAccounts(double amount) {
    accounts.push_back(amount);
};

void User::setTranscationStart(int start) {
    transcationStart = start;
};

void User::setLastLine(int last) {
    lastLine = last;
};

void User::addToTranscationList(Action transcation) {
    transcationList.push_back(transcation);
};