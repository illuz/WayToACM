/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3480.cpp
*  Create Date: 2014-09-19 22:17:25
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 10010;
const int M = 5010;

struct Point {
	ll x;
	ll y;
} pt[N];
ll f[N][M];
int q[N], head, tail;

int n, m, t, cas;
ll a[N];

inline bool checkOut(int a, int b, int c) {
	Point p0 = pt[a], p1 = pt[b], p2 = pt[c];
	return (p0.x - p1.x) * (p0.y - p2.y) <= (p0.y - p1.y) * (p0.x - p2.x);
}

inline bool notBest(int a, int b, int k) {
	Point p0 = pt[a], p1 = pt[b];
	return p0.y - p0.x * k > p1.y - p1.x * k;
}

int solve() {
	repf (i, 1, n)
		f[i][1] = (a[i] - a[1]) * (a[i] - a[1]);
	repf (j, 2, m) {
		head = tail = 0;
		repf (i, j, n) {
			pt[i].x = a[i];
			pt[i].y = f[i - 1][j - 1] + a[i] * a[i];
			while (head <= tail - 1 && checkOut(q[tail - 1], q[tail], i))
				tail--;
			q[++tail] = i;
			while (head <= tail - 1 && notBest(q[head], q[head + 1], 2 * a[i]))
				head++;
			int k = q[head];
			f[i][j] = pt[k].y - 2 * pt[k].x * a[i] + a[i] * a[i];
		}
	}
	return f[n][m];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		repf (i, 1, n)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		cout << "Case " << ++cas << ": " << solve() << endl;
	}
	return 0;
}

