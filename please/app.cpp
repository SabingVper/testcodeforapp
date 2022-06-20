#include "app.h"
#include "actions.h"
#include "date.h"
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

using namespace std;


string askString(string str = "null") {
    string txt;
    if (str != "null") {
        cout << str;
    }
    cin >> txt;
    cout << endl;
    return txt;
}
double askingDouble(string str = "null") {
    double num;
    if (str != "null") {
        cout << str;
    }
    while (1) {
        if (cin >> num) {
            return num;
        }
        else {
            cout << "Invalid Input! Please input a numerical value." << endl;
            cin.clear();
            while (cin.get() != '\n'); // empty loop
        }
    }
    cout << endl;
}
int askingInt(int min, int max, string str = "null") {
    int num;
    if (str != "null") {
        cout << str;
    }
    while (1) {
        if (cin >> num) {
            if (num >= min && num <= max) {
                return num;
            }
            else {
                cout << "Invalid Input! Please input a numerical value." << endl;
                cin.clear();
                while (cin.get() != '\n'); // empty loop
            }
        }
        else {
            cout << "Invalid Input! Please input a numerical value." << endl;
            cin.clear();
            while (cin.get() != '\n'); // empty loop
        }
    }
    cout << endl;
}


App::App() {
    storePerson();
    bool inMenu = true;
    while (inMenu) {
        inMenuText();
        inMenuMethods(inMenu);
    }
}
App::App(User &per) {
    User person = per;
}
App::~App() {
    cout << "App for " << person.getName() << " Terminated" << endl;
}


void App::storePerson(){
    //string path = "C:\\Users\\Ry-Bread\\Documents\\data.txt";
    string path = "C:\\Users\\Ryan\\Desktop\\data.txt";
    ifstream f; f.open(path); string str; vector<string> contents;
    while (f.good()) {
        while (getline(f, str)) {
            contents.push_back(str);
        }
    }
    f.close();
    person.setName(contents.at(0));
    int i = 0;
    while (i < stoi(contents.at(1))) {
        person.setAccounts(stod(contents.at(2 + i)));
        i++;
    }
    person.setLastLine(contents.size());
    person.setTranscationStart(2 + i);
}
void App::printDefault() {
    clearScreen();
    int num = person.getAccounts().size();
    string str = "Name: " + person.getName() + "\nNumber of accounts: "
        + to_string(num);
    for (int i = 0; i < num; i++) {
        stringstream stream;
        double value = person.getAccounts().at(i);
        stream << fixed << setprecision(2) << value;
        string str1 = "\nAccount " + to_string(i + 1) + ": " + stream.str();
        str.append(str1);
    }
    cout << str << endl;
}
void App::storeTranscation() {
    //string path = "C:\\Users\\Ry-Bread\\Documents\\data.txt";
    string path = "C:\\Users\\Ryan\\Desktop\\data.txt";
    ifstream f; f.open(path); string str; Action a;
    int count = 0;
    do {
        if (count > person.getTranscationStart()) {
            getline(f, str);
            count++;
        }
        if (count <= person.getTranscationStart()) {
            for (int i = 0; i < 3; i++) {
                getline(f, str, ' ');
                a.setDate(stoi(str));
            }
            getline(f, str);
            a.setAmount(stod(str));
            getline(f, str);
            //strcpy_s(arr, str.c_str());
            std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
            a.setAction(cstr.at(0));
            getline(f, str);
            a.setAccountTo(stoi(str));
            getline(f, str);
            a.setAccountFrom(stoi(str));
            getline(f, str);
            a.setReason(str);
            person.addToTranscationList(a);
        }
    } while (f.good() && count < person.getLastLine());

    f.close();
}
void App::printAllTranscations() {
    clearScreen();
    for (int i = 0; i < person.getTranscationList().size(); i++) {
        cout << "-----------------------" << endl;
        person.getTranscationList().at(i).print();
    }
}
void App::inMenuText() {
    clearScreen();
    cout << "-----------------------" << endl;
    cout << "Hello "<< person.getName() << endl;
    cout << "Do you wish to 1: View Current Details 2: Add Money 3: Remove Money";
    cout << " 4: Transfer Money Between Accounts 5: View Transcation History 6: Add Manual Entry 7: Quit" << endl;
}
void App::moneyMethod(string type) {
    double amo = askingDouble("How Much: ");
    int acc;
    if (person.getAccounts().size() == 1) {
        acc = 0;
    }
    else {
        acc = askingInt(0, person.getAccounts().size() - 1, "To Which Account: ");
    }
    if (type == "add") {
        person.add(amo, acc);
        autoNewEntry(amo, acc, 'A', "Added from Menu", -1);
    }
    else {
        if (person.getAmount(acc) - amo >= 0) {
            person.remove(amo, acc);
            autoNewEntry(amo, acc, 'R', "Removed from Menu", -1);
        }
        else {
            cout << "Invaild Funds" << endl;
        }
    }
}
void App::moneyTranfer() {
    if (person.getAccounts().size() == 1) {
        cout << "You only have one account" << endl;
    }
    while (person.getAccounts().size() != 1) {
        bool flag = false;
        string flagReason = "/";
        double amo = askingDouble("How Much: ");
        int accFrom;
        accFrom = askingInt(0, person.getAccounts().size() - 1, "From Which Account: ");

        int accTo;
        if (person.getAccounts().size() == 2) {
            accTo = (accFrom % 2 == 0) ? 1 : 0;
        }
        else {
            accTo = askingInt(0, person.getAccounts().size() - 1, "To Which Account: ");

        }
        string com = askString("Reason: ");
        if (person.getAccounts().at(accFrom) <= amo) {
            flag = true;
            flagReason.append("Invaild Funds Transfered/");

        }
        if (accTo == accFrom) {
            flag = true;
            flagReason.append("Same Account Detected/");
        }
        if (flag) {
            cout << "Error with Transfer. Check below." << endl;
            cout << flagReason << endl;
            if (askingInt(0, 1, "Would you like to Retry? 1 == Yes, 0 ==No\n") == 0) {
                break;
            }
        }
        else {
            autoNewEntry(amo, accTo, 'T', com, accFrom);
            cout << "Transfer Done";
            person.transfer(accTo, accFrom, amo);
            break;
        }
    }
}
void App::inMenuMethods(bool &quit) {
    int in = askingInt(1, 7);
    switch (in) {
        case 1:
            printDefault();
            break;
        case 2:
            moneyMethod("add");
            break;
        case 3:
            moneyMethod("remove");
            break;
        case 4:
            moneyTranfer();
            break;
    }
    Sleep(2000);
}

