/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        E.cpp
*  Create Date: 2014-08-06 16:21:20
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <sstream>
#include <utility>
#include <cctype>
/****************************/
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() puts("")
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi first
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 3010;

pair<ll, ll> p[N];
ll dp[N], sum[N];	// sum[i] is the total length of [i,end] goto the pined i
int n;

int main() {
	RI(n);
	repf (i, 0, n - 1)
		cin >> p[i].fi >> p[i].sd;
	sort(p, p + n);
	for (int i = n - 2; i >= 0; i--) {
		sum[i] = sum[i + 1] + (n - i - 1) * (p[i + 1].fi - p[i].fi);
		cout << sum[i] << ' ';
	}
	dp[0] = sum[0] + p[0].sd;
	repf (i, 1, n - 1) {
		dp[i] = dp[i - 1];
		repf (j, 0, i - 1) {
			dp[i] = min(dp[i], min(dp[j], dp[j] + p[i].sd - sum[j] + sum[i]));
		}
	}
	cout << dp[n - 1] << endl;
	return 0;
}
