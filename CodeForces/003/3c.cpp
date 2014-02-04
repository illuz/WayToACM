/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3c.cpp
*  Create Date: 2014-01-13 10:34:04
*  Descripton:  3c 
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
#define PIN(x) printf("%d\n",&x)
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

char ch[4][4];
int f, s;
int ff, ss, ii;

int main() {
	rep(i, 3) RS(ch[i]);
	rep(i, 3) rep(j, 3) {
		if (ch[i][j] == 'X') f++;
		else if (ch[i][j] == '0') s++;
	}
	if (s != f && s != f - 1) { puts("illegal"); return 0; }
	rep(i, 3) {
		if (ch[i][0] == ch[i][1] && ch[i][1] == ch[i][2] && ch[i][0] != '.') {
			if(ch[i][0] == 'X') ff++;
			else ss++;
		}
		if (ch[0][i] == ch[1][i] && ch[1][i] == ch[2][i] && ch[0][i] != '.') {
			if(ch[0][i] == 'X') ff++;
			else ss++;
		}
	}
	if (ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2] && ch[0][0] != '.') {
		if(ch[0][0] == 'X') ff++;
		else ss++;
	}
	if (ch[2][0] == ch[1][1] && ch[1][1] == ch[0][2] && ch[2][0] != '.') {
		if(ch[2][0] == 'X') ff++;
		else ss++;
	}
	if (ss && ff) { puts("illegal"); return 0; }
	if (ff && f > s) { puts("the first player won"); return 0; }
	if (ss && s == f) { puts("the second player won"); return 0; }
	if (ss || ff) { puts("illegal"); return 0; }
	if (s + f == 9) { puts("draw"); return 0; }
	if (s == f) puts("first");
	else puts("second");
	return 0;
}


