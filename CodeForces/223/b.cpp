/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2014-01-13 00:09:43
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

const int N = 1e5 + 10;
int n, a, m, i;
int b[5010], c[5010];

int main() {
	RI(n);
	rep(i, n) {
		RI(a);
		m = max(m, a);
		b[a]++;
		c[a]++;
	}
	string o;
	int cnt = 0;
	rep(i, m)
		if (b[i]) b[i]--, cnt++;
	for (int i = m; i >= 0; i--)
		if (b[i]) b[i]--, cnt++;
	printf("%d\n", cnt);
	rep(i, m)
		if (c[i]) c[i]--, cout << i << ' ';
	for (int i = m; i >= 0; i--)
		if (c[i]) c[i]--, cout << i << ' ';
	cout << endl;
	return 0;
}


