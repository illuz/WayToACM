/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        140.cpp
*  Create Date: 2014-07-07 12:04:58
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int N = 51;

int t, n, rd, cas, mmax, ans;
vector<int> rec[N], res;
set<int> s;

void dfs(int cnt, int v) {
	if (v == t) {
		if (!s.count(cnt)) {
			s.insert(cnt);
			res.push_back(cnt);
		}
		return;
	}

	for (int i = 0; i < rec[v].size(); i++) {
		dfs(cnt + rec[v][i], v + 1);
	}
}

int main() {
	bool blank = false;
	while (~scanf("%d", &t) && t) {
		ans = 0;

		if (blank) {
			puts("");
		}
		blank = true;

		// read
		for (int i = 0; i < t; i++) {
			// init the rec[i]
			rec[i].clear();
			// the 0 is the basic max pos
			rec[i].push_back(0);

			scanf("%d", &n);
			int sum = 0;
		  	mmax = 0;

			for (int j = 1; j <= n; j++) {	// read the n and find max and count
				scanf("%d", &rd);
				rd = 10 - rd;
				sum += rd;
				if (sum == mmax) {
					rec[i].push_back(j);
				} else if (sum > mmax) {
					rec[i].clear();
					rec[i].push_back(j);
					mmax = sum;
				}
			}

			ans += mmax;
		}

		printf("Workyards %d\n", ++cas);
		printf("Maximum profit is %d.\n", ans);
		printf("Number of pruls to buy:");
		s.clear();
		res.clear();
		dfs(0, 0);

		sort(res.begin(), res.end());
		int num = res.size() > 10 ? 10 : res.size();
		for (int i = 0; i < num; i++) {
			printf(" %d", res[i]);
		}

		puts("");

	}
	return 0;
}

