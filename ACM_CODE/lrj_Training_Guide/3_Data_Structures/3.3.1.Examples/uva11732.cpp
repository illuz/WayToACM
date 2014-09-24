/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        uva11732.cpp
*  Create Date: 2014-09-24 10:30:15
*  Descripton:  trie son brother
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;
const int MAXNODE =	4000010;

int n, cas;
ll ans;
char str[4001];

struct STrie {
	int son[MAXNODE];
	int bro[MAXNODE];
	int val[MAXNODE];
	char ch[MAXNODE];
	int sz;

	STrie() { sz = 1; ch[0] = val[0] = bro[0] = son[0] = 0; }
	void init() { sz = 1; ch[0] = val[0] = bro[0] = son[0] = 0; }
	// inline int idx(char c) { return c - 'a'; }
	
	void insert(char *s) {
		int len = strlen(s), u = 0, p;
		repf (i, 0, len) {
			// check the brother of u
			for (p = son[u]; p; p = bro[p]) {
				if (ch[p] == s[i])
					break;
			}
			// cannot find out than insert
			if (!p) {
				p = sz++;
				ch[p] = s[i];
				bro[p] = son[u];
				son[p] = 0;
				val[p] = 0;
				son[u] = p;
			}
			ans += (val[u] - val[p]) * (2 * i + 1);
			if (len == i) {
				ans += val[p] * (2 * i + 2);
				val[p]++;
			}
			val[u]++;
			u = p;
		}
	}
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
	while (~scanf("%d", &n) && n) {
		trie.init();
		ans = 0;
		repf (i, 0, n - 1) {
			scanf("%s", str);
			trie.insert(str);
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}

