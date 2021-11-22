#include <iostream>
#include <stdbool.h>

using namespace std;

class Point
{
	double x;
	double y;

public:
	Point(double = 0, double = 0);
	void setPoint(const double x, const double y);
	friend class Meta;
};
class Meta
{
public:
	int condition(Point& t1, Point& t2, Point& p);

};

Point::Point(double x, double y)
{
	cout << "Unesi kordinate x,y" << endl;
	cin >> x;
	cin >> y;
	setPoint(x, y);
}
void Point::setPoint(const double x, const double y)
{
	this->x = x;
	this->y = y;
}

int Meta::condition(Point& t1, Point& t2, Point& p)
{
	if (p.x >= t1.x and p.x <= t2.x and p.y >= t1.y and p.y <= t2.y)
		return true;
	if (p.x >= t2.x and p.x <= t1.x and p.y >= t2.y and p.y <= t1.y)
		return true;

	return false;
}

int main()
{
	Point p1;
	Point p2;
	Point p;
	Meta m;
	int x = m.condition(p1, p2, p);
	if (x == 1)
		cout << "Pogodjena" << endl;
	else
		cout << "Promasena" << endl;
}