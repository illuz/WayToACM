//
// WRONG WAY !!!
// Beause the way below just considered one array to change.
//
/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11997.cpp
*  Create Date: 2014-02-25 15:28:22
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

const int N = 760;

int arr[N][N], pos[N], k, tot;
struct Item {
	int s;	// arr[i][pos[i]] - arr[i][pos[i] - 1]
	int i;	// id of the array
	void up() {
		pos[i]++;
		s += arr[i][pos[i]] - arr[i][pos[i] - 1];
	}
	bool operator < (const Item& b) const {
		return s > b.s;
	}
} tmp;
priority_queue<Item> q;

int main() {
	while (~RI(k)) {
		tot = 0;
		while (!q.empty()) q.pop();
		rep (i, k) {
			rep (j, k) 
				RI(arr[i][j]);
			arr[i][k] = INF;	// set the last number to INF
			sort (arr[i], arr[i] + k);
			tot += arr[i][0];
			q.push((Item){arr[i][1] - arr[i][0], i});
			pos[i] = 1;
		}
		printf("%d", tot);
		rep (i, k - 1) {
			tmp = q.top();
			q.pop();
			printf(" %d", tot + tmp.s);
			tmp.up();
			q.push(tmp);
		}
		puts("");
	}
	return 0;
}

