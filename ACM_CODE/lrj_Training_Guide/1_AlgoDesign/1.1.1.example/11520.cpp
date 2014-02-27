/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11520.cpp
*  Create Date: 2014-02-18 15:42:33
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

const int N = 11;

char mat[N][N];
int t, n;

int main() {
	RI(t);
	rep(cas, t) {
		RI(n);
		rep(i, n) RS(mat[i]);
		rep(i, n) rep(j, n) if (mat[i][j] == '.')
			for (char ch = 'A'; ch <= 'Z'; ch++) {
			bool ok = true;
			if (i > 0 && mat[i - 1][j] == ch) ok = false;
			if (i < n - 1 && mat[i + 1][j] == ch) ok = false;
			if (j > 0 && mat[i][j - 1] == ch) ok = false;
			if (j < n - 1 && mat[i][j + 1] == ch) ok = false;
			if (ok) { mat[i][j] = ch; break; }
		}
		printf("Case %d:\n", cas+1);
		rep(i, n) puts(mat[i]);
	}
	return 0;
}

