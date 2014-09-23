/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        4.cpp
*  Create Date: 2014-09-20 12:59:58
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 110;
const int INF = 40000000;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char g[N][N];
int d[N][N][10][33];
int n, m, sn;
int sx, sy;

struct Node{
	int x, y, k, s;
	int d;
	Node() {};
	Node(int _x, int _y, int _k, int _s, int _d) {
		x = _x;
		y = _y;
		k = _k;
		s = _s;
		d = _d;
	}
};

bool operator <(Node a, Node b) {
	return a.d < b.d;
}

queue<Node> q;

int bfs(int x, int y, int key, int snst) {
	while (!q.empty())
		q.pop();

	int ret = INF;
	q.push(Node(x, y, key, snst, 0));
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		x = tmp.x;
		y = tmp.y;
		key = tmp.k;
		snst = tmp.s;

		if (d[x][y][key][snst] != -1)
			continue;
		d[x][y][key][snst] = tmp.d;

		if (key == m && g[x][y] == 'T') {
			ret = min(ret, tmp.d);
		}

		repf (i, 0, 3) {
			int xx = x + dx[i], yy = y + dy[i];
			int st = g[xx][yy] - 'A';
			// if next is snack
			if (st >= 0 && st < sn) {
				if (snst & (1<<st))
					q.push(Node(xx, yy, key, snst, tmp.d + 1));
				else
					q.push(Node(xx, yy, key, (snst|(1<<st)), tmp.d + 2));
			}
			// if next is key && can open
			else if (g[xx][yy] == '1' + key) {
				q.push(Node(xx, yy, key + 1, snst, tmp.d + 1));
			}
			else if (g[xx][yy] >= '1' && g[xx][yy] < '1' + m) {
				q.push(Node(xx, yy, key, snst, tmp.d + 1));
			}
			else if (g[xx][yy] == '.' || g[xx][yy] == 'K' || g[xx][yy] == 'T')
				q.push(Node(xx, yy, key, snst, tmp.d + 1));
		}
	}

	return ret;
}

int main() {
	while (scanf("%d%d", &n, &m) && (n || m)) {
		sn = 0;
		memset(d, -1, sizeof(d));
		memset(g, 0, sizeof(g));
		repf (i, 1, n) {
			scanf("%s", g[i] + 1);
			repf (j, 1, n) {
				if (g[i][j] == 'S') {
					g[i][j] = 'A' + sn;
					sn++;
				}
				if (g[i][j] == 'K')
					sx = i, sy = j;
			}
		}

		int ans = bfs(sx, sy, 0, 0);
		if (ans >= INF)
			puts("impossible");
		else
			printf("%d\n", ans);
	}
	return 0;
}

