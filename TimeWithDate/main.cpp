#include <iostream>

class Time {
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
    static constexpr int second_per_minute = 60;
    static constexpr int minute_per_hour = 60;
    static constexpr int hour_per_day = 24;
protected:
    int h, m, s;
public:
    Time(int hour, int minute, int second) : h(hour), m(minute), s(second) {}
    ~Time() = default;
    void set(int hour, int minute, int second) {
        h = hour;
        m = minute;
        s = second;
    }
    int increase(int seconds) {
        s += seconds;
        m += s/second_per_minute;
        h += m/minute_per_hour;
        int d = h/hour_per_day;
        s %= second_per_minute;
        m %= minute_per_hour;
        h %= hour_per_day;
        return d;
    }
    int operator-(const Time &t) const {
        return ((h-t.h)*minute_per_hour+(m-t.m))*second_per_minute+(s-t.s);
    }
    bool operator<(const Time &t) const {
        return (h<t.h)?true:((m<t.m)?true:((s<t.s)?true:false));
    }
};

std::ostream &operator<<(std::ostream &os, const Time &t) {
    os << t.h << ":" << t.m << ":" << t.s;
    return os;
}

class Date {
    friend std::ostream &operator<<(std::ostream &os, const Date &d);
    static constexpr int day_per_month = 30;
    static constexpr int month_per_year = 12;
protected:
    int y, m, d;
public:
    Date(int year, int month, int day) : y(year), m(month), d(day) {}
    ~Date() = default;
    void set(int year, int month, int day) {
        y = year;
        m = month;
        d = day;
    }
    Date &increase(int day) {
        d += day;
        m += d/day_per_month;
        y += m/month_per_year;
        d %= day_per_month;
        m %= month_per_year;
        return *this;
    }
    int operator-(const Date &date) const {
        return ((y-date.y)*month_per_year + (m-date.m))*day_per_month + (d-date.d);
    }
    bool operator<(const Date &date) const {
        return (y<date.y)?true:((m<date.m)?true:((d<date.d)?true:false));
    }
};

std::ostream &operator<<(std::ostream &os, const Date &d) {
    os << d.y << "-" << d.m << "-" << d.d;
    return os;
}

class TimeWithDate {
    friend std::ostream &operator<<(std::ostream &os, const TimeWithDate &p);
    static constexpr int second_per_day = 24*60*60;
private:
    Time t;
    Date d;
public:
    TimeWithDate(int y, int mo, int d_, int h, int mi, int s) : t(h,mi,s), d(y,mo,d_) {}
    ~TimeWithDate() = default;
    TimeWithDate &increase(int seconds) {
        int days = t.increase(seconds);
        d.increase(days);
        return *this;
    }
    int operator-(const TimeWithDate &p) const {
        return (d-p.d) * second_per_day + (t-p.t);
    }
    bool operator<(const TimeWithDate &p) const {
        return (d<p.d)?true:(t<p.t);
    }
};

std::ostream &operator<<(std::ostream &os, const TimeWithDate &p) {
    os << p.d << " " << p.t;
    return os;
}


using namespace std;
int main() {
    TimeWithDate a(2018,11,7,11,33,10), b(2018,4,1,23,48,45);
    cout << a << endl << b << endl;
    cout << a-b << endl;
    cout << (a<b) << endl;
    cout << b.increase(4*24*60*60+25*60) << endl;
    return 0;
}

// output
// 2018-11-7 11:33:10
// 2018-4-1 23:48:45
// 18618265
// 1
// 2018-4-6 0:13:45
