/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        d.cpp
*  Create Date: 2014-02-06 16:38:45
*  Descripton:  Manacher
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

const int N = 5e6+10;

char s[N], t[N<<1];
int p[N<<1], k[N<<1];;
int n, ans;

int main() {
	RS(s);
	int ls = strlen(s), j = 0;
	t[j++] = '$';
	t[j++] = '#';
	rep(i, ls) {
		t[j++] = s[i];
		t[j++] = '#';
	}

	int mx = 0, id = 0;
	for (int i = 1; i < j; i++) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		while (t[i + p[i]] == t[i - p[i]])
			p[i]++;
		if (i + p[i] > mx) {
			mx = i + p[i];
			id = i;
		}
		if (p[i] == i) k[i] = 1;
	}

	k[1] = 0;
	for (int i = 2; i <= ls + 2; i++) {
		if (k[(i + 1) / 2] && k[i])
			k[i] = k[(i + 1) / 2] + 1;
		ans += k[i];
	}

	PIN(ans);
	return 0;
}

