/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        E.cpp
*  Create Date: 2014-08-16 09:43:59
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 3e5 + 10;

struct Edge {
	int x;
	int y;
	int w;
	bool operator <(const Edge& e) const {
		return w < e.w;
	}
} e[N];

int n, m;
int edge[N], node[N];		// edges and nodes' dp

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(edge, 0, sizeof(edge));
		memset(node, 0, sizeof(node));

		repf (i, 1, m) {
			scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w);
		}

		sort(e + 1, e + m + 1);

		repf (i, 1, m) {
			int j = i;
			while (j <= m && e[i].w == e[j].w) {		// update edges' dp
				int x = e[j].x;
				edge[j] = max(edge[j], node[x] + 1);
				j++;
			}

			j = i;
			while (j <= m && e[i].w == e[j].w) {		// update nodes' dp
				int y = e[j].y;
				node[y] = max(edge[j], node[y]);
				j++;
			}
			i = j - 1;
		}

		int ans = 0;
		repf (i, 1, m)
			ans = max(ans, edge[i]);

		printf("%d\n", ans);
	}
	return 0;
}

