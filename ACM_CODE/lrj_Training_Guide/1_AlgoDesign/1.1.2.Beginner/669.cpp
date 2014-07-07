/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        669.cpp
*  Create Date: 2014-07-06 14:36:04
*  Descripton:  simulate 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <deque>
using namespace std;

const int N = 10100;
int clu[N];
int t, n, k, m, v, num;

int main() {
	scanf("%d", &t);
	while (t--) {
		// init
		num = 0;
		memset(clu, 0, sizeof(clu));
		bool moved = false;

		// read
		scanf("%d%d", &n, &k);
		while (k--) {
			scanf("%d", &m);
			while (m--) {
				scanf("%d", &v);
				clu[v] = ++num;
			}
		}

		// simulate
		for (int i = 1; i <= n; i++) {
			if (clu[i] == 0 || clu[i] == i) {
				continue;
			}
			moved = true;
			deque<int> s;
			int cur = clu[i], t1, t3;

			s.push_back(i);

			while (clu[cur] != 0 && clu[cur] != i) {
				s.push_back(cur);
				cur = clu[cur];
			}

			if (clu[cur] == i) {	// ring
				// find out the 0
				for (int j = n; j >= 0; j--) {
					if (clu[j] == 0) {
						t3 = j;
						break;
					}
				}

				clu[t3] = clu[cur];
				printf("%d %d\n", cur, t3);

				while (!s.empty()) {
					t1 = s.back();
					clu[cur] = clu[t1];
					printf("%d %d\n", t1, cur);
					cur = t1;
					s.pop_back();
				}

				clu[cur] = clu[t3];
				clu[t3] = 0;
				printf("%d %d\n", t3, cur);

			} else {	// link
				while (!s.empty()) {
					t1 = s.back();
					clu[cur] = clu[t1];
					printf("%d %d\n", t1, cur);
					cur = t1;
					s.pop_back();
				}
				clu[cur] = 0;
			}
		}
		if (!moved) {
			puts("No optimization needed");
		}
		if (t) {
			puts("");
		}
	}
	return 0;
}

