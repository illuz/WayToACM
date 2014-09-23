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
	Point(double _x, double _y) {
		x = _x; y = _y;
	}
	Point operator -(const Point &b) const {
		return Point(x - b.x, y - b.y);
	}

	//叉积
	double operator ^(const Point &b) const {
		return x*b.y - y*b.x;
	}

	//点积
	double operator *(const Point &b) const {
		return x*b.x + y*b.y;
	}
	//绕原点旋转角度B(弧度值),后x,y的变化
	void transXY(double B) {
		double tx = x,ty = y;
		x = tx*cos(B) - ty*sin(B);
		y = tx*sin(B) + ty*cos(B);
	}

	void read() {
		scanf("%lf", &x);
		scanf("%lf", &y);
	}

	void print() {
		printf("debug: x = %f, y = %f\n", x, y);
	}
};

struct Line
{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}

	//两直线相交求交点
	//第一个值为0表示直线重合,为1表示平行,为0表示相交,为2是相交
	//只有第一个值为2时,交点才有意义
	pair<int,Point> operator &(const Line &b)const {
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((s-b.e)^(b.s-b.e)) == 0)
				return make_pair(0,res);//重合
			else return make_pair(1,res);//平行
		}
		double t = ((s-b.s)^(b.s-b.e)) / ((s-e)^(b.s-b.e));
		res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return make_pair(2,res);
	}
};

//*两点间距离
double dist(Point a,Point b) {
	return sqrt((a-b)*(a-b));
}

Point getD(Point A, Point B, Point C) {
	Line l1(B, C);
	Line l2(C, B);
}

int main() {
	int t;
	Point A, B, C, D, E, F;
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

