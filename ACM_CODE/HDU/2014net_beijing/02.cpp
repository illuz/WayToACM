/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        02.cpp
*  Create Date: 2014-10-05 22:16:11
*  Descripton:   
*/

// #define HDU
// don't forget to change lld to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const double PI = acos(-1.0);
const int N = 100100;

struct Node {
	int id;
	double x;
	double h;
	bool operator <(const Node b) const {
		return x < b.x;
	}
} nd[N<<1], S[N];

int t, n, m, q[N], l, r, cnt;
int h, x;
double ans[N];

bool check(Node a, Node b, Node c) {
	return (a.h - b.h) * (c.x - b.x) >= (b.h - c.h) * (b.x - a.x);
}

double getAngle(Node a, Node b) {
	return atan((b.x - a.x) / a.h);
}

void getans() {
	int top = 0;
	repf (i, 0, cnt - 1) {
		if (nd[i].id) {
			while (top >= 2 && check(S[top - 1], S[top], nd[i]))
				top--;
			ans[nd[i].id] += getAngle(S[top], nd[i]);
		} else {
			while (top && S[top].h <= nd[i].h)
				top--;
			while (top >= 2 && check(S[top - 1], S[top], nd[i]))
				top--;
			S[++top] = nd[i];
		}
	}
}

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		cnt = 0;
		scanf("%d", &n);
		repf (i, 1, n) {
			scanf("%lf%lf", &nd[cnt].x, &nd[cnt].h);
			nd[cnt++].id = 0;
		}
		scanf("%d", &m);
		repf (i, 1, m) {
			scanf("%lf", &nd[cnt].x);
			nd[cnt].h = 0;
			nd[cnt++].id = i;
			ans[i] = 0;
		}

		sort(nd, nd + cnt);
		getans();
		reverse(nd, nd + cnt);
		repf (i, 0, cnt - 1)
			nd[i].x = 1e9 - nd[i].x;
		getans();
		
		printf("Case #%d:\n", cas);
		repf (i, 1, m)
			printf("%.9f\n", ans[i] * 180 / PI);
	}
	return 0;
}

