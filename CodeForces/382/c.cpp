/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        c.cpp
*  Create Date: 2014-01-18 00:22:34
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

const int N = 1e5 + 10;
int a[N], d[N];
int ans;
int n, mmin = 0x7f7f7f7f;

int main() {
	RI(n);
	rep(i, n)
		RI(a[i]);
	sort(a, a + n);
	repf(i, 1, n - 1) {
		d[i] = a[i] - a[i - 1];
		mmin = min(mmin, d[i]);
	}
	if (n == 1) {
		puts("-1");
		return 0;
	}
	if (mmin == 0) {
		if (a[0] == a[n - 1])
			printf("1\n%d\n", a[0]);
		else 
			puts("0");
		return 0;
	}
	if (n == 2) {
		if (mmin % 2 == 0) {
			puts("3");
			printf("%d %d %d\n", a[0] - mmin, a[0] + mmin / 2, a[1] + mmin);
			return 0;
		}
		else {
			puts("2");
			printf("%d %d\n", a[0] - mmin, a[1] + mmin);
			return 0;
		}
	}
	int cnt = 0;
	repf(i, 1, n - 1) {
		if (d[i] % mmin != 0 || d[i] / mmin > 2) {
			puts("0"); return 0;
		}
		if (d[i] / mmin == 2) {
			cnt++;
			ans = a[i] - mmin;
		}
	}
	if (cnt == 1) {
		puts("1");
		PIN(ans);
	}
	else if (cnt == 0) {
		puts("2");
		printf("%d %d\n", a[0] - mmin, a[n - 1] + mmin);
	}
	else
		puts("0");
	return 0;
}

