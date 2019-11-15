#pragma once
#ifndef POINT_H
#include <iostream>
using namespace std;

class Point {
	int x, y;
public:

	Point(int xp, int yp) {
		x = xp;
		y = yp;
	}

	Point() {}

	void Print() {
		cout << "(" << x << "," << ")";
	}


	//Friend declarations
	friend ostream &operator << (ostream &, const Point &);	//insertion operator
	friend istream &operator >> (istream &, Point &);	//extraction operator

	//add operator	
	Point operator + (const Point &obj)
	{
		Point temp;

		temp.x = x + obj.x;
		temp.y = y + obj.y;

		return temp;
	}

	//minus operator
	Point operator - (const Point &obj)
	{
		Point temp;

		temp.x = x - obj.x;
		temp.y = y - obj.y;

		return temp;
	}

	//member-wise comparison
	bool operator == (const Point &obj) const
	{
		return (x == obj.x && y == obj.y);
	}

	//not-equal comparison
	bool operator != (const Point &obj)
	{
		return !(*this == obj);
	}
};

istream &operator >> (istream &strm, Point &obj)
{
	strm >> obj.x;
	strm >> obj.y;

	return strm;
}

ostream &operator << (ostream &strm, const Point &obj)
{
	strm << obj.x << obj.y;

	return strm;
}

#endif // !POINT_H

