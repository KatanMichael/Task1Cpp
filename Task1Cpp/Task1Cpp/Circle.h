// #pragma once
#ifndef Circle_H
#define Circle_H

#include "point.h"

class Circle {

public:
	Circle(int x, int y, int r, int color);
		int getColor() const;
		void setColor(int color);
		bool contains(const Point &p) const;
		void print() const;
	private:
		const Point center;
		int radius, color;
	};

#endif // !Circle_H
