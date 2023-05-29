#ifndef _Cirlce
#define _Cirlce
#include<iostream>
#endif
using namespace std;

class Circle
{
private:
	double radius;
public:
	Circle();
	Circle(double r);
	void setRadius(double r);
	double getRadius();
	double area();
	void display();
	Circle operator+(const Circle& cir) const;
};
//Definations of Construction;
Circle::Circle()
{
	radius = 1;
}
Circle::Circle(double r)
{
	radius = r; 
}
void Circle::setRadius(double r)
{
	radius = r;
}
double Circle::getRadius()
{
	return radius;
}
double Circle::area()
{
	return 3.1415926 * radius * radius;
}
void Circle::display()
{
	cout << "This a circle \n";
	cout << "Radius = " << radius << endl;
}
Circle Circle::operator+(const Circle& cir) const
{
	double r = this->radius + cir.radius;
	Circle s(r);
	return s;
}
ostream& operator<<(ostream& out, Circle aCircle)
{
	out << "This a circle \n";
	out << "The radius is " << aCircle.getRadius();
	return out;
}