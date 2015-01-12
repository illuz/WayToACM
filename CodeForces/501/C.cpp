/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2015-01-12 17:24:13
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

typedef pair<int, int> PII;

vector<PII> ans;
map<PII, int> used;
deque<int> q;

int n;
int deg[N], s[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &deg[i], &s[i]);
		if (deg[i] == 1)
			q.push_back(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		if (!deg[u])
			continue;
		if (u^s[u] && !used[make_pair(s[u], u)]) {
			ans.push_back(make_pair(u, s[u]));
			used[make_pair(s[u], u)] = used[make_pair(u, s[u])] = 1;
		}
		s[s[u]] ^= u;
		if (--deg[s[u]] == 1)
			q.push_back(s[u]);
	}
	printf("%d\n", (int)ans.size());
	for (auto &i : ans)
		printf("%d %d\n", i.first, i.second);
	return 0;
}

