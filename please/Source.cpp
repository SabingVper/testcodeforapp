#include <fstream>
#include <ctime>
#include "user.cpp"
#include "actions.h"
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

string path = "C:\\Users\\Ry-Bread\\Documents\\data.txt";



struct app {
    User activePerson;
    void readAllLines(){
        ifstream f; f.open(path); string str; vector<string> contents;
        while(f.good()){
            while(getline(f,str)){
                contents.push_back(str);
            }
        }
        f.close();

        activePerson.name = contents.at(0);
        int i = 0;
        while(i < stoi(contents.at(1))) {
            activePerson.accounts.push_back(stod(contents.at(2 + i)));
            i++;
        }
        activePerson.lastLine = contents.size();
        activePerson.transcationStart = 2 + i;
    }
    void printLines() {
        int num = activePerson.accounts.size();
        string str = "Name: " + activePerson.name + "\nNumber of accounts: " 
            + to_string(num);
        for (int i = 0; i < num; i++) {
            stringstream stream;
            double value = activePerson.accounts.at(i);
            stream << fixed << setprecision(2) << value;
            string str1 = "\nAccount " + to_string(i+1) + ": " + stream.str();
            str.append(str1);
        }
        cout << str << endl;
    }
};


int main() {

    app main;

    time_t now = time(NULL);

    struct tm nowLocal;

    localtime_s(&nowLocal, &now);

    //cout << "Happy " << nowLocal.tm_year + 1900 << endl;
    
    main.readAllLines();
    main.printLines();

    return 0;
}