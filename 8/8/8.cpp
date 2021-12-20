#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Timer
{
    int h, m;
    double s;
public:
    int getH();
    int getM();
    double getS();
    void setH(int hours);
    void setM(int minutes);
    void setS(double seconds);
    Timer();
    Timer(int hours, int minutes, double seconds);
    Timer operator+=(Timer& t);
    Timer operator-=(const Timer& t);
    Timer operator/=(int n);
    ~Timer();
    friend ostream& operator<<(ostream& out, const Timer& t);
    operator double();
    friend bool operator<(const Timer& a, const Timer& b);  //nije dio
};

class Penalty
{
    int penalty;
public:
    Penalty(int p);
    void operator()(Timer& t);
};

int Timer::getH()
{
    return h;
}
int Timer::getM()
{
    return m;
}
double Timer::getS()
{
    return s;
}
void Timer::setH(int hours)
{
    h = hours;
}
void Timer::setM(int minutes)
{
    m = minutes;
}
void Timer::setS(double seconds)
{
    s = seconds;
}

Timer::Timer() {
    h = 0;
    m = 0;
    s = 0;
}

Timer::Timer(int hours, int minutes, double seconds) {
    h = hours;
    m = minutes;
    s = seconds;
}

Timer Timer::operator-=(const Timer& t) {
    double time = h * 3600 + m * 60 + s;
    double time_end = t.h * 3600 + t.m * 60 + t.s;
    time -= time_end;
    h = time / 3600;
    m = (time / 60) - h * 60;
    s = time - m * 60 - h * 3600;
    return *this;
}

Timer Timer::operator+=(Timer& t) {
    double time = (h * 3600) + (m * 60) + s;
    double time_end = (t.h * 3600) + (t.m * 60) + t.s;
    time += time_end;
    h = time / 3600;
    m = (time / 60) - h * 60;
    s = time - m * 60 - h * 3600;
    return *this;
}


Timer Timer::operator/=(int t) {
    double time = ((h * 3600) + (m * 60) + s) / t;
    h = time / 3600;
    m = (time / 60) - h * 60;
    s = time - m * 60 - h * 3600;
    return *this;
}

ostream& operator<<(ostream& out, const Timer& t) {
    return out << t.h << ":" << t.m << ":" << t.s;
}

bool operator<(const Timer& x, const Timer& y) {
    double time_x = x.h * 3600 + x.m * 60 + x.s;
    double time_y = y.h * 3600 + y.m * 60 + y.s;
    return time_x < time_y;
}

Timer::operator double() {
    return h * 3600 + m * 60 + s;
}


Penalty::Penalty(int time) {
    penalty = time;
}

void Penalty::operator()(Timer& t) { 
    double time = t.getH() * 3600 + t.getM() * 60 + t.getS();
    time += penalty;
    t.setH(time / 3600);
    t.setM((time / 60) - t.getH() * 60);
    t.setS(time - t.getM() * 60 - t.getH() * 3600);
}

Timer::~Timer() {};

int main()
{
    vector<Timer> v{ {2, 6, 9.118}, {2, 6, 15.251}, {2, 6, 9.925}, {2, 7, 15.222}, {2, 7, 10.775} };
    Timer avg;
    for (auto t : v)
        avg += t;
    avg /= v.size();
    cout << "avg " << avg << endl;
    Timer tmax = *min_element(v.begin(), v.end());
    cout << "min " << tmax << endl;
    for (auto& tm : v)
        cout << double(tm - tmax) << endl;
    Penalty p(5);
    for (auto& tm : v)
        p(tm);
    cout << endl;
    for (auto t : v)//poslje
        cout << t << endl;
}

/*
 * avg 2:6:36.0582
 * min 2:6:9.118
 * 0
 * 6.133
 * 0.807
 * 66.104
 * 61.657
 *
 */