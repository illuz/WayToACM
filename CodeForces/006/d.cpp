/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        d.cpp
*  Create Date: 2014-01-16 23:04:47
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

const int N = 16;

int t, n, a, b;
int h[N];
int rec[N], ans[N];
int mmin;

void dfs(int who, int cnt) {
	if (who == n) {
		if (h[n] >= 0) return;
		mmin = cnt;
		repf(i, 1, n) rec[i] = ans[i];
		return;
	}
	int begin = (h[who - 1] + b - 1) / b;
	if (begin < 0) begin = 0;
	repf(i, begin, 16) {
		if (i + cnt >= mmin) break;
		if (h[who - 1] - b * i >= 0) continue;
		ans[who] = i;
		h[who - 1] -= b * i;
		h[who] -= a * i;
		h[who + 1] -= b * i;
		dfs(who + 1, cnt + i);
		h[who - 1] += b * i;
		h[who] += a * i;
		h[who + 1] += b * i;
		if (h[who - 1] < b * i && h[who] < a * i && h[who + 1] < b * i)
			break;
	}
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	repf(i, 1, n) RI(h[i]);
	mmin = 0x7f7f7f7f;
	dfs(2, 0);
	PIN(mmin);
	int cnt = 0;
	repf(i, 2, n - 1)
		rep(j, rec[i]) {
			cnt++;
			if (cnt == mmin) {
				PIN(i);
				break;
			}
			else
				printf("%d ", i);

		}
	return 0;
}

