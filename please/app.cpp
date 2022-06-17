#include "app.h"
#include "actions.h"
#include "date.h"
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ctime>
#include <stdlib.h>

using namespace std;

App::App() {
    storePerson();
}
App::App(User &per) {
    User person = per;
}
App::~App() {
    cout << "App for " << person.getName() << " Terminated";
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
void App::waitingInMenu() {

}
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
    if(str != "null") {
        cout << str;
    }
    while (1) {
        if (cin >> num) {
            if (num >= min && num < max) {
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
void App::askNewEntry() {
    Action a;
    time_t now = time(NULL); struct tm nowLocal; localtime_s(&nowLocal, &now);
    a.setDate(getDate()); a.setDate(getMonth()); a.setDate(getYear()); a.setDate(getYearDay());
    while (1) {
        clearScreen();
        a.setAmount(askingDouble());        a.setAccountTo(askingInt(-1, person.getAccounts().size()));        
        a.setAccountFrom(askingInt(-1, person.getAccounts().size()));        
        a.setReason(askString("Reason: "));
        a.print();
        cout << "Is This Right? 1 == Yes, 0 == No" << endl;
        if (askingInt(0, 2) == 0) {
            break;
        }
    }
    

}
void App::manualEntry() {
    Action a;
    while (1) {
        clearScreen();
        a.setDate(askingInt(0, 31, "Day: "));
        a.setDate(askingInt(0, 12, "Month: "));
        a.setDate(askingInt(2000, getYear(), "Year: "));
        a.setDate(askingInt(0, 365, "Year Day: "));
        a.setAmount(askingDouble("Amount: "));
        a.setAccountTo(askingInt(-1, person.getAccounts().size(), "Account To: "));
        a.setAccountFrom(askingInt(-1, person.getAccounts().size(), "Account From: "));
        a.setReason(askString("Reason: "));
        a.print();
        cout << "Is This Right? 1 == Yes, 0 == No" << endl;
        if (askingInt(0, 2) == 0) {
            break;
        }
    }
}
User App::getPerson() {
    return person;
}