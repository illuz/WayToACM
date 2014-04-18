/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        G.cpp
*  Create Date: 2014-04-18 16:43:01
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

const int N = 6;
int n, m, q, x, y, cnt;
int g[N][N];

bool check(int x, int y)
{
	for (int i = 0; i < 4; i++) {
		int mid = 0, tx = x, ty = y;
		tx += dx[i];
		ty += dy[i];
		while (tx >= 0 && tx < n && ty >= 0 && ty < m) {
			if (g[tx][ty] == 1 && mid == 1)
				return false;
			if (g[tx][ty])
				mid++;
			tx += dx[i];
			ty += dy[i];
		}
	}
	return true;
}

void dfs(int p, int cur)
{
	if (cur > 10)
		return;
	if (p == n * m) {
		int t = 0;
		if (cur < cnt)
			return;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (g[i][j] == 1)
					if (check(i, j))
						t++;
					else
						return;
			}

		cnt = max(cnt, t);
		return;
	}
	int x = p / n, y = p - n * x;
	if (g[x][y] == -1)
		dfs(p + 1, cur);
	else {
		dfs(p + 1, cur);
		g[x][y] = 1;
		dfs(p + 1, cur + 1);
		g[x][y] = 0;
	}
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &q)) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i < q; i++) {
			scanf("%d%d", &x, &y);
			g[x][y] = -1;
		}
		cnt = 0;
		dfs(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}

