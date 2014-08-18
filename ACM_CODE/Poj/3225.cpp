/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3225.cpp
*  Create Date: 2014-08-16 19:40:37
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)

typedef long long ll;

const int N = (1<<17) + 10;
const int ROOT = 1;

int ans[N], a, b;
char op, lo, ro;

struct seg {
	int w;
	int v;
};

struct segment_tree {
	seg node[N << 2];

	void pxor(int pos) {
		if (node[pos].w != -1)
			node[pos].w ^= 1;
		else
			node[pos].v ^= 1;
	}

	void build(int l, int r, int pos) {
		node[pos].w = node[pos].v = 0;
		if (l == r) {
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
	}

	void push(int pos) {
		seg& fa = node[pos];
		seg& lhs = node[lson(pos)];
		seg& rhs = node[rson(pos)];
		if (fa.w != -1) {
			lhs.w = rhs.w = fa.w;
			lhs.v = rhs.v = 0;
			fa.w = -1;
		}
		if (node[pos].v) {
			pxor(lson(pos));
			pxor(rson(pos));
			node[pos].v = 0;
		}
	}

	// add the point [x,y] with z
	void modify(int l, int r, int pos, int x, int y, char op) {
		if (x <= l && r <= y) {
			if (op == 'U') {
				node[pos].w = 1;
				node[pos].v = 0;
			} else if (op == 'D') {
				node[pos].w = node[pos].v = 0;
			} else if (op == 'C' || op == 'S') {
				pxor(pos);
			}
			return;
		}
		push(pos);
		int m = (l + r) >> 1;
		if (x <= m)
			modify(l, m, lson(pos), x, y, op);
		else if (op == 'I' || op == 'C')
			node[lson(pos)].w = node[lson(pos)].v = 0;
		if (y > m)
			modify(m + 1, r, rson(pos), x, y, op);
		else if (op == 'I' || op == 'C')
			node[rson(pos)].w = node[rson(pos)].v = 0;
	}

	// query the segment [x, y]
	void query(int l, int r, int pos) {
		if (node[pos].w == 1) {
			repf (i, l, r)
				ans[i] = 1;
			return;
		} else if (node[pos].w == 0)
			return;
		push(pos);
		int m = (l + r) >> 1;
		query(l, m, lson(pos));
		query(m + 1, r, rson(pos));
	}

} sgm;

void output() {
	//memset(ans, 0, sizeof(ans));
	sgm.query(0, N, ROOT);
	
	bool empty = 1;
	int s = -1, e;
	repf (i, 0, N - 1) {
		if (ans[i]) {
			if (s == -1)
				s = i;
			e = i;
		} else if (s != -1) {
			if (!empty)
				printf(" ");
			empty = 0;
			printf("%c%d,%d%c", s&1? '(':'[', s >> 1, (e+1)>>1, e&1? ')':']');
			s = -1;
		}
	}
	if (empty)
		puts("empty set");
	else
		puts("");
}

int main() {
	//sgm.build(0, N, ROOT);
	while (~scanf("%c %c%d,%d%c\n", &op, &lo, &a, &b, &ro)) {
		a = (lo == '(')? ((a << 1) + 1) : (a << 1);
		b = (ro == ')')? ((b << 1) - 1) : (b << 1);
		if (a > b) {
			if (op == 'C' || op == 'I')
				sgm.node[ROOT].w = sgm.node[ROOT].v = 0;
		} else 
			sgm.modify(0, N, ROOT, a, b, op);
	}
	output();
	return 0;
}

