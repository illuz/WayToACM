/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-05-29 21:05:38
*  Descripton:   
*/

#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int t, n, m, p[N], tmp, ans[N], cnt;
bool flag;
vector<int> v[N];

void dfs(int r, int val) {
	if (r >= m || p[r] - 1 < 0 || v[r][p[r] - 1] < val)
		return;
	ans[cnt++] = v[r][p[r] - 1];
	dfs(r + 1, v[r][p[r] - 1]);
	p[r]--;
}

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		printf("Case #%d:", cas);

		scanf("%d%d", &n, &m);
		flag = false;

		for (int i = 0; i < m; i++) {
			v[i].clear();
			scanf("%d", &p[i]);

			for (int j = 0; j < p[i]; j++) {
				scanf("%d", &tmp);
				v[i].push_back(tmp);
				if (j > 0 && v[i][j] < v[i][j - 1])
					flag = true;
			}

			if (i > 0 && v[i][0] < v[i - 1][0])
				flag = true;
		}

		if (flag) {
			puts(" No solution");
			continue;
		}

		cnt = 0;
		for (int i = p[0] - 1; i >= 0; i--) {
			ans[cnt++] = v[0][i];
			dfs(1, v[0][i]);
		}

		if (cnt != n) {
			puts(" No solution");
			continue;
		}
		for (int i = cnt - 1; i >= 0; i--)
			printf(" %d", ans[i]);
		puts("");
	}
	return 0;
}

