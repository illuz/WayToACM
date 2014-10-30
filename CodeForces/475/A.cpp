/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-10-06 12:12:31
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

char b[6][50], a[6][50] = {
	"+------------------------+",
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|",
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+" };
int n;

int main() {
	while (cin >> n) {
		memcpy(b, a, sizeof(b));
		if (n > 4) {
			repf (i, 1, 4)
				b[i][1] = '0';
			n -= 4;
			for (int j = 3; n > 0; j += 2) {
				if (n-- > 0) b[1][j] = 'O';
				if (n-- > 0) b[2][j] = 'O';
				if (n-- > 0) b[4][j] = 'O';
			}
		} else {
			repf (i, 1, n)
				b[i][1] = 'O';
		}
		repf (i, 0, 5)
			puts(b[i]);
	}
	return 0;
}

