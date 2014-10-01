/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        12304.cpp
*  Create Date: 2014-09-29 10:12:47
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

const double eps = 1e-10;
const double PI = acos(-1.0);
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
	bool operator <(const Point &B) const { return x < B.x || (x == B.x && y < B.y) };

	void read() { scanf("%lf", &x); scanf("%lf", &y); }
	void output() { printf("debug: x = %f, y = %f\n", x, y); }
};

typedef Point Vector;

double length(const Vector& A) { return sqrt(A*A); }
double angle(const Vector& A, const Vector& B) { return acos(A*B / length(A) / length(B)); }
Vector rotate(Vector& A, double ang) {return Vector(A.x * cos(ang) - A.y * sin(ang), A.x * sin(ang) + A.y * cos(ang)); }
Vector normal(Vector A) { double l = length(A); return Point(-A.y/l, A.x/l); }
Point getLineIntersection(const Point &P, const Vector &v, const Point &Q, const Vector &w) {
	Vector u = P - Q;
	double t = (w ^ u) / (v ^ w);
	return P + v * t;
}

struct Line {
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}

	Point point(double t) { return s + (e-s) * t; }

	Line move(double d) {return Line(s + normal(e-s)*d, e + normal(e-s)*d);}

	//两直线相交求交点
	//第一个值为0表示直线重合,为1表示平行,为0表示相交,为2是相交
	//只有第一个值为2时,交点才有意义
	pair<int,Point> operator &(const Line &b)const {
		Point res = s;
		if(dcmp((s-e)^(b.s-b.e)) == 0) {
			if(dcmp((s-b.e)^(b.s-b.e)) == 0)
				return make_pair(0,res);//重合
			else return make_pair(1,res);//平行
		}
		double t = ((s-b.s)^(b.s-b.e)) / ((s-e)^(b.s-b.e));
		res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return make_pair(2,res);
	}
};

//点到直线距离
//返回为result,是点到直线最近的点
Point PointToLine(Point P,Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s)) / ((L.e-L.s)*(L.e-L.s));
	result.x = L.s.x + (L.e.x-L.s.x)*t;
	result.y = L.s.y + (L.e.y-L.s.y)*t;
	return result;
}

int main() {
	// ios_base::sync_with_stdio(0);

	return 0;
}

