#pragma once
#ifndef user_h_
#include "actions.h"
#include <vector>

class User {
    public:
        User();
        User(std::string, std::vector<double>, int, int, std::vector<Action>);
        ~User();
        void setName(std::string str);
        std::string getName();
        void setAccounts(double amount);
        std::vector<double> getAccounts();
        int getTranscationStart();
        void setTranscationStart(int start);
        int getLastLine();
        void setLastLine(int last);
        std::vector<Action> getTranscationList();
        void addToTranscationList(Action transcation);
        double getAmount(int acc);
        void add(int acc, double amount);
        void remove(int acc, double amount);
        void transfer(int acc1, int acc2, double amount);
    private:
        std::string name;
        std::vector<double> accounts;
        int transcationStart;
        int lastLine;
        std::vector<Action> transcationList;
};

#endif // !user_h_

