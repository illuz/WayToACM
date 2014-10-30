/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        J.cpp
*  Create Date: 2014-10-20 10:21:23
*  Descripton:   
*/

#include <cstdio>
#include <algorithm>
typedef __int64 ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

ll c[4];

int main() {
	while (~scanf("%I64d%I64d%I64d", &c[0], &c[1], &c[2])) {
		sort(c, c + 3);
		if (c[1] == 0) {	//0 0 0+
			if (c[2] <= 1)
				puts("0");
			else
				printf("%I64d\n", 1 + (c[2] - 2) * 2);
		} else if (c[0] == 0) {	// 1 zero
			if (c[1] == 1) {
				if (c[2] == 1)
					puts("1");
				else if (c[2] == 2)
					puts("3");
				else
					printf("%I64d\n", 3 + (c[2] - 2) * 3);
			} else {
				printf("%I64d\n", 6 + (c[1] + c[2] - 4) * 4);
			}
		} else {		// no zero
			if (c[1] == 1) {	// 1 1 1+
				if (c[2] == 1)
					puts("3");
				else if (c[2] == 2)
					puts("6");
				else
					printf("%I64d\n", 6 + (c[2] - 2) * 4);
			} else if (c[0] == 1) {	// 1 2+ 2+
				printf("%I64d\n", 10 + (c[1] + c[2] - 4) * 5);
			} else {	// 2+ 2+ 2+
				printf("%I64d\n", 15 + (c[0] + c[1] + c[2] - 6) * 6);
			}
		}
	}
	return 0;
}

