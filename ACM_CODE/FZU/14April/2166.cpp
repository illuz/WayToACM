/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2166.cpp
*  Create Date: 2014-04-15 15:03:49
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d",&x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define clr(a) memset(a,0,sizeof(a))

const int N = 1010;

int num[N];
int u[N][N];
int n;

int main()
{
	while (~RI(n)) {
		clr(u);
		rep (i, n) {
			RI(num[i]);
		}
		rep (i, n) {
			int tmp = 0;
			repu (j, i + 1, n - 1) {
				if (num[i] < num[j]) tmp++;
				else if (num[i] > num[j]) tmp--;
				u[i][j + 1] = tmp;
			}
		}
		rep (j, n) {
			int tmp = 0;
			repd (i, j - 1, 1) {
				if (num[j] < num[i]) tmp--;
				else if (num[j] > num[i]) tmp++;
				u[i - 1][j] += tmp;
			}
		}
		int ans = 0, rev = 0;
		rep (i, n) repu (j, i + 1, n) {
			if (num[i] > num[j]) rev++;
			if (num[i] < num[j]) u[i][j]++;
			else if (num[i] > num[j]) u[i][j]--;
			ans = min(u[i][j], ans);
		}
		printf("%d\n", rev + ans);
	}
	return 0;
}

