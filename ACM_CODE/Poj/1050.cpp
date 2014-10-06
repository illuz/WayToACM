/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1050.cpp
*  Create Date: 2014-10-02 09:49:36
*  Descripton:  dp, mat martrix sum
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 110;

int n, mat[N][N];
int sum[N];

int main() {
	// ios_base::sync_with_stdio(0);
	while (~scanf("%d", &n)) {
		repf (i, 1, n) {
			repf (j, 1, n)
				scanf("%d", &mat[i][j]);
		}
		int mmax = 0;
		repf (i, 1, n) {
			memset(sum, 0, sizeof(sum));
			repf (j, i, n) {
				int one = 0;
				repf (k, 1, n) {
					// update the sum of [i~j]
					sum[k] += mat[j][k];
					// just like the interval max of one line
					if (one < 0)
						one = sum[k];
					else
						one += sum[k];
					mmax = max(mmax, one);
				}
			}
		}
		printf("%d\n", mmax);
	}
	return 0;
}

