/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-03-05 23:36:34
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

const int N = 15;
char c[N];
int n, rec[N];
int a[] = {1, 2, 3, 4, 6, 12};
int b[] = {12, 6, 4, 3, 2, 1};

int main()
{
	cin >> n;
	while (n--) {
		RS(c);
		int cnt = 0;
		clr(rec);
		rep (i, 6) {
			bool ok = 0;
			rep (j, b[i]) {
				rep (k, a[i]) {
					if (c[b[i]*k+j] == 'O') break;
					if (k == a[i] - 1) ok = 1;
				}
			}
			if (ok) rec[i]++, cnt++;
		}
		printf("%d ", cnt);
		rep (i, 6)
			if (rec[i])
				printf(" %dx%d", a[i], b[i]);
		puts("");
	}
	return 0;
}

