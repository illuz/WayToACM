/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2886.cpp
*  Create Date: 2014-08-06 14:10:51
*  Descripton:  segment tree 
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

const int N = 500100;
const int ROOT = 1;

int n, k;
int maxid, maxnum;
int tab[N];
char name[N][15];
int card[N];

// below is sement point updated version
struct seg {
	ll w;
};

struct segment_tree { 
	seg node[N << 2];

	void update(int pos) {
		node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
	}

	void build(int l, int r, int pos) {
		if (l == r) {
			node[pos].w = 1;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
	}

	// remove the point that the sum of [0, it] is x, return its id
	int remove(int l, int r, int pos, ll x) {
		if (l == r) {
			node[pos].w = 0;
			return l;
		}
		int m = (l + r) >> 1;
		int res;
		if (x <= node[lson(pos)].w)
			res = remove(l, m, lson(pos), x);
		else
			res = remove(m + 1, r, rson(pos), x - node[lson(pos)].w);
		update(pos);
		return res;
	}
} sgm;

// record the num of division, O(nlogn)
void pre() {
	repf (i, 1, N - 1) {
		for (int j = i; j < N; j += i)
			tab[j]++;
	}
}

void getmaxnum(int n) {
	maxid = 1;
	maxnum = tab[1];
	repf (i, 2, n) {
		if (tab[i] > maxnum) {
			maxnum = tab[i];
			maxid = i;
		}
	}
}

int main() {
	pre();
	while (~scanf("%d%d", &n, &k)) {
		getmaxnum(n);
		sgm.build(1, n, ROOT);
		repf (i, 1, n) {
			scanf("%s%d", name[i], &card[i]);
		}
		int pos, rest = n;
		repf (i, 1, maxid) {
			pos = sgm.remove(1, n, ROOT, k);
			if (--rest == 0)
				break;
			if (card[pos] > 0)
				k = (k - 1 + card[pos] - 1) % rest + 1;
			else
				k = ((k - 1 + card[pos]) % rest + rest) % rest + 1;
		}
		printf("%s %d\n", name[pos], maxnum);
	}
	return 0;
}

