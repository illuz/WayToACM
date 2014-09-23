/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        UVALive3942.cpp
*  Create Date: 2014-09-23 15:43:26
*  Descripton:  trie
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 300010;
const int MAXNODE = 400010;
const int MAXSON = 26;
const int MOD = 20071027;

char st[N], wd[110];
int cas, n;
int d[N];

// array index
struct ATrie {
	int ch[MAXNODE][MAXSON];
	int val[MAXNODE];
	int sz;		// num of nodes
	ATrie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
	void init() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
	inline int idx(char c) { return c - 'a'; }

	void insert(char *s, int v = 1) {
		int u = 0, len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (!ch[u][c]) {
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	}

	// if s in trie return the value, else return 0
	int find(char *s, int pos) {
		int u = 0, len = strlen(s), cnt = 0;
		repf (i, 0, len) {
			int c = idx(s[i]);
			if (val[u])
				cnt = (cnt + d[pos + i]) % MOD;

			if (ch[u][c])
				u = ch[u][c];
			else
				return cnt;
		}
	}
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
	cas = 1;
	while (~scanf("%s", st)) {
		trie.init();
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			scanf("%s", wd);
			trie.insert(wd);
		}

		int len = strlen(st);
		d[len] = 1;
		for (int i = len - 1; i >= 0; i--) {
			d[i] = trie.find(st + i, i);
		}
		printf("Case %d: %d\n", cas++, d[0]);
	}
}

