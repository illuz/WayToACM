/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        bzoj1588.cpp
*  Create Date: 2014-11-06 10:30:54
*  Descripton:  splay
*/

// #define HDU
// don't forget to change lld to I64d

#ifdef HDU
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 100005;
const int INF = 0x7fffffff;

int fa[N], key[N], son[N][2];	// 0->left, 1->right
int root, tot;

void NewNode(int &r, int f, int k) {
	r = ++tot;
	fa[r] = f;
	key[r] = k;
	son[r][0] = son[r][1] = 0;
}

void Rotate(int x, int kind) {
	int y = fa[x];
	son[y][!kind] = son[x][kind];
	fa[son[x][kind]] = y;
	if (fa[y])
		son[fa[y]] [ son[fa[y]][1] == y ] = x;
	fa[x] = fa[y];
	son[x][kind] = y;
	fa[y] = x;
}

void Splay(int r, int goal) {
	while (fa[r] != goal) {
		if (fa[fa[r]] == goal)
			Rotate(r, son[fa[r]][0] == r);
		else {
			int y = fa[r];
			int kind = son[fa[y]][0] == y;
			if (son[y][kind] == r) {
				Rotate(r, !kind);
				Rotate(r, kind);
			} else {
				Rotate(y, kind);
				Rotate(r, kind);
			}
		}
	}
	if (goal == 0) root = r;
}

int Insert(int k) {
	int r = root;
	while (son[r][key[r] < k]) {
		if (key[r] == k) {
			Splay(r, 0);
			return 0;
		}
		r = son[r][key[r] < k];
	}
	NewNode(son[r][key[r] < k], r, k);
	Splay(son[r][key[r] < k], 0);
	return 1;
}

int get_pre(int x) {
	int tmp = son[x][0];
	if (tmp == 0)
		return INF;
	while (son[tmp][1])
		tmp = son[tmp][1];
	return key[x] - key[tmp];
}

int get_next(int x) {
	int tmp = son[x][1];
	if (tmp == 0)
		return INF;
	while (son[tmp][0])
		tmp = son[tmp][0];
	return key[tmp] - key[x];
}

int n, t;

int main() {
	while (~scanf("%d", &n)) {
		int ans = 0;
		root = tot = 0;
		if (EOF == scanf("%d", &t)) t = 0;
		ans += t;
		NewNode(root, 0, t);
		repf (i, 2, n) {
			if (EOF == scanf("%d", &t)) t = 0;
			if (Insert(t))
				ans += min(get_pre(root), get_next(root));
		}
		printf("%d\n", ans);
	}
	return 0;
}

