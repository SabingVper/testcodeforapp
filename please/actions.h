#pragma once
#ifndef actions_h
#define actions_h

struct Action {
    int date[3]; // Stores Day/Month/Year
    double amount; // Stores Amount
    char action; // Stores action "T" == Transfer, "A" == Add, "R" == Remove
    int accountTo; // Stores where the money is going to
    int accountFrom; // Stores where the money is coming from
    std::string reason; // Stores a String of the comment

    void store(int dmy[3], double amo, char act, int to, int from, std::string com) {
        for (int i = 0; i < 3; i++) {
            date[i] = dmy[i];
        }
        amount = amo;
        action = act;
        accountTo = to;
        accountFrom = from;
        reason = com;
    }
    /**
        @title 

    */
    void print() {

    }
};


#endif // !actions_h