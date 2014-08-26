/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        convex_hull.cpp
*  Create Date: 2014-08-06 09:17:20
*  Descripton:   
*  求凸包,Graham算法
*  点的编号0~n-1
*  返回凸包结果Stack[0~top-1]为凸包的编号
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const double eps = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 1010;

int Stack[MAXN], top;

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
} list[MAXN];

//*两点间距离
double dist(Point a,Point b) {
	return sqrt((a-b)*(a-b));
}

//相对于list[0]的极角排序
bool _cmp(Point p1,Point p2) {
	double tmp = (p1-list[0])^(p2-list[0]);
	if(sgn(tmp) > 0)return true;
	else if(sgn(tmp) == 0 && sgn(dist(p1,list[0]) - dist(p2,list[0])) >= 0)
		return true;
	else return false;
}

void Graham(int n) {
	Point p0;
	int k = 0;
	p0 = list[0];
	//找最下边的一个点
	for(int i = 1;i < n;i++) {
		if( (p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x) ) {
			p0 = list[i];
			k = i;
		}
	}
	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);
	if(n == 1) {
		top = 1;
		Stack[0] = 0;
		return;
	}
	if(n == 2) {
		top = 2;
		Stack[0] = 0;
		Stack[1] = 1;
		return;
	}
	Stack[0] = 0;
	Stack[1] = 1;
	top = 2;
	for(int i = 2;i < n;i++) {
		while(top > 1 &&
				sgn((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]])) <= 0)
			top--;
		Stack[top++] = i;
	}
}

int main() {

	return 0;
}

