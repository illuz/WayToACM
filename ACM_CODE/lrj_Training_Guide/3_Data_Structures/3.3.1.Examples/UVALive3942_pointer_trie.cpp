/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        UVALive3942_pointer_trie.cpp
*  Create Date: 2014-09-23 16:24:32
*  Descripton:  pointer trie
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 300010;
const int MAXSON = 26;
const int MOD = 20071027;

char st[N], wd[110];
int cas, n;
int d[N];

// pointer trie
struct Node {
	int val;
	Node *next[MAXSON];
};

struct PTrie {
	Node *root;
	PTrie() { root = newNode(); }
	void init() { del(root); root = newNode(); }
	inline int idx(char c) { return c - 'a'; }

	Node *newNode() {
		Node *u = new Node;
		repf (i, 0, MAXSON - 1) {
			u->next[i] = NULL;
		}
		u->val = 0;
		return u;
	}

	void insert(char *s, int v = 1) {
		Node *u = root;
		int len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (u->next[c] == NULL) {
				u->next[c] = newNode();
			}
			u = u->next[c];
		}
		u->val = v;
	}

	int find(char *s, int pos) {
		Node*u = root;
		int len = strlen(s), cnt = 0;
		repf (i, 0, len) {		// remember to len
			if (u->val)
				cnt = (cnt + d[pos + i]) % MOD;
			if (i == len)		// prevent to voer the string
				return cnt;
			int c = idx(s[i]);
			if (u->next[c] == NULL)
				return cnt;
			u = u->next[c];
		}
	}

	void del(Node *rt) {
		if (rt == NULL)
			return;
		else {
			repf (i, 0, MAXSON - 1)
				if (rt->next[i] != NULL)
					del(rt->next[i]);
		}
		delete rt;
	}
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
	cas = 1;
	while (~scanf("%s", st)) {
		scanf("%d", &n);
		repf (i, 0, n - 1) {
			scanf("%s", wd);
			trie.insert(wd);
		}

		int len = strlen(st);
		d[len] = 1;
		int i = len - 1;
		while (i >= 0) {
			d[i] = trie.find(st + i, i);
			i--;
		}
		printf("Case %d: %d\n", cas++, d[0]);
		trie.init();
	}
}

