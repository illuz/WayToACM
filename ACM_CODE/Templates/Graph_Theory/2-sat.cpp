/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2-sat.cpp
*  Create Date: 2014-08-07 10:30:21
*  Descripton:  2-sat 
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 100000;

struct TwoSAT {
	int n;
	vector<int> G[N<<1];
	bool mark[N<<1];
	int S[N<<1], c;

	void init(int _n) {
		n = _n;
		repf (i, 0, (_n<<1) - 1)
			G[i].clear();
		memset(mark, 0, sizeof(mark));
	}

	bool dfs(int x) {
		if (mark[x^1])
			return false;
		if (mark[x])
			return true;
		mark[x] = true;
		S[c++] = x;
		int len = G[x].size();
		repf (i, 0, len - 1)
			if (!dfs(G[x][i]))
				return false;
		return true;
	}

	// x = xval or y = yval
	void add_clause(int x, int xval, int y, int yval) {
		x = (x<<1) + xval;
		y = (y<<1) + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}

	bool sovle() {
		repf (i, 0, (n<<1) - 1) {
			if (!mark[i] && !mark[i + 1]) {
				c = 0;
				if (!dfs(i)) {
					while (c > 0)
						mark[S[--c]] = false;
					if (!dfs(i + 1))
						return false;
				}
			}
		}
	}
};

int main() {

	return 0;
}

