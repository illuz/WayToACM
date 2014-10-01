/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        circle.cpp
*  Create Date: 2014-09-29 09:24:19
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const double eps = 1e-8;
const int N = 0;

int dcmp(double x) {
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) { x = _x; y = _y; }
	Point operator +(const Point &B) const { return Point(x + B.x, y + B.y); }
	Point operator -(const Point &B) const { return Point(x - B.x, y - B.y); }
	Point operator *(const double &b) const { return Point(x * b, y * b); }
	Point operator /(const double &b) const { return Point(x / b, y / b); }
	//叉积
	double operator ^(const Point &B) const { return x*B.y - y*B.x; }
	//点积
	double operator *(const Point &B) const { return x*B.x + y*B.y; }
	bool operator ==(const Point &B) const {return x == B.x && y == B.y; }

	void read() { scanf("%lf", &x); scanf("%lf", &y); }
	void output() { printf("debug: x = %f, y = %f\n", x, y); }
};

typedef Point Vector;

struct Circle {
	Point c;
	double r;
	Circle(Point c = Point(0,0), double r = 0) : c(c), r(r) { }
	Point point (double a) {
		return Point(c.x + cos(a)*r, c.y + sin(a)*r);
	}
};



int main() {
	// ios_base::sync_with_stdio(0);
	
	return 0;
}

