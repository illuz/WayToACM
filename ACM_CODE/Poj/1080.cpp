/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1080.cpp
*  Create Date: 2014-10-02 10:20:24
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 110;
const int M = 'T' + 1;

int t, n, m, dp[M][M], v[M][M];
char a[N], b[N];

int main() {
	// ios_base::sync_with_stdio(0);
	v['A']['A'] = v['C']['C'] = v['G']['G'] = v['T']['T'] = 5;
	v['A']['C'] = v['C']['A'] = -1;
	v['A']['G'] = v['G']['A'] = -2;
	v['A']['T'] = v['T']['A'] = -1;
	v['A']['-'] = v['-']['A'] = -3;
	v['C']['G'] = v['G']['C'] = -3;
	v['C']['T'] = v['T']['C'] = -2;
	v['C']['-'] = v['-']['C'] = -4;
	v['G']['T'] = v['T']['G'] = -2;
	v['G']['-'] = v['-']['G'] = -2;
	v['T']['-'] = v['-']['T'] = -1;
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d %s", &n, a + 1);
		scanf("%d %s", &m, b + 1);
		// init
		repf (i, 1, n)
			dp[i][0] = dp[i - 1][0] + v[a[i]]['-'];
		repf (i, 1, m)
			dp[0][i] = dp[0][i - 1] + v['-'][b[i]];
		// dp
		repf (i, 1, n)
			repf (j, 1, m) {
				dp[i][j] = max(dp[i-1][j-1] + v[a[i]][b[j]], 
						max(dp[i-1][j] + v[a[i]]['-'], dp[i][j-1] + v['-'][b[j]]));
			}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}

