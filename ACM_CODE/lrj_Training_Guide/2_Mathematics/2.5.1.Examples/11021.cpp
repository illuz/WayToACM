/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        11021.cpp
*  Create Date: 2014-09-01 20:00:34
*  Descripton:  
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 1010;

int n, k, m;
double P[N], f[N];

int main() {
	int t;
	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d%d", &n, &k, &m);
		repf (i, 0, n - 1)
			scanf("%lf", &P[i]);
		f[0] = 0;
		f[1] = P[0];
		repf (i, 2, m) {
			f[i] = 0;
			repf (j, 0, n - 1)
				f[i] += P[j] * pow(f[i - 1], j);
		}
		printf("Case #%d: %.7f\n", cas, pow(f[m], k));
	}
	return 0;
}

