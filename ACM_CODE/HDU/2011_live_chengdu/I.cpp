/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        I.cpp
*  Create Date: 2014-11-09 11:13:54
*  Descripton:   
*/

#define HDU
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
#include <bitset>
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
#define x first
#define y second
#define MK(x,y) make_pair(x,y)
typedef pair<int, int> PII;

const int N = 55;

char g[N][N], o[N];
vector<pair<int, int> > p;
map<string, int> mp;
int t, n, m;

bool cmp1(PII a, PII b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp2(PII a, PII b) {
	return a.y < b.y || (a.y == b.y && -a.x < -b.x);
}

bool cmp3(PII a, PII b) {
	return -a.x < -b.x || (-a.x == -b.x && -a.y < -b.y);
}

bool cmp4(PII a, PII b) {
	return -a.y < -b.y || (-a.y == -b.y && a.x < b.x);
}

int main() {
	scanf("%d", &t);
	repf (cas, 1, t) {
		p.clear();
		mp.clear();
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%s", g[i] + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%s", o + 1);
			for (int j = 1; j <= n; j++)
				if (o[j] == '*')
					p.push_back(MK(i, j));
		}

		string s[5];
		int sz = p.size();
		sort(p.begin(), p.end(), cmp1);
		for (int i = 0; i < sz; i++)
			s[1] += g[p[i].x][p[i].y];
		sort(p.begin(), p.end(), cmp2);
		for (int i = 0; i < sz; i++)
			s[2] += g[p[i].y][n + 1 - p[i].x];
		sort(p.begin(), p.end(), cmp3);
		for (int i = 0; i < sz; i++)
			s[3] += g[n + 1 - p[i].x][n + 1 - p[i].y];
		sort(p.begin(), p.end(), cmp4);
		for (int i = 0; i < sz; i++)
			s[4] += g[n + 1 - p[i].y][p[i].x];

		string ss[4];
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 4; j++) {
				ss[i] += s[(i + j - 1) % 4 + 1];
			}
		}

		scanf("%d", &m);
		string tmp;
		repf (i, 0, m - 1) {
			cin >> tmp;
			mp[tmp] = 1;
		}

		sort(ss, ss + 4);
		int ok = -1;
		repf (i, 0, 3) {
			string tmp;
			int sz = ss[i].length();
			bool flag = true;
			repf (j, 0, sz - 1) {
				if (ss[i][j] == '.') {
					if (tmp == "") continue;
					// cout << tmp << endl;
					if (mp.find(tmp) == mp.end()) {
						flag = false;
						break;
					}
					tmp = "";
				} else {
					tmp += ss[i][j];
				}
			}
			if (tmp != "") {
				// cout << tmp << endl;
				if (mp.find(tmp) == mp.end())
					flag = false;
			}
			if (flag) {
				ok = i;
				break;
			}
		}
		printf("Case #%d: ", cas);
		if (ok == -1) {
			puts("FAIL TO DECRYPT");
		} else {
			bool space = false;
			string tmp;
			int sz = ss[ok].length();
			bool flag = true;
			repf (j, 0, sz - 1) {
				if (ss[ok][j] == '.') {
					if (tmp == "") continue;
					// cout << tmp << endl;
					if (flag) { flag = 0; cout << tmp; }
					else cout << ' ' << tmp;
					tmp = "";
				} else {
					tmp += ss[ok][j];
				}
			}
			if (tmp != "" && flag) { flag = 0; cout << tmp; }
			else cout << ' ' << tmp;
			cout << endl;
		}
	}
	return 0;
}

