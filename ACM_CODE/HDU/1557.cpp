/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1557.cpp
*  Create Date: 2014-06-28 14:47:58
*  Descripton:  brute force/ set 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
int t, n, tot;
int a[N], ans[N], sub[N], scnt;

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(ans, 0, sizeof(ans));
		tot = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			tot += a[i];
		}

		tot /= 2;		// half total tickets
		int ALL = (1 << n);	// subset 1 ~ 2^n-1
		for (int i = 0; i < ALL; i++) {
			scnt = 0;	// this subset's number
			int tmp = i, sum = 0, no = 0;
			while (tmp) {
				if (tmp & 1) {	// if no is in subset
					sub[scnt++] = no;
					sum += a[no];
				}
				tmp >>= 1;
				no++;
			}

			if (sum > tot) {	// if success
				for (int j = 0; j < scnt; j++) {
					if (sum - a[sub[j]] <= tot) {	// find out
						ans[sub[j]]++;
					}
				}
			}
		}

		// output
		printf("%d", ans[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}

