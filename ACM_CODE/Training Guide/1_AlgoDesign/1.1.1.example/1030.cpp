/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        uvalive2995.cpp
*  Create Date: 2014-02-18 15:12:39
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

const int N = 10;

int n;
char pos[N][N][N];
char view[6][N][N];

char read_char() {
	char ch;
	while (1) {
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || ch == '.') return ch;
	}
}

void get(int k, int i, int j, int len, int &x, int &y, int &z) {
	if (k == 0) { x = len; y = j; z = i; }
	else if (k == 1) { x = n - 1 - j; y = len; z = i; }
	else if (k == 2) { x = n - 1 - len; y = n - 1 - j; z = i; }
	else if (k == 3) { x = j; y = n - 1 - len; z = i; }
	else if (k == 4) { x = n - 1 - i; y = j; z = len; }
	else { x = i; y = j; z = n - 1 - len; }
}

int main() {
	while (~RI(n) && n) {
		rep(i, n) rep(k, 6) rep(j, n) view[k][i][j] = read_char();
		rep(i, n) rep(j, n) rep(k, n) pos[i][j][k] = '#';

		rep(k, 6) rep(i, n) rep(j, n) if (view[k][i][j] == '.')
			rep(p, n) {
				int x, y, z;
				get(k, i, j, p, x, y, z);
				pos[x][y][z] = '.';
			}

		while (1) {
			bool done = true;
			rep(k, 6) rep(i, n) rep(j, n) if (view[k][i][j] != '.') {
				rep(p, n) {
					int x, y, z;
					get(k, i, j, p, x, y, z);
					if (pos[x][y][z] == '.') continue;
					if (pos[x][y][z] == '#') {
						pos[x][y][z] = view[k][i][j];
						break;
					}
					if (pos[x][y][z] == view[k][i][j]) break;
					pos[x][y][z] = '.';
					done = false;
				}
			}
			if (done) break;
		}

		int ans = 0;
		rep(i, n) rep(j, n) rep(k, n)
			if (pos[i][j][k] != '.') ans++;

		printf("Maximum weight: %d gram(s)\n", ans);
	}
	return 0;
}

