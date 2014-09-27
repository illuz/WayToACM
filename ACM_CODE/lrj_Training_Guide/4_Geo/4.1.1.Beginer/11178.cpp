/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11178.cpp
*  Create Date: 2014-09-18 23:03:32
*  Descripton:  Geo
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 0;
const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x) {
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) { x = _x; y = _y; }
	Point operator +(const Point &b) const { return Point(x + b.x, y + b.y); }
	Point operator -(const Point &b) const { return Point(x - b.x, y - b.y); }
	Point operator *(const double &b) const { return Point(x * b, y * b); }
	//叉积
	double operator ^(const Point &b) const { return x*b.y - y*b.x; }
	//点积
	double operator *(const Point &b) const { return x*b.x + y*b.y; }
	void read() { scanf("%lf", &x); scanf("%lf", &y); }
	void print() { printf("debug: x = %f, y = %f\n", x, y); }
};

typedef Point Vector;

double length(const Vector& A) { return sqrt(A*A); }
double angle(const Vector& A, const Vector& B) { return acos(A*B / length(A) / length(B)); }

Point getLineIntersection(const Point &P, const Vector &v, const Point &Q, const Vector &w) {
	Vector u = P - Q;
	double t = (w ^ u) / (v ^ w);
	return P + v * t;
}

Vector rotate(Vector& A, double ang) {
	return Vector(A.x * cos(ang) - A.y * sin(ang), A.x * sin(ang) + A.y * cos(ang));
}

Point getD(Point A, Point B, Point C) {
	Vector v1 = C - B, v2 = B - C;
	double a1 = angle(A - B, v1);
	v1 = rotate(v1, a1 / 3);
	double a2 = angle(A - C, v2);
	v2 = rotate(v2, -a2 / 3);
	return getLineIntersection(B, v1, C, v2);
}

int main() {
	int t;
	Point A, B, C, D, E, F;
	scanf("%d", &t);
	while (t--) {
		A.read();
		B.read();
		C.read();
		D = getD(A, B, C);
		E = getD(B, C, A);
		F = getD(C, A, B);
		printf("%6f %6f %6f %6f %6f %6f\n", D.x, D.y, E.x, E.y, F.x, F.y);
	}
	return 0;
}

