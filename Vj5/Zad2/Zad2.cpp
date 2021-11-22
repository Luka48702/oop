#include <iostream>
#include <time.h> 
using namespace std;


class Point
{
	double x;
	double y;
	double z;

public:
	Point(double = 0, double = 0, double = 0);
	void setPoint(const double x, const double y, const double z);
};

class Weapon
{
	Point p;
	int number_of_bullet;
	int n;

public:
	Weapon(int = 0, int = 0);
	void setBullets(const int number_of_bullets, int n);
	void shoot(int x);
	void refill() { this->n = number_of_bullet; };
};



Point::Point(double x, double y, double z)
{
	cout << "Unesi kordinate x,y,z" << endl;
	cin >> x;
	cin >> y;
	cin >> z;
	setPoint(x, y, z);
}
void Point::setPoint(const double x, const double y, const double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Weapon::Weapon(int x, int y)
{
	setBullets(x, y);
}
void Weapon::setBullets(const int x, int y)
{
	this->number_of_bullet = x;
	this->n = y;
}
void Weapon::shoot(int x)
{
	if (this->n < x)
	{
		refill();
	}
	this->n -= x;
	if (this->n == 0)
		refill();
}

int main()
{
	Weapon w(30, 15);
	int x;
	cout << "Koliko zelis metaka ispucati, ako zelis stati Ctrl+Z" << endl;
	while (cin >> x)
	{
		w.shoot(x);
	}
}