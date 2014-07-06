/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10670.cpp
*  Create Date: 2014-07-05 09:37:30
*  Descripton:  Greedy
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;

struct Agency {
	char name[N];
	int fee;
} agc[N];
char rd[N];
int t, m, n, l, a, b, cd;

bool cmp(Agency a, Agency b) {
	if (a.fee != b.fee)
		return a.fee < b.fee;
	return strcmp(a.name, b.name) < 0;
}

int main() {
	scanf("%d", &t);

	for (int cas = 1; cas <= t; cas++) {
		scanf("%d%d%d", &n, &m, &l);
		memset(agc, 0, sizeof(agc));

		for (int i = 0; i < l; i++) {

			// read
			scanf("%s", rd);
			int j = 0;
			while (rd[j] != ':') {
				agc[i].name[j] = rd[j];
				j++;
			}
			rd[j] = 0;
			sscanf(rd + j + 1, "%d,%d", &a, &b);

			// init
			int nn = n;
			agc[i].fee = 0;
			
			// deal
			while (nn > m) {
				if (nn / 2 < m) {
					agc[i].fee += (nn - m) * a;
					break;
				}
				if ((nn - nn / 2) * a < b) {
					agc[i].fee += (nn - nn / 2) * a;
				} else {
					agc[i].fee += b;
				}
				nn >>= 1;
			}
		}

		sort(agc, agc + l, cmp);
		printf("Case %d\n", cas);
		for (int i = 0; i < l; i++) {
			printf("%s %d\n", agc[i].name, agc[i].fee);
		}
	}

	return 0;
}

