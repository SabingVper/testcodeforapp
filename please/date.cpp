#include "date.h"

time_t now = time(NULL); struct tm nowLocal;

int getYear() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_year + 1900;
}
int getMonth() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_mon;
}
int getDate() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_mday;
}
int getDay() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_wday;
}
std::string getDayText() {
	localtime_s(&nowLocal, &now);
	switch (nowLocal.tm_wday) {
	case 0:
		return "Sunday";
	case 1:
		return "Monday";
	case 2:
		return "Tuesday";
	case 3:
		return "Wednesday";
	case 4:
		return "Thursday";
	case 5:
		return "Friday";
	case 6:
		return "Saturday";
	}
	
}
int getHour() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_hour;
}
int getMinute() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_min;
}
int getSecond() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_sec;
}
int getYearDay() {
	localtime_s(&nowLocal, &now);
	return nowLocal.tm_yday;
}