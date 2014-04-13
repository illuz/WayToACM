/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-04-13 17:27:39
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

const int N = 1010;

struct S {
	int c, p, od, ch;
} v[N], res[N];

PII r[N];
int vis[N];
int n, k, m, s;

bool cmp(struct S a, struct S b) {
	return a.p > b.p;
}
bool cmp1(struct S a, struct S b) {
	return a.od < b.od;
}

int main()
{
	RI(n);
	rep (i, n) {
		RII(v[i].c, v[i].p);
		v[i].od = i + 1;
	}
	RI(k);
	rep (i, k) {
		RI(r[i].first);
		r[i].second = i + 1;
	}
	sort(v, v + n, cmp);
	sort(r, r + k);
	m = 0;
	rep (i, n) {
		int tmp = INF, rec;
		rep (j, k) {
			if (!vis[j] && v[i].c <= r[j].first) {
				vis[j] = 1;
				res[m].c = v[i].c;
				res[m].p = v[i].p;
				res[m].od = v[i].od;
				res[m].ch = r[j].second;
				m++;
				s += v[i].p;
				break;
			}
		}
	}
	sort(res, res + m, cmp1);
	printf("%d %d\n", m, s);
	rep (i, m) printf("%d %d\n", res[i].od, res[i].ch);
	return 0;
}

