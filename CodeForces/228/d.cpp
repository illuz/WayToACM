/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        d.cpp
*  Create Date: 2014-02-04 15:00:26
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

const int N = 500;

int n, s[10];
int e[N][N];
string k;

int main() {
	// init
	int t = 0;
	repf(i, 1, 9) {
		t += i;
		int tt = (t - i + 1) * 10;
		repf(j, 1, 10) e[tt+j][1]=e[1][tt+j]=1;
		s[i] = t * 10;
		rep(j, i - 1) {
			repf(k, 1, 10) repf(l, 1, 10)
				e[tt+j*10+k][tt+j*10+10+l]=e[tt+j*10+10+l][tt+j*10+k]=1;
		}
	}
	repf(i, 2, 9) e[i][i+1]=e[i+1][i]=1;
	// cut
	cin >> k;
	if (k == "1000000000") {
		e[20][10] = e[10][20] = 1;
		k = "999999999";
	}
	n = k.length();
	reverse(k.begin(), k.end());
	rep(i, n) {
		int tt = k[i] - '0';
		repf(j, 1, tt)
			e[s[i+1]+j][10-i]=e[10-i][s[i+1]+j]=1;
	}
	// output
	PIN(N - 1);
	repf(i, 1, N - 1) {
		repf(j, 1, N - 1) printf("%c", e[i][j]?'Y':'N');
		puts("");
	}
	return 0;
}

