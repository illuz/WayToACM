/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2159.cpp
*  Create Date: 2014-03-28 23:19:35
*  Descripton:   
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
/****************************/
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() printf("")
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define clr(a) memset(a,0,sizeof(a))
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 10010;

char a[N], b[N];
int t, cur, len;

bool solve(int p)
{
	while (a[p] == b[p] && p < len) p++;

	if (p == len)
		return false;

	if (a[p] == '?') {
		// a[p] = b[p]
		a[p] = b[p];
		if (solve(p + 1)) return true;
		// a[p] = b[p] - 1
		a[p] = '?';
		if (b[p] - 1 < '0') return false;
		a[p] = b[p] - 1;
		repf (i, p, len - 1)
			if (a[i] == '?') a[i] = '9';
		return true;
	}
	else if (a[p] < b[p]) {
		repf (i, p, len - 1)
			if (a[i] == '?') a[i] = '9';
		return true;
	}
	else if (a[p] > b[p]) {
		return false;
	}
}

int main()
{
	RI(t);
	while (t--) {
		RS(a);
		RS(b);
		len = strlen(a);
		cur = 0;
		if (solve(0) && a[0] != '0')
			puts(a);
		else
			puts("-1");
	}
	return 0;
}

