#include <iostream>
#include "geometry.h"

int main() {

	const int size = 4;

	Point pts[size]{ Point(2,1), Point(3,0), Point(-1,3), Point(4,5) };

	PointArray ptArr = PointArray(pts, size);

	ptArr.printArray();

	ptArr.push_back(Point(2, 2));

	std::cout << std::endl;
	ptArr.printArray();

	ptArr.insert(2, Point(1, 1));

	std::cout << std::endl;
	ptArr.printArray();

	ptArr.remove(3);

	std::cout << std::endl;
	ptArr.printArray();

	system("PAUSE");
	return 0;
}