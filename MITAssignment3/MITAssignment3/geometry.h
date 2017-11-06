#pragma once

class Point {
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}
	int getX() const { return x; }
	int getY() const { return y; }

	void setX(const int new_x) { x = new_x; }
	void setY(const int new_y) { y = new_y; }

private:
	int x;
	int y;
};

class PointArray {
public:
	PointArray();
	PointArray(const Point pts[], const int size) {
		psize = size;
		points = new Point[size];

		for (int i = 0; i < size; i++) {
			points[i] = pts[i];
		}
	}
	PointArray(const PointArray &o);
	~PointArray();

	void PointArray::printArray() const;
	void PointArray::push_back(const Point &p);
	void PointArray::insert(const int position, const Point &p);
	void PointArray::remove(const int pos);
	const int PointArray::getSize() const;
	void PointArray::clear();

private:
	int psize;
	Point *points;
	void resize(int n);
};

class Polygon {

protected:
	static int numPoly;
	PointArray polyArray;

public:
	Polygon(const Point pts[], const int length);
	Polygon(const PointArray &pArray);
	~Polygon() { numPoly--; }

	virtual double area() const = 0;
	int getNumPolygons() { return numPoly; }
	int getNumSides() { return polyArray.getSize(); }
	const PointArray *getPoints() const { return &polyArray; }
};