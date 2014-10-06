/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1211.cpp
*  Create Date: 2014-10-02 14:35:21
*  Descripton:  
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 101;
const int MAX_TIME = 5*60*60;

int sn[N], n;
int start = 0;
char ch;

int main() {
	// ios_base::sync_with_stdio(0);
	int zero = 0;
	while (zero != 3) {
		n = 0;
		int mmin = 0x7fffffff;
		while (scanf("%d", &sn[n]) && sn[n]) {
			mmin = min(mmin, sn[n]);
			n++;
			zero = 0;
		}
		if (n == 0) {
			zero++;
			continue;
		}
		if (!sn[0] && !sn[1])
			break;
		int t;
		bool ok;
		for (t =  mmin - 5 + 1; t <= MAX_TIME; t++) {
			ok = true;
			repf (i, 0, n - 1) {
				if (t % (sn[i] * 2) + 1 > sn[i] - 5) {
					ok = false;
					break;
				}
			} if (ok)
				break;
		}
		if (ok) {
			// cout << t << endl;
			int m = t/60;
			printf("%02d:%02d:%02d\n", m / 60, m % 60, t % 60);
		} else
			puts("Signals fail to synchronise in 5 hours");
	}
	return 0;
}

