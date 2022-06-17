#pragma once
#ifndef actions_h_
#include <string>
#include <vector>

class Action {
    public: 
        Action();
        Action(std::vector<int>, double, char, int, int, std::string);
        ~Action();
        //void store(std::vector<int> dmy, double amo, char act, int to, int from, std::string com);
        void savetoFile(std::string &path);
        void print();
        std::vector<int> getDate();
        double getAmount();
        char getAction();
        int getAccountTo();
        int getAccountFrom();
        std::string getReason();
        void setDate(int d);
        void setAmount(double amo);
        void setAction(char act);
        void setAccountTo(int to);
        void setAccountFrom(int from);
        void setReason(std::string str);
    private:
        std::vector<int> date; // Stores Day/Month/Year/Year Day
        double amount; // Stores Amount
        char action; // Stores action "T" == Transfer, "A" == Add, "R" == Remove
        int accountTo; // Stores where the money is going to
        int accountFrom; // Stores where the money is coming from
        std::string reason; // Stores a String of the comment
};

#endif // !actions_h_
