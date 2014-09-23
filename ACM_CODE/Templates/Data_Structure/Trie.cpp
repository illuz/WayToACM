/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Trie.cpp
*  Create Date: 2014-09-23 11:04:27
*  Descripton:  template of trie 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;
const int SIZE = 26;

// array index
struct ATrie {
	int ch[N][SIZE];
	int val[N];
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
	int find(char *s) {
		int u = 0, len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (ch[u][c])
				u = ch[u][c];
			else
				return 0;
		}
		return val[u];
	}
} atrie;


// point trie
struct Node {
	int val;
	Node *next[SIZE];
};

struct PTrie {
	Node *root;
	PTrie() { root = newNode(); }
	void init() { del(root); root = newNode(); }
	inline int idx(char c) { return c - 'a'; }

	Node *newNode() {
		Node *u = new Node;
		repf (i, 0, SIZE - 1) {
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
			if (u->next[c] == NULL)
				u->next[c] = newNode();
			u = u->next[c];
		}
		u->val = v;
	}

	int find(char *s) {
		Node*u = root;
		int len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (u->next[c] == NULL)
				return 0;
			u = u->next[c];
		}
		return u->val;
	}

	void del(Node *rt) {
		if (rt == NULL)
			return;
		else {
			repf (i, 0, SIZE - 1)
				if (rt->next[i])
					del(rt->next[i]);
		}
		delete root;
	}
} ptrie;

int main() {
	ios_base::sync_with_stdio(0);
//	char str[10];
//	int v;
//	while (scanf("%s%d", str, &v) && v)
//		trie.insert(str, v);
//	while (scanf("%s%d", str, &v) && v)
//		printf("%d\n", trie.find(str));
//	return 0;
}

