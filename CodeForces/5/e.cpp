/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        e.cpp
*  Create Date: 2014-01-27 22:07:38
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

const int N = 1000010;
ll l[N], r[N], a[N], b[N], c[N];
int n, mmax, imax;

int main() {
	RI(n);
	rep(i, n) {
		cin >> b[i];
		if (mmax < b[i]) {
			mmax = b[i];
			imax = i;
		}
	}
	// cut the ring into a link
	int j = 0;
	repf(i, imax + 1, n - 1)
		a[j++] = b[i];
	rep(i, imax + 1)
		a[j++] = b[i];
	
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	// get the first right bigger than a[i] to l[i]
	for (int i = n - 2; i >= 0; i--) {
		int p = i + 1;
		while (p != -1 && p != i && a[p] <= a[i]) {
			if (a[p] == a[i])
				c[i] += c[p] + 1;
			p = r[p];
		}
		if (p != i && a[p] > a[i])
			r[i] = p;
	}
	// get the first left bigger than a[i] to l[i]
	if (a[0] < a[n - 1]) l[0] = n - 1;
	for (int i = 1; i < n; i++) {
		int p = i - 1;
		while (p != -1 && p != i && a[p] <= a[i]) 
			p = l[p];
		if (p != i && a[p] > a[i])
			l[i] = p;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += c[i];
		if (l[i] == -1 || r[i] == -1) {
			if (l[i] == -1 && r[i] == -1) continue;
			ans++;
		}
		else if (l[i] == n - 1 && r[i] == n - 1)
			ans++;
		else
			ans += 2;
	}
	cout << ans << endl;
	return 0;
}

