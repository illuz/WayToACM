/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Cooking.cpp
*  Create Date: 2015-01-09 08:59:03
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 999999999 + 10;

int cas, t;
char dig[N];

int main() {
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++) {
		scanf("%s", dig);
		int len = strlen(dig);
		char minc = '9' + 1, maxc = '0' - 1;
		int minp = -1, maxp = -1, zerop = -1;
		bool findmin = false, findmax = false;
		for (int i = 0; i < len; i++) {
			if (i && dig[i - 1] < dig[i])
				findmax = true;
			if (i && dig[i - 1] > dig[i])
				findmin = true;

			if (dig[i] != '0') {
				if (minc >= dig[i]) {
					minc = dig[i];
					minp = i;
				}
				if (findmax && maxc <= dig[i]) {
					maxc = dig[i];
					maxp = i;
				}
			} else
				zerop = i;
		}
		printf("Case #%d: ", cas);
		// min
		if (findmin) {
			// swap dig[0] with minc if dig[0] > minc
			if (dig[0] > minc) {
				swap(dig[0], dig[minp]);
				printf("%s ",dig);
				swap(dig[0], dig[minp]);
			} else {
				findmin = false;
				minc = '9'+1;
				for (int i = 1; i < len; i++) {
					if (i > 1 && dig[i - 1] > dig[i])
						findmin = true;
					if (findmin && minc >= dig[i]) {
						minc = dig[i];
						minp = i;
					}
				}
				if (findmin) {
					for (int i = 1; i < len; i++) {
						if (dig[i] > minc) {
							swap(dig[i], dig[minp]);
							printf("%s ",dig);
							swap(dig[i], dig[minp]);
							break;
						}
					}
				} else {
					printf("%s ",dig);
				}
			}
		} else {
			printf("%s ",dig);
		}

		// max
		if (findmax) {
			for (int i = 0; i < len; i++) {
				if (dig[i] < maxc) {
					swap(dig[i], dig[maxp]);
					break;
				}
			}
		}
		printf("%s\n",dig);
	}
	return 0;
}

