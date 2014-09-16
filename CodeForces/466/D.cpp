/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-09-16 19:31:45
*  Descripton:  cf 266 d
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define add(a, b) (a)=((a)+(b))%MOD
typedef long long ll;

const int N = 2010;
const ll MOD = 1000000007;

ll dp[N][N];
int a[N], n, h;

int main() {
	ios_base::sync_with_stdio(0);
	while (cin >> n >> h) {
		repf (i, 1, n)
			cin >> a[i];
		// init
		memset(dp, 0, sizeof(dp));
		dp[1][0] = (a[1] == h || a[1] + 1 == h);
		dp[1][1] = (a[1] + 1 == h);

		repf (i, 2, n + 1) {
			repf (open, max(0, h - a[i] - 1), min(i, h - a[i])) {
				if (a[i] + open == h) {
					add(dp[i][open], dp[i - 1][open]);	// -
					if (open > 0)
						add(dp[i][open], dp[i - 1][open - 1]);	// [
				}
				if (a[i] + open + 1 == h) {
					add(dp[i][open], dp[i - 1][open]);	// []
					add(dp[i][open], dp[i - 1][open + 1] * (open + 1));	// ]
					add(dp[i][open], dp[i - 1][open] * open);	// ][
				}
			}
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}

