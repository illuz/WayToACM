/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-10-12 11:03:25
*  Descripton:   
*/

// #define HDU
// don't forget to change lld to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 55;

int t, n, m;
double dp[N][N][N*N];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		dp[1][1][1] = 1;
		repf (k, 1, n * m - 1) {
			repf (i, 1, n)
				repf (j, 1, m) {
					if (dp[i][j][k] > 0) {
						// 1
						dp[i + 1][j + 1][k + 1] += dp[i][j][k] * (n - i) * 1.0 / (n * m - k) * (m - j) ;
						// 2 add row
						dp[i + 1][j][k + 1] += dp[i][j][k] * (n - i) * j * 1.0 / (n * m - k);
						// 3 add col
						dp[i][j + 1][k + 1] += dp[i][j][k] * (m-j) * i * 1.0 / (n*m-k);
						// 4 not add
						if (i == n && j == m)
							continue;
						dp[i][j][k + 1] += dp[i][j][k] * (i*j-k) * 1.0 / (n*m-k);
					}
				}
		}
		double ans = 0;
		repf (i, 0, n * m)
			ans += dp[n][m][i] * i;
		printf("%.8f\n", ans);
	}
	return 0;
}

