/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        434.cpp
*  Create Date: 2014-07-06 11:14:26
*  Descripton:  greedy
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;

int l[N], r[N];
bool used[N];
int t, n, mmin, mmax;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int v = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &l[i]);
			v = max(v, l[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &r[i]);
			v = max(v, l[i]);
		}

		// deal
		mmin = mmax = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (r[j] <= l[i]) {
					mmax += r[j];
				} else {
					mmax += l[i];
				}
			}
		}
		for (int i = 1; i <= 8; i++) {
			int t1 = 0, t2 = 0;
			for (int j = 0; j < n; j++) {
				if (r[j] == i) {
					t1++;
				}
				if (l[j] == i) {
					t2++;
				}
			}
			mmin += max(t1, t2) * i;
		}

		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mmin, mmax - mmin);
	}
	return 0;
}

