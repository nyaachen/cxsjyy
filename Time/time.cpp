#include <cstdio>
#include "time.h"



	Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	void Time::set(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	void Time::increment() {
		++second;
		if (second > 59) {
			second = 0;
			++minute;
		}
		if (minute > 59) {
			minute = 0;
			++hour;
		}
		if (hour > 23) {
			hour = 0;
		}
	}
	// should be defined as const method
	void Time::display() {
		// view C++ reference for precious format control
		printf("%2d:%2d:%2d", hour, minute, second);
	}
	// why these two is not defined as const methods and using const reference
	bool Time::equal(Time &other_time) {
		return (hour == other_time.hour)?(
			(minute == other_time.minute)?(
				(second == other_time.second)?true:false
			):false
		):false;
	}
	bool Time::less_than(Time &other_time) {
		if (hour <= other_time.hour) {
			if (hour == other_time.hour) {
				if (minute <= other_time.minute) {
					if (minute == other_time.minute) {
						if (second < other_time.second) {
							return true;
						}
						else return false;
					}
					else return true;
				}
				else return false;
			}
			else return true;
		}
		else return false;
	}

int main() {
	return 0;
}