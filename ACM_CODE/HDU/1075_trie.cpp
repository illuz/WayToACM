/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1075_trie.cpp
*  Create Date: 2014-09-23 14:25:31
*  Descripton:  trie
*/

#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 3010;
const int SIZE = 26;

// pointer trie
struct Node {
	char* val;
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
		u->val = NULL;
		return u;
	}

	void insert(char *s, char *v) {
		Node *u = root;
		int len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (u->next[c] == NULL)
				u->next[c] = newNode();
			u = u->next[c];
		}
		u->val = new char[11];
		strcpy(u->val, v);
	}

	void find(char *s) {
		Node*u = root;
		int len = strlen(s);
		repf (i, 0, len - 1) {
			int c = idx(s[i]);
			if (u->next[c] == NULL) {
				printf("%s", s);
				return;
			}
			u = u->next[c];
		}
		if (u->val)
			printf("%s", u->val);
		else
			printf("%s", s);
	}

	void del(Node *rt) {
		if (rt == NULL)
			return;
		else {
			repf (i, 0, SIZE - 1)
				if (rt->next[i])
					del(rt->next[i]);
		}
		delete rt->val;
		delete rt;
	}
} trie;

char a[11], b[11];
char str[N], rec[N];

int main() {
	// ios_base::sync_with_stdio(0);
	scanf("%s", a);
	while (scanf("%s %s\n", a, b) && strcmp(a, "END")) {
		//cout << a << b << endl;
		trie.insert(b, a);
	}
	while (gets(str) && strcmp(str, "END")) {
		int len = strlen(str);
		int idx = 0;
		repf (i, 0, len - 1) {
			if (islower(str[i])) {
				rec[idx++] = str[i];
			} else {
				rec[idx] = 0;
				trie.find(rec);
				idx = 0;
				printf("%c", str[i]);
			}
		}
		puts("");
	}
}

