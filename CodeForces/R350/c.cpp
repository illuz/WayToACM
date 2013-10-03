/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        c.cpp
*  Create Date: 2013-10-02 01:14:06
*  Descripton:  c 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long LL;

const int MAXN = 100010;
struct P {
	int x, y;
	int step;
} p[MAXN];
int n;

bool cmp(P a, P b) {
	return a.step < b.step;
}

int main() {
	cin >> n;
	LL cnt = 0;
	rep(i, n) {
		scanf("%d%d", &p[i].x, &p[i].y); 
		p[i].step = abs(p[i].x) + abs(p[i].y);
		if (p[i].x) cnt+= 2;
		if (p[i].y) cnt+=2;
		cnt += 2;
	}
	sort (p, p + n, cmp);
	cout << cnt << endl;
	rep(i, n) {
		if (p[i].x > 0)
			printf("1 %d R\n", p[i].x);
		else if (p[i].x < 0)
			printf("1 %d L\n", -p[i].x);
		if (p[i].y > 0)
			printf("1 %d U\n", p[i].y);
		else if (p[i].y < 0)
			printf("1 %d D\n", -p[i].y);
		printf("2\n");
		if (p[i].x > 0)
			printf("1 %d L\n", p[i].x);
		else if (p[i].x < 0)
			printf("1 %d R\n", -p[i].x);
		if (p[i].y > 0)
			printf("1 %d D\n", p[i].y);
		else if (p[i].y < 0)
			printf("1 %d U\n", -p[i].y);
		printf("3\n");
	}
	return 0;
}
