/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1247.cpp
*  Create Date: 2014-09-24 11:04:11
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 50010;
const int MAXNODE = 1000010;
const int MAXSON = 26;

// array index
struct ATrie {
	int ch[MAXNODE][MAXSON];
	int val[MAXNODE];
	int sz;		// num of nodes
	ATrie() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
	void init() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }
	inline int idx(char c) { return c ? c - 'a' : 0; }

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

char wd[N][110], a[110], b[110];
int n;

int main() {
	// ios_base::sync_with_stdio(0);
	while (gets(wd[n])) {
		trie.insert(wd[n++]);
	}
	repf (i, 0, n - 1) {
		int len = strlen(wd[i]);
		repf (j, 1, len - 1) {
			strncpy(a, wd[i], j);
			a[j] = 0;
			strcpy(b, wd[i] + j);
			// cout << a << ' ' << b << endl;
			if (trie.find(a) && trie.find(b)) {
				printf("%s\n", wd[i]);
				break;
			}
		}
	}
	return 0;
}

