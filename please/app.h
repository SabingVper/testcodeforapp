#pragma once
#ifndef app_h_
#include "user.h"
#include "screenControl.h"

class App {
public:
	App();
	App(User&);
	~App();
	void storePerson();
	void storeTranscation();
	void printDefault();
	void printAllTranscations();
	void waitingInMenu();
	void askNewEntry();
	void manualEntry();
	User getPerson();
private:
	User person;
};

#endif // !app_h_
