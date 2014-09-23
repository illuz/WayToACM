/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Trie_array.cpp
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
const int MAXNODE = 1000010;
const int MAXSON = 26;

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
} trie;

int main() {
	// ios_base::sync_with_stdio(0);
}

