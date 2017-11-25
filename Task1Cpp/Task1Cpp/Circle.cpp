#include "Circle.h"
#include <math.h>

/*
#include "point.h"
#include <iostream>

using namespace std;
*/

Circle::Circle(int x, int y, int r, int color)
	:center(x, y), color(color) {
	if (r > 0) radius = r;
	else {
		do {
			cout << "radius cant be smaller then 0 insert another radius ";
			cin >> r;
		} while (r <= 0);
		radius = r;
	}
}

int Circle::getColor() const { return color; }

void Circle::setColor(int color) { this->color = color; }

bool Circle::contains(const Point & p) const 
{
	int x, y, r;
	int x1 = center.getX(), y1 = center.getY();
	int x2 = p.getX(),		y2 = p.getY();
	x = x1 - x2;
	y = y1 - y2;
	x = x*x;
	y = y*y;
	r = radius*radius;
	
	if(r <= (x+y))
	{
		return true;	
	}
	return false;
	
//	double distance = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
	// distance = sqrt((x1-x2)^2 + (y1-y2)^2)
//	return (double)radius >= distance ? true : false;
}

void Circle::print() const {
	// center=(0,0) radius=4 color=0
	cout << "Circle center = ";
	this->center.print();
	cout << " radius = " << radius
		<< " color = " << color << endl;
}
