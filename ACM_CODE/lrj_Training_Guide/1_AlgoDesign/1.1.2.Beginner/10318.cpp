/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10318.cpp
*  Create Date: 2014-06-29 19:51:39
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};

const int N = 6;

int r, c, cas;
int change[3*3], lit[N][N], prs[N*N], ans[N*N], cnt;
char str[4];

bool check(int l1) {
	if (l1 >= 0) {
		for (int i = 0; i < c; i++) {
			if (!lit[l1][i]) {
				return false;
			}
		}
	}
	return true;
}

void pressfunc(int x, int y) {
	for (int i = 0; i < 9; i++) {
		if (change[i]) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 0 && tx < r && ty >= 0 && ty < c) {
				lit[tx][ty] = !lit[tx][ty];
			}
		}
	}
}

void dfs(int x, int y, int press) {
	if (y == c) {
		if (x == r - 1) {
			// check if all light
			for (int i = 0; i < r; i++) {
				if (!check(i)) {
					return;
				}
			}

			// if all light, update the ans
			if (press < cnt) {
				cnt = press;
				for (int i = 0; i < press; i++) {
					ans[i] = prs[i];
				}
			}
			return;
		} else {
			if (!check(x - 2)) {	// if not all light in line x - 2
				return;
			}
			x++;
			y = 0;
		}
	}

	// not press
	dfs(x, y + 1, press);

	// press
	pressfunc(x, y);
	prs[press] = c * x + y + 1;
	dfs(x, y + 1, press + 1);
	pressfunc(x, y);	// roll back
}

int main() {
	while (~scanf("%d%d", &r, &c) && (r || c)) {
		// input
		for (int i = 0; i < 3; i++) {
			scanf("%s", str);
			for (int j = 0; j < 3; j++) {
				change[i*3+j] = str[j] == '*' ? 1 : 0;
			}
		}

		// init
		memset(lit, 0, sizeof(lit));
		cnt = r * c + 1;

		// solve
		printf("Case #%d\n", ++cas);
		dfs(0, 0, 0);
		if (cnt != r * c + 1) {
			for (int i = 0; i < cnt - 1; i++) {
				printf("%d ", ans[i]);
			}
			printf("%d\n", ans[cnt - 1]);
		} else {
			puts("Impossible.");
		}
	}
	return 0;
}

