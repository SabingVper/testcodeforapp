#pragma once
#ifndef app_h_
#include "user.h"
#include "screenControl.h"
#include <string>

class App {
public:
	App();
	App(User&);
	~App();
	void storePerson();
	void storeTranscation();
	void printDefault();
	void printAllTranscations();
	void inMenuText();
	void inMenuMethods(bool&);
	void moneyMethod(std::string);
	void moneyTranfer();
	void askNewEntry();
	void autoNewEntry(double, int, char, std::string, int);
	void manualEntry();
	User getPerson();
private:
	User person;
};

#endif // !app_h_
