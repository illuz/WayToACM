/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-04-18 14:28:30
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

const int N = 100010;

int f[N], a[N], b[N], ans[N];
int m, n;

int find(int x)
{
	if (f[x] != x)
		return f[x] = find(f[x]);
	return x;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i <= n; i++)
			f[i] = i;
		for (int i = 1; i <= m; i++)
			scanf("%d%d", &a[i], &b[i]);
		for (int i = m; i > 0; i--) {
			int x = find(a[i]), y = find(b[i]);
			ans[i] = n;
			if (x != y) {
				n--;
				f[x] = y;
			}
		}
		for (int i = 1; i <= m; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}

