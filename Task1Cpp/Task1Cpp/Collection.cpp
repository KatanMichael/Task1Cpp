#include "Collection.h"
/*
#include "point.h"
#include "Circle.h"
#include <iostream>

using namespace std;
*/
Collection::Collection(int radius, int width, int height, int color) {
	if (radius > 0) radius; // send to somewere
	else {
		do {
			cout << "radius cant be smaller then 0 insert another radius ";
			cin >> radius;
		} while (radius <= 0);
		radius; // send to somehwere
	}

	while (width <= 0) {
		cout << "Insert to width number that greater then 0" << endl;
		cin >> width;
	}
	while (height <= 0) {
		cout << "Insert to height number that greater then 0" << endl;
		cin >> height;
	}

	int index = 0;
	count = width * height;
	circles = new Circle*[count];
	if (circles == nullptr) {
		cout << "There is no memory " << endl;
		return;
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			circles[index++] = new Circle((radius * 2)*j, (radius * 2)*i, radius, color);
			if (circles[index - 1] == nullptr) {
				cout << "There is no memory " << endl;
				return;
			}
		}
	}
}

Collection::~Collection() {
	cout << "Delete circles" << endl;
	for (int i = 0; i < count; i++)
		delete circles[i];
	delete[] circles;
}

Circle & Collection::getCircleAt(const Point & p) {
	for (int i = 0; i < count; i++)
		if (circles[i]->contains(p))
			return *(circles[i]);
}

void Collection::print() const {
	for (int i = 0; i < count; i++)
		circles[i]->print();
}