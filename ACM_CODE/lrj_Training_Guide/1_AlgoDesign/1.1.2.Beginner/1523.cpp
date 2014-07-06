/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1523.cpp
*  Create Date: 2014-07-05 15:01:58
*  Descripton:  brute force 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
const int t[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int v[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int a[N];

int main() {
	while (1) {
		bool ok = false;
		for (int i = 0; i < 8; i++) {
			scanf("%d", &a[i]);
			ok |= a[i];
		}
		if (!ok) {
			break;
		}
		sort(a, a + 8);
		int mmin = 0x7f7f7f7f;
		do {
			int t1 = 0, t2 = 0;
			for (int i = 0; i < 8; i++) {
				t1 += t[i] * a[i];
				t2 += v[i] * a[i];
			}
			mmin = min(mmin, t1 * t1 + t2 * t2);
		} while (next_permutation(a, a + 8));
		printf("%.3f\n", sqrt(mmin));
	}
	return 0;
}

