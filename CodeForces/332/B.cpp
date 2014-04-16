/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-04-16 15:23:13
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
#define fi firsst
#define sd second
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

const int N = 2e5 + 10;

int x[N];
int n, k, a, b, t;
ll s[N], maxt;

int main()
{
	RII(n, k);
	rep (i, n)
		RI(x[i]);
	rep (i, n) {
		if (i < k)
			s[0] += x[i];
		else
			s[i - k + 1] = s[i - k] - x[i - k] + x[i];
	}
	a = b = t = 0;
	// t is the max num in [0, i]
	rep (i, n - k) {
		if (s[i] > s[t]) {
			t = i;
		}
		if (s[i + k] + s[t] > maxt) {
			maxt = s[i + k] + s[t];
			a = t;
			b = i + k;
		}
	}
	printf("%d %d\n", a + 1, b + 1);
	return 0;
}

