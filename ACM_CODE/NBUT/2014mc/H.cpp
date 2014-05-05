/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        H.cpp
*  Create Date: 2014-05-04 15:01:04
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

const int N = 110;

int g[N][N];
int n, m;
queue<PII> q;

bool bfs(int x, int y)
{
	while (!q.empty())
		q.pop();
	int vis[N][N] = {0};
	q.push(make_pair(x, y));
	vis[x][y] = 1;
	while (!q.empty()) {
		x = q.front().fi;
		y = q.front().sd;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i], newy = y + dy[i];
			if (g[x][y] - g[newx][newy] > 1 || vis[newx][newy])
				continue;
			if (newx == 0 || newx == n + 1 || newy == 0 || newy == m + 1)
				return true;
			vis[newx][newy] = 1;
			q.push(make_pair(newx, newy));
		}
	}
	return false;
}

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		int mmax = 0;
		bool flag = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m ;j++) {
				scanf("%d", &g[i][j]);
				mmax = max(g[i][j], mmax);
			}
		for (int i = 1; i <= n && !flag; i++)
			for (int j = 1; j <= m && !flag;j++) {
				if (mmax == g[i][j]) {
					flag = bfs(i, j);
				}
			}
		if (flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

