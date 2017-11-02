#include "geometry.h"
#include <iostream>

PointArray::PointArray() {
	points = new Point[0];
}

PointArray::PointArray(const Point pts[], const int size) {
	psize = size;
	points = new Point[size];

	for (int i = 0; i < size; i++) {
		points[i] = pts[i];
	}
}

PointArray::PointArray(const PointArray &o) {
	psize = o.psize;
	points = new Point[o.psize];

	for (int i = 0; i < o.psize; i++) {
		points[i] = o.points[i];
	}
}

PointArray::~PointArray() {
	delete[] points;
}

void PointArray::printArray() const {
	for (int i = 0; i < psize; i++) {
		std::cout << "(" << points[i].getX() << ", " << points[i].getY() << ")" << std::endl;
	}
}

void PointArray::resize(int n) {
	
	Point *newPoints = new Point[n];

	int minSize = (n > psize ? psize : n);

	for (int i = 0; i < minSize; i++) {
		newPoints[i] = points[i];
	}
	delete[] points;
	psize = n;
	points = newPoints;
}

void PointArray::push_back(const Point &p) {
	resize(psize + 1);
	points[psize - 1] = p;
}

void PointArray::insert(const int position, const Point &p) {
	resize(psize + 1);
	for (int i = psize - 1; i > position; i--) {
		points[i] = points[i - 1];
	}
	points[position] = p;
}

void PointArray::remove(const int pos) {
	if (pos >= 0 && pos < psize - 1) {
		for (int i = pos; i < psize - 1; i++) {
			points[i] = points[i + 1];
		}
		resize(psize - 1);
	}
}

const int PointArray::getSize() const {
	return psize;
}

void PointArray::clear() {
	resize(0);
}