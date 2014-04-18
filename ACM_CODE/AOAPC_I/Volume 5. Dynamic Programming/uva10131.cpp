/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10131.cpp
*  Create Date: 2013-09-20 22:45:08
*  Descripton:  dp, lds 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
struct Ele {
	int wei;
	int iq;
	int id;
} e[MAXN];
int n = 0, dp[MAXN], path[MAXN];

bool cmp(Ele a, Ele b) {
	if (a.wei != b.wei)
		return a.wei > b.wei;
	else
		return a.iq > b.iq;
}

void print(int x) {
		printf("%d\n", e[x].id);
	if (path[x])
		print(path[x]);
	else
		printf("%d\n", e[0].id);
}

int main() {
	while (scanf("%d%d", &e[n].wei, &e[n].iq) != EOF)
		e[n].id = n + 1, path[n] = 0, dp[n++] = 1;
	sort(e, e + n, cmp);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (e[j].iq < e[i].iq && dp[j] + 1 > dp[i]) {
				path[i] = j;
				dp[i] = dp[j] + 1;
			}
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
		if (dp[ans] < dp[i])
			ans = i;
	printf("%d\n", dp[ans]);
	print(ans);
	return 0;
}

