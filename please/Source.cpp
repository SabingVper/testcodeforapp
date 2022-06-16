#include <ctime>
#include "app.h"
#include <iostream>

using namespace std;

int main() {

    App main;

    time_t now = time(NULL);

    struct tm nowLocal;

    localtime_s(&nowLocal, &now);

    //cout << "Happy " << nowLocal.tm_year + 1900 << endl;
    
    main.printDefault();

    return 0;
}