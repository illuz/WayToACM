/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1004.cpp
*  Create Date: 2014-07-23 10:46:49
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6 + 10;

struct Task {
	int x;
	int y;
} task[N];

multiset<int> s[101];
int n, m;
int mmax, ans, tim, level;
ll sum;

bool cmp(Task a, Task b) {
	return a.x > b.x || (a.x == b.x && a.y > b.y);
}

void init() {
	for (int i = 0; i <= mmax; i++) {
		s[i].clear();
	}
	mmax = 0;
	sum = 0;
	ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d%d", &tim, &level);
		s[level].insert(tim);
		mmax = max(mmax, level);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &task[i].x, &task[i].y);
	}
	sort(task, task + m, cmp);
}

void solve() {
	for (int i = 0; i < m; i++) {
		tim = task[i].x;
		level = task[i].y;

		for (int j = level; j <= mmax; j++) {
			if (s[j].empty())
				continue;
			multiset<int>::iterator it = s[j].lower_bound(tim);
			if (it == s[j].end() || *it < tim)
				continue;
			ans++;
			sum += (ll)tim * 500 + (ll)level * 2;
			s[j].erase(it);
			break;
		}
	}

	cout << ans << ' ' << sum << endl;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		init();
		solve();
	}
	return 0;
}

