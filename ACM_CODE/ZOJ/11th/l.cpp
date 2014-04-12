/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        l.cpp
*  Create Date: 2014-04-12 13:20:10
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

const int N = 20010;

int t, n, l;
int id[N], cnt;

struct S {
	int h, m, s;
	int id;
} s[N], last;

bool cmp(struct S a, struct S b) {
	if (a.h != b.h) return a.h <= b.h;
	else if (a.m != b.m) return a.m <= b.m;
	else return a.s <= b.s;
}

int main()
{
	RI(t);
	while (t--) {
		cnt = 0;
		RII(n, l);
		rep (i, n) {
			scanf("%d:%d:%d", &s[i].h, &s[i].m, &s[i].s);
			s[i].id = i + 1;
		}
		last = (S){-1, -1, -1, 0};
		sort(s, s + n, cmp);
		rep (i, n) {
			if (cmp(last, s[i])) {
				s[i].s += l;
				s[i].m += s[i].s / 60;
				s[i].h += s[i].m / 60;
				last.s = s[i].s % 60;
				last.m = s[i].m % 60;
				last.h = s[i].h;
				id[cnt++] = s[i].id;
			}
		}
		sort (id, id + cnt);
		printf("%d\n", cnt);
		rep (i, cnt - 1)
			printf("%d ", id[i]);
		printf("%d\n", id[cnt - 1]);
	}
	return 0;
}

