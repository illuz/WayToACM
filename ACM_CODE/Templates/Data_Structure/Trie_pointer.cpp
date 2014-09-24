/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Trie_pointer.cpp
*  Create Date: 2014-09-23 14:26:39
*  Descripton:  template
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;
const int MAXSON = 26;

// pointer trie
struct Node {
	int val;
	Node *next[MAXSON];
};

struct PTrie {
	Node *root;
	PTrie() { root = newNode(); }
	void init() { del(root); root = newNode(); }
	inline int idx(char c) { return c ? c - 'a' : 0; }

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
			repf (i, 0, MAXSON - 1)
				if (rt->next[i])
					del(rt->next[i]);
		}
		delete rt;
	}
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
}

