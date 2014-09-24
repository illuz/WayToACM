/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Trie_sonbrother.cpp
*  Create Date: 2014-09-24 10:01:35
*  Descripton:  left son, right brther
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;
const int MAXNODE = 1000010;

struct STrie {
	int son[MAXNODE];
	int bro[MAXNODE];
	int val[MAXNODE];
	char ch[MAXNODE];
	int sz;

	STrie() { sz = 1; ch[0] = val[0] = bro[0] = son[0] = 0; }
	void init() { sz = 1; ch[0] = val[0] = bro[0] = son[0] = 0; }
	// inline int idx(char c) { return c ? c - 'a' : 0; }
	
	void insert(char *s, int v = 1) {
		int len = strlen(s), u = 0, p;
		repf (i, 0, len - 1) {
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
			u = p;
		}
		val[u] = v;
	}

	int find(char *s) {
		int len = strlen(s), u = 0, p;
		repf (i, 0, len - 1) {
			// check the brother of u
			for (p = son[u]; p; p = bro[p]) {
				if (ch[p] == s[i])
					break;
			}
			// cannot find out than insert
			if (!p) {
				return 0;
			}
			u = p;
		}
		return val[u];
	}
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
//	int n;
//	char ch[100];
//	while (cin >> n) {
//		trie.init();
//		repf (i, 0, n - 1) {
//			cin >> ch;
//			trie.insert(ch);
//		}
//		cin >> n;
//		repf (i, 1, n) {
//			cin >> ch;
//			cout << trie.find(ch) << endl;
//		}
//	}
	return 0;
}

