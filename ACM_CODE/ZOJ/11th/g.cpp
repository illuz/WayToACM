/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        g.cpp
*  Create Date: 2014-04-12 12:44:54
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

int t, a, b, c;
char o[2][2];
bool flag1, flag2;

int solve(int a, int b, char o)
{
	if (o == '+') return a + b; 
	if (o == '-') return a - b; 
	if (o == '*') return a * b; 
	if (o == '/') return a / b; 
	if (o == '%') return a % b; 
}

int main()
{
	RI(t);
	while (t--) {
		scanf("%d %s %d %s %d", &a, o[0], &b, o[1], &c);
		if (o[0][0] == '+' || o[0][0] == '-') flag1 = true;
		else flag1 = false;
		if (o[1][0] == '+' || o[1][0] == '-') flag2 = true;
		else flag2 = false;
		if (flag1 == true && flag2 == false)
			cout << solve(a, solve(b, c, o[1][0]), o[0][0]) << endl;
		else
			cout << solve(solve(a, b, o[0][0]), c, o[1][0]) << endl;
	}
	return 0;
}
