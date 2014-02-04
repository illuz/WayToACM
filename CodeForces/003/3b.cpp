/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3b.cpp
*  Create Date: 2014-01-12 20:09:54
*  Descripton:   
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

/****** TEMPLATE ENDS ******/

const int N = 100100;

vector<PII> k, c;
int sk[N], sc[N];
int n, v, t, p;

bool cmp(PII a, PII b) {
	return a.first > b.first;
}

int main() {
	scanf("%d%d", &n, &v);
	rep(i, n) {
		scanf("%d%d", &t, &p);
		if (t == 1)
			k.push_back(make_pair(p, i + 1));
		else
			c.push_back(make_pair(p, i + 1));
	}

	int kn = k.size(), cn = c.size();
	sort (k.begin(), k.end(), cmp);
	rep(i, kn) sk[i + 1] = sk[i] + k[i].first;
	sort (c.begin(), c.end(), cmp);
	rep(i, cn) sc[i + 1] = sc[i] + c[i].first;

	int rx = 0, ry = 0, ans = 0;

	rep(i, cn + 1) {
		int j = min(v - 2 * i, kn);
		if (j < 0) break;
		if (ans < sk[j] + sc[i]) {
			ans = sk[j] + sc[i];
			rx = j;
			ry = i;
		}
	}

	printf("%d\n", ans);
	rep(i, rx) printf("%d ", k[i].second);
	rep(i, ry) printf("%d ", c[i].second);
	puts("");

	return 0;
}
