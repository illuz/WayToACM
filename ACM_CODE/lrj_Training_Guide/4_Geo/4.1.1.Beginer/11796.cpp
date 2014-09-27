/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11796.cpp
*  Create Date: 2014-09-19 08:53:09
*  Descripton:  Geo
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 60;
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

	Point operator +(const Point &b) const {
		return Point(x + b.x, y + b.y);
	}

	//叉积
	double operator ^(const Point &b) const {
		return x*b.y - y*b.x;
	}

	//点积
	double operator *(const Point &b) const {
		return x*b.x + y*b.y;
	}

	Point operator *(const double &b) const {
		return Point(x * b, y * b);
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

//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg(Point P,Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s)) / ((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1) {
		result.x = L.s.x + (L.e.x - L.s.x)*t;
		result.y = L.s.y + (L.e.y - L.s.y)*t;
	} else {
		if(dist(P,L.s) < dist(P,L.e))
			result = L.s;
		else result = L.e;
	}
	return result;
}

int t, a, b;
Point p[N], q[N];
double mmin, mmax;

inline void update(Point p, Point a, Point b) {
	mmin = min(mmin, dist(NearestPointToLineSeg(p, Line(a, b)), p));
	mmax = max(max(mmax, dist(p, a)), dist(p, b));
}

int main() {
	ios_base::sync_with_stdio(0);
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d", &a, &b);
		repf (i, 0, a - 1)
			p[i].read();
		repf (i, 0, b - 1)
			q[i].read();

		double lenA = 0, lenB = 0;
		repf (i, 0, a - 2)
			lenA += dist(p[i], p[i + 1]);
		repf (i, 0, b - 2)
			lenB += dist(q[i], q[i + 1]);

		int sa = 0, sb = 0;
		Point pa = p[0], pb = q[0];
		mmin = 1e9;
		mmax = -1e9;
		while (sa < a - 1 && sb < b - 1) {
			double al = dist(p[sa + 1], pa);
			double bl = dist(q[sb + 1], pb);
			double T = min(al/lenA, bl/lenB);
			Point va = (p[sa + 1] - pa) * (1 / al) * T * lenA;
			Point vb = (q[sb + 1] - pb) * (1 / bl) * T * lenB;
			update(pa, pb, pb + vb - va);
			pa = pa + va;
			pb = pb + vb;
			if (pa == p[sa + 1])
				sa++;
			if (pb == p[sb + 1])
				sb++;
		}
		printf("Case %d: %.0f\n", cas, mmax - mmin);
	}
	return 0;
}

