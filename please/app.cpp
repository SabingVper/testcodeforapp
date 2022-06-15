#include "app.h"
#include "actions.h"
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

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
    for (int i = 0; i < person.getTranscationList().size(); i++) {
        cout << "-----------------------" << endl;
        person.getTranscationList().at(i).print();
    }
}