/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11991.cpp
*  Create Date: 2014-02-24 22:43:02
*  Descripton:   
*/

#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)

int n, q, t, a, b;
map<int, vector<int> > m;

int main() {
	while (~RII(n, q)) {
		m.clear();
		rep (i, n) {
			RI(t);
			m[t].push_back(i + 1);
		}
		rep (i, q) {
			RII(a, b);
			if (!m.count(b) || m[b].size() < a) puts("0");
			else PIN(m[b][a - 1]);
		}
	}
	return 0;
}

