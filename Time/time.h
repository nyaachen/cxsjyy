#ifndef TIME_H
#define TIME_H


	class Time {
	private:
		int hour;
		int minute;
		int second;
	public:
		Time(int h, int m, int s);
		void set(int h, int m, int s);
		void increment();
		void display();
		bool equal(Time &other_time);
		bool less_than(Time &other_time);
	};

#endif