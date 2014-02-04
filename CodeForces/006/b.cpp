/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2014-01-16 01:09:13
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

const int N = 0;
int n, m;
char c;
char off[110][110];
int vis[110][110];
queue<PII> q;
set<char> s;

int main() {
	scanf("%d%d %c\n", &n, &m, &c);
	rep(i, n)
		gets(off[i]);
	rep(i, n) rep(j, m)
		if (off[i][j] == c) {
			q.push(MP(i, j));
			vis[i][j] = 1;
			s.insert(c);
			while (!q.empty()) {
				PII t = q.front();
				q.pop();
				rep(k, 4) {
					int tx = t.first + dx[k], ty = t.second + dy[k];
					if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
					if (vis[tx][ty]) continue;
					vis[tx][ty] = 1;
					if (off[tx][ty] != '.') s.insert(off[tx][ty]);
					if (off[tx][ty] == c) q.push(MP(tx, ty));
				}
			}
			PIN((s.size() - 1));
			return 0;
		}
	return 0;
}

