/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        H.cpp
*  Create Date: 2014-04-18 15:52:56
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

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
using namespace std;
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi firsst
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

const int N = 24;

int dp[N][N][N][N], A[N], B[N];
int t, n;

int f(int a, int b, int c, int d)
{
	int &r = dp[a][b][c][d];
	if (r >= 0)
		return r;
	if (a > b && c > d)
		return r = 0;
	int s = A[b] - A[a - 1] + B[d] - B[c - 1];
	int t1 = a > b ? INF : f(a + 1, b, c, d);
   	int t2 = a > b ? INF : f(a, b - 1, c, d);
	int t3 = c > d ? INF : f(a, b, c + 1, d);
	int t4 = c > d ? INF : f(a, b, c, d - 1);
	if (t1 < t2 && t1 < t3 && t1 < t4) {
		return r = s - t1;
	} else if (t2 < t3 && t2 < t4) {
		return r = s - t2;
	} else if (t3 < t4) {
		return r = s - t3;
	} else {
		return r = s - t4;
	}
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
			A[i] += A[i - 1];
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &B[i]);
			B[i] += B[i - 1];
		}
		printf("%d\n", f(1, n, 1, n));
	}
	return 0;
}

