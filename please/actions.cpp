#include <iomanip>
#include <sstream>
#include "actions.h"
#include <fstream>
#include <iostream>

Action::Action() {
	date.push_back(0); date.push_back(0); date.push_back(2000); date.push_back(0);
	amount = 0.0;
	action = 'N';
	accountTo = 0;
	accountFrom = 0;
	reason = "null";
}
Action::Action(std::vector<int> dmy, double amo, char act, int to, int from, std::string com) {
	date = dmy;
	amount = amo;
	action = act;
	accountTo = to;
	accountFrom = from;
	reason = com;
}
Action::~Action() {
	std::cout << "Action " << std::endl;
}
/*
void Action::store(std::vector<int> dmy, double amo, char act, int to, int from, std::string com) {
    for (int i = 0; i < 4; i++) {
        date.push_back(dmy.at(i));
    }
    amount = amo;
    action = act;
    accountTo = to;
    accountFrom = from;
    reason = com;
};
*/
void Action::savetoFile(std::string &path) {
	std::ofstream f; f.open(path, std::ios_base::app); std::string str; std::vector<std::string> contents;
	while (f.good()) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << amount;
		std::string firstLine = std::to_string(date[0]) + " " + std::to_string(date[1]) + " " + std::to_string(date[2]);
		std::string secondLine = stream.str();
		std::string thirdLine = std::to_string(accountTo);
		std::string forthLine = std::to_string(accountFrom);
		std::string lastLine = reason;
		f << firstLine << std::endl;
		f << secondLine << std::endl;
		f << thirdLine << std::endl;
		f << forthLine << std::endl;
		f << lastLine << std::endl;

	}
	f.close();
}

void Action::print() {
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << amount;
	std::string firstLine = "Date: " + std::to_string(date.at(0)) + " " + std::to_string(date.at(1)) + " " + std::to_string(date.at(2));
	std::string secondLine = "Amount: " + stream.str();
	std::string thirdLine = "Account To: " + std::to_string(accountTo);
	std::string forthLine = "Account From: " + std::to_string(accountFrom);
	std::string lastLine = "Reason: " + reason;
	std::cout << firstLine << std::endl << secondLine << std::endl << thirdLine
		<< std::endl << forthLine << std::endl << lastLine << std::endl;
}
std::vector<int> Action::getDate() { return date; }
double Action::getAmount() { return amount; }
char Action::getAction() { return action; }
int Action::getAccountTo() { return accountTo; }
int Action::getAccountFrom() { return accountFrom; }
std::string Action::getReason() { return reason; }
void Action::setDate(int d) { 
	if (date.size() < 5) { date.push_back(d); } 
	else { std::cout << "Not allowed to push anymore" << std::endl; }
}
void Action::setAmount(double amo) { amount = amo; }
void Action::setAction(char act) { action = act; }
void Action::setAccountTo(int to) { accountTo = to; }
void Action::setAccountFrom(int from) { accountFrom = from; }
void Action::setReason(std::string str) { reason = str; }