/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        LA3263.cpp
*  Create Date: 2014-09-18 23:18:47
*  Descripton:  V+F-E=2
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 310;
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

	bool operator <(const Point &b) const {
		return x < b.x || (x == b.x && y < b.y);
	}

	bool operator ==(const Point &b) const {
		return x == b.x && y == b.y;
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

//*判断点在线段上
bool OnSeg(Point P,Line L) {
	return
		sgn((L.s-P)^(L.e-P)) == 0 &&
		sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
		sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

Point p[N], v[N*N];
Line a, b;
int c, e, n, cas;

int main() {
	ios_base::sync_with_stdio(0);
	cas = 0;
	while (scanf("%d", &n) && n) {
		repf (i, 0, n - 1) {
			p[i].read();
			v[i] = p[i];
		}
		n--;
		c = n;
		repf (i, 0, n - 1) {
			a.s = p[i];
			a.e = p[i + 1];
			repf (j, i + 1, n - 1) {
				b.s = p[j];
				b.e = p[j + 1];
				pair<int,Point> t = a & b;
				if (t.first == 2 && OnSeg(t.second, a) && OnSeg(t.second, b))
					v[c++] = t.second;
			}
		}
		sort(v, v + c);
		c = unique(v, v + c) - v;
		
		e = n;
		repf (j, 0, n - 1) {
			a.s = p[j];
			a.e = p[j + 1];
			repf (i, 0, c - 1) {
				if (p[j] == v[i] || p[j + 1] == v[i])
					continue;
				if (OnSeg(v[i], a))
					e++;
			}
		}
		// cout << e << c << endl;
		printf("Case %d: There are %d pieces.\n", ++cas, e + 2 - c);
	}
	return 0;
}