void App::askNewEntry() {
    Action a;
    time_t now = time(NULL); struct tm nowLocal; localtime_s(&nowLocal, &now);
    a.setDate(getDate()); a.setDate(getMonth()); a.setDate(getYear()); a.setDate(getYearDay());
    while (1) {
        clearScreen();
        a.setAmount(askingDouble()); a.setAccountTo(askingInt(-1, person.getAccounts().size()));        
        a.setAccountFrom(askingInt(-1, person.getAccounts().size()));        
        a.setReason(askString("Reason: "));
        a.print();
        cout << "Is This Right? 1 == Yes, 0 == No" << endl;
        if (askingInt(0, 1) == 1) {
            person.addToTranscationList(a);
            a.~Action();
            break;
        }
    }
    

}
void App::autoNewEntry(double amo, int accTo, char act, string reason, int accFrom = -1) {
    Action a;
    a.setDate(getDate()); a.setDate(getMonth()); a.setDate(getYear()); a.setDate(getYearDay());
    a.setAmount(amo); a.setAccountTo(accTo); a.setAccountFrom(-1); a.setAction(act); a.setReason(reason);
    person.addToTranscationList(a);
    a.~Action();
}
void App::manualEntry() {
    Action a;
    while (1) {
        clearScreen();
        a.setDate(askingInt(1, 31, "Day: "));
        a.setDate(askingInt(1, 12, "Month: "));
        a.setDate(askingInt(2000, getYear(), "Year: "));
        a.setDate(askingInt(1, 365, "Year Day: "));
        a.setAmount(askingDouble("Amount: "));
        a.setAccountTo(askingInt(-1, person.getAccounts().size()-1, "Account To: "));
        a.setAccountFrom(askingInt(-1, person.getAccounts().size()-1, "Account From: "));
        a.setReason(askString("Reason: "));
        a.print();
        cout << "Is This Right? 1 == Yes, 0 == No" << endl;
        if (askingInt(0, 1) == 1) {
            person.addToTranscationList(a);
            a.~Action();
            break;
        }
    }
}
User App::getPerson() {
    return person;
}