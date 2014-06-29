/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1508.cpp
*  Create Date: 2014-06-28 20:55:20
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10010;
int n, t, k, ans;
int m[5], r[N][5], mmax[40];

int dfs(int S, int num) {	// find num different subset in S, return the max sum
	if (num == 0) {
		return 0;
	}

	int tmp = 0;
	for (int S0 = S; S0; S0 = (S0-1)&S) {
		tmp = max(tmp, mmax[S0] + dfs((S0^S), num - 1));
	}
	return tmp;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(m, 0, sizeof(m));

		// input
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &r[i][j]);
				m[j] = max(m[j], r[i][j]);
			}
		}

		if (k >= 5) {	// just the max

			int sum = 0;
			for (int i = 0; i < 5; i++) {
				sum += m[i];
			}
			printf("%d\n", sum);

		} else {

			memset(mmax, 0, sizeof(mmax));

			for (int i = 0; i < n; i++) {		// for every one
				for (int S = 0; S <= 31; S++) {	// every situation, 00000 to 11111
					int tmp = 0;
					for (int k = 0; k < 5; k++) {
						if (S&(1<<k)) {
							tmp += r[i][k];
						}
						mmax[S] = max(mmax[S], tmp);	// update the max of every situation
					}
				}
			}
			printf("%d\n", dfs(31, k));	// find the max sum in 11111

		}
	}
	return 0;
}

