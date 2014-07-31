/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        206.cpp
*  Create Date: 2014-07-25 23:58:52
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 200;
const int INF = 0x7fffffff;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Triple {
	int x;
	int y;
	int rank;
};

char g[N][N];
int t, n, m, res[N][N];

void bfs(int x, int y) {
	queue<Triple> q;
	q.push((Triple){x, y, 0});
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, r = q.front().rank + 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (g[tx][ty] == '0' && res[tx][ty] > r) {
				res[tx][ty] = r;
				q.push((Triple){tx, ty, r});
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(g, 0, sizeof(g));

		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", g[i] + 1);
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == '0') {
					res[i][j] = INF;
				} else {
					res[i][j] = 0;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == '1') {
					bfs(i, j);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < m; j++) {
				printf("%d ", res[i][j]);
			}
			printf("%d\n", res[i][m]);
		}
	}
	return 0;
}

