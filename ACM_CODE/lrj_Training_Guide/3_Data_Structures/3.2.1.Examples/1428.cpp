/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1428.cpp
*  Create Date: 2014-02-28 16:24:09
*  Descripton:  BIT
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define clr(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;

const int N = 1e5 + 10;
const int M = 2e4 + 10;

int n, t, tmp, mmax;
int v[N], a[M], rec[M];
ull ans;

int lowbit(int x) { return x&-x; }

void add(int x)
{
	while (x <= mmax) {
		v[x]++;
		x += lowbit(x);
	}
}

int sum(int x) 
{
	int ret = 0;
	while (x > 0) {
		ret += v[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() 
{
	RI(t);
	while (t--) {
		RI(n);
		mmax = 0;
		repf (i, 1, n) {
			RI(a[i]);
			mmax = max(mmax, a[i]);
		}
		// get the number of players who less than a[i]
		clr(v);
		repf (i, 1, n) {
			rec[i] = sum(a[i]);
			add(a[i]);
		}
		// calculate the answer
		ans = 0;
		clr(v);
		repd (i, n, 1) {
			tmp = sum(a[i]);
			add(a[i]);
			ans += rec[i] * (n - i - tmp) + tmp * (i - 1 - rec[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

