/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-03-28 14:46:45
*  Descripton:  data struct 
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

const int N = 110;

vector<string> u;
vector<pair<string, int> > f;
map<string, set<string> > ug;
map<string, string> fg;
map<string, string> fu;

string usr, grp, fn;
int  n, m, t, v;

int main()
{
	RI(t);
	while (t--) {
		u.clear();
		f.clear();
		ug.clear();
		fg.clear();
		fu.clear();
		RI(n);
		rep (i, n) {
			cin >> usr;
			u.push_back(usr);
			RI(v);
			rep (i, v) {
				cin >> grp;
				ug[usr].insert(grp);
			}
		}

		RI(m);
		rep (i, m) {
			cin >> fn;
			RI(v);
			f.push_back(MP(fn, v));
			cin >> usr >> grp;
			fu[fn] = usr;
			fg[fn] = fn;
		}

		rep (i, n) {
			rep (j, m) {
				// u[i], f[j].first
				if (fu[f[j].first] == u[i])
					printf("%d", f[j].second / 100);
				// ug[u[i]]
				else if (ug[u[i]].count(fg[f[j].first]))
					printf("%d", f[j].second % 100 / 10);
				else
					printf("%d", f[j].second % 10);
				if (j != m - 1) printf(" ");
			}
			puts("");
		}
	}
	return 0;
}

