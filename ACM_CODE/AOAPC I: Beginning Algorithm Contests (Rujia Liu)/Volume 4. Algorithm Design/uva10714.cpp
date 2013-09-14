 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          uva10714.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-29 22:52:12
 *   Descripton:    UVA 10714 Ants, greed, simutation
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int cas;
	int Max, Min, len, n, t, L, S;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d%d", &len, &n);
		Min = 0;
		Max = 0;
		while (n--) {
			scanf("%d", &t);
			if (t > len / 2) L = t, S = len - t;
			else L = len - t, S = t;
			Min = max(L, Min);
			Max = max(S, Max);
		}
		printf("%d %d\n", Max, Min);
	}
	return 0;
}

