/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2828.cpp
*  Create Date: 2014-08-05 20:16:28
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

const int N = 200000;
const int ROOT = 1;


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

	int remove(int l, int r, int pos, ll x) {
		if (l == r) {
			node[pos].w = 0;
			return l;
		}
		int m = (l + r) >> 1;
		int res;
		if (x < node[lson(pos)].w)
			res = remove(l, m, lson(pos), x);
		else
			res = remove(m + 1, r, rson(pos), x - node[lson(pos)].w);
		update(pos);
		return res;
	}
} sgm;

int Scan() {
	int res = 0, ch, flag = 0;
	if((ch = getchar()) == '-')
		flag = 1;
	else if(ch >= '0' && ch <= '9')
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}

void Out(int a) {
    if(a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

int a[2][N], n;
int ans[N];

int main() {
	while (~scanf("%d", &n)) {
		repf (i, 0, n - 1) {
			a[0][i] = Scan();
			a[1][i] = Scan();
		}
		sgm.build(1, n, ROOT);
		for (int i = n - 1; i >= 0; i--) {
			ans[sgm.remove(1, n, ROOT, a[0][i])] = a[1][i];
		}
		repf (i, 1, n) {
			if (i != 1)
				printf(" ");
			Out(ans[i]);
		}
		printf("\n");
	}
	return 0;
}

