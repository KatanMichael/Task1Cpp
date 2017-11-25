// Nir Y.

#include "Collection.h" // already in, "Circle.h" "Point.h" <math.h> <iostream>
/*
#include "point.h"
#include "Circle.h"
#include <iostream>

using namespace std;
*/

#define LOG(x) cout << x << endl ;

enum MyEnum {
	Exit = 0, Example, UserInput
};

void Menu();
void ActiveExample();
void UserData();

int main() {
	system("color f0");
	Menu();
	return 0;
}

void Menu() {
	LOG("Welcome to Task 1");
	int options = 0;
	bool quit = false;
	while (!quit) {
		LOG(endl << "Exit by insert 0" << endl <<
			"Example data insert 1" << endl <<
			"Insert your own data to collection enter 2");
		cin >> options;
		system("cls");
		switch (options) {
		case Exit:
			quit = true;
			break;
		case Example:
			ActiveExample();
			break;
		case UserInput:
			UserData();
			break;
		default:
			LOG("Wrong input!");
			break;
		}
	}
}

void UserData() {
	int radius, width, height, color, x, y;
	LOG("Insert integer numbers in this order : radius , width , height and color");
	cin >> radius >> width >> height >> color;
	Collection collection(radius, width, height, color);
	collection.print();
	LOG("Insert point x and y that in one of the circles, then color to change it");
	cin >> x >> y >> color;
	const Point point(x, y);
	collection.getCircleAt(point).setColor(color);
	collection.print();
	LOG("-End-");
}

void ActiveExample() {
	Collection collection(4, 3, 2, 0);
	LOG("-- before setColor(2) --");
	collection.print();
	Point p(5, 1);
	collection.getCircleAt(p).setColor(2);
	LOG("-- after setColor(2) --");
	collection.print();
}