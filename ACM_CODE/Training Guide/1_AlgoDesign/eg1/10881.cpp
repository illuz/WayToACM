/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10881.cpp
*  Create Date: 2014-02-17 20:48:43
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
const char dirName[][10] = {"L", "Turning", "R"};

struct Ant {
	int id;
	int p;
	int d;
	bool operator < (const Ant& a) const {
		return p < a.p;
	}
} bef[N], aft[N];

int order[N];
int k, l, t, n;

int main() {
	RI(k);
	rep(cas, k) {
		printf("Case #%d:\n", cas + 1);
		scanf("%d%d%d", &l, &t, &n);
		rep(i, n) {
			int p, d;
			char c;
			scanf("%d %c", &p, &c);
			d = (c == 'L' ? -1 : 1);
			bef[i] = (Ant) {i, p, d};
			aft[i] = (Ant) {0, p + t * d, d};
		}

		sort(bef, bef + n);
		rep(i, n)
			order[bef[i].id] = i;

		sort(aft, aft + n);
		rep(i, n - 1)
			if (aft[i].p == aft[i + 1].p)
				aft[i].d = aft[i + 1].d = 0;

		rep(i, n) {
			int od = order[i];
			if (aft[od].p < 0 || aft[od].p > l) puts("Fell off");
			else printf("%d %s\n", aft[od].p, dirName[aft[od].d + 1]);
		}

		puts("");
	}
	return 0;
}
