/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        b.cpp
*  Create Date: 2014-01-27 14:19:15
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

const int N = 110;

int mem[N];
int t, m, id, n;
string op;

bool alloc() {
	RI(n);
	repf(j, 1, m - n + 1) {
		bool finded = true;
		rep(k, n) {
			if (mem[j + k]) {
				finded = false;
				break;
			}
		}
		if (finded) {
			id++;
			rep(k, n) mem[j + k] = id;
			return 1;
		}
	}
	return 0;
}

bool erase() {
	RI(n);
	if (n > id || n <= 0) return 0;
	bool erased = false;
	repf(i, 1, m)
		if (mem[i] == n) {
			mem[i] = 0;
			erased = true;
		}
	return erased;
}

void defrag() {
	int cur = 1;
	repf(i, 1, m)
		if (mem[i])
			if (i == cur) cur++;
			else {
				mem[cur++] = mem[i];
				mem[i] = 0;
			}
}

int main() {
	RII(t, m);
	rep(i, t) {
		cin >> op;
		if (op[0] == 'a') {
			if (alloc()) PIN(id);
			else puts("NULL");
		}
		else if (op[0] == 'e') {
			if (!erase()) puts("ILLEGAL_ERASE_ARGUMENT");
		}
		else defrag();
	}
	return 0;
}

