/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1000.cpp
*  Create Date: 2015-01-03 10:11:50
*  Descripton:  If a vertic wit integer has enough no-int-vertics,
*               and the sum of int-vertics is equal to 
*               the number of no-int-vertics, it is POSSIBLE
*
*               !!!THIS WAS WRONG!!!
*               exp. {0,1,2,2,2} {3,-1,-1,3,-1,-1}
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 55;

// !! THIS IS WRONG !! // class TreeCutting {
private:
	vector<int> g[N], val;

	int countNoInt(int u, int fa) {
		int ret = 1;
		for (int i = 0; i < g[u].size(); i++)
			if (g[u][i] != fa && val[g[u][i]] == -1)
				ret += countNoInt(g[u][i], u);
		return ret;
	}
public:
// !! THIS IS WRONG !! // 	string can(vector<int> par, vector<int> num) {
		val = num;
		int sz = par.size();
		int n = sz + 1;
		// count
		int intv = 0;
		for (auto &it : num) {
			if (it != -1)
				intv += it;
		}
		if (intv != n)
			return "IMPOSSIBLE";
		// build graph
		for (int i = 0; i < sz; i++) {
			g[i + 1].push_back(par[i]);
			g[par[i]].push_back(i + 1);
		}
		for (int i = 0; i < n; i++) {
			if (num[i] != -1) {
				int cnt = countNoInt(i, -1);
				if (num[i] > cnt)
					return "IMPOSSIBLE";
			}
		}
		return "POSSIBLE";
	}
};

// !! THIS IS WRONG !! // int main() {
	int n, m;
	TreeCutting s;
	cin >> n;
	vector<int> par(n), num(n + 1);
	for (int i = 0; i < n; i++)
		cin >> par[i];
	for (int i = 0; i < n + 1; i++)
		cin >> num[i];
	cout << s.can(par, num) << endl;
	return 0;
}

