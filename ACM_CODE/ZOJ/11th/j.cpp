/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        j.cpp
*  Create Date: 2014-04-12 14:13:44
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

const int N = 0;
int a[] = {0,4,3,0,3,4,4,5,6,3,5,6,5,5,6,1,6,0,5,6,6,0,4,5,2,6,5,5,6,0,3,5,4,5,5,6,1,3,4,6,5,5,6,3,2,6,2,3,3,4,5,2,4,5,4,4,5,0,5,6,4,5,5,6,3,4,1,5,4,4,5,6,2,4,3,4,4,5,0,2,3,5,4,4,5,2,1,5,1,2,2,3,4,1,3,4,3,3,4,6,4,5,3,4,4,5,2,3,0,4,3,3,4,5,1,3,2,3,3,4,6,1,2,4,3,3,4,1,0,4,0,1,1,2,3,0,2,3,2,2,3,5,3,4,2,3,3,4,1,2,6,3,2,2,3,4,0,2,1,2,2,3,5,0,1,3,2,2,3,0,6,3,6,0,0,1,2,6,1,2,1,1,2,4,2,3,1,2,2,3,0,1,5,2,1,1,2,3,6,1,0,1,1,2,4,6,0,2,1,1,2,6,5,2,5,6,6,0,1,5,0,1,0,0,1,3,1,2,0,1,1,2,6,0,4,1,0,0,1,2,5,0,6,0,0,1,3,5,6,1,0,0,1,5,4,1,4,5,5,6,0,4,6,0,6,6,0,2,0,1,6,0,0,1,5,6,3,0,6,6,0,1,4,6,5,6,6,0,2,4,5,0,6,6};
char str[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
	int t;
	ll n;
	RI(t);
	while (t--) {
		cin >> n;
		n--;
		cout << (str[a[n % 294]]) << endl;
	}
	return 0;
}

