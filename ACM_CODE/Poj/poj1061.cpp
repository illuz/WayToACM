/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        poj1061.cpp
*  Create Date: 2014-01-27 16:16:56
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
#define PI(x) printf("%d",&x)
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
const double PI=acos(-1.0);
const int dx[]= {0,-1,0,1};
const int dy[]= {1,0,-1,0};
const int fx[]= {-1,-1,-1,0,0,1,1,1};
const int fy[]= {-1,0,1,-1,1,-1,0,1};
/***************************************/
void openfile()
{
	    freopen("data.in","rb",stdin);
		    freopen("data.out","wb",stdout);
}
/****** TEMPLATE ENDS *******/

ll n, m, x, y, l, c;

ll exgcd(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll r = exgcd(b, a % b);
	ll t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int main() {
	while (~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l)) {
		c = y - x;
		ll g;
		if (m > n) 
			g = exgcd(m - n, l);
		else {
			c = -c;
		   	g = exgcd(n - m, l);
		}
		if (m == n || c % g != 0)
			puts("Impossible");
		else {
			l /= g;
			c /= g;
			ll t = c * x;
			cout << (t % l + l) % l << endl;
		}
	}
	return 0;
}

