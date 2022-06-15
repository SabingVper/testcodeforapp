#pragma once
#ifndef app_h_
#include "user.h"

class App {
public:
	void storePerson();
	void storeTranscation();
	void printDefault();
	void printAllTranscations();
private:
	User person;
};

#endif // !app_h_
