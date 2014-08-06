/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-05 12:01:20
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

const int N = 100010;
const int ROOT = 1;

// below is sement point updated
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
            node[pos].w = 0;
            return;
        }
        int m = (l + r) >> 1;
        build(l, m, lson(pos));
        build(m + 1, r, rson(pos));
        update(pos);
    }

    // add the point x with y
    void modify(int l, int r, int pos, int x, ll y) {
        if (l == r) {
            node[pos].w += y;
            return;
        }
        int m = (l + r) >> 1;
        if (x <= m)
            modify(l, m, lson(pos), x, y);
        else
            modify(m + 1, r, rson(pos), x, y);
        update(pos);
    }

    // query the segment [x, y]
    ll query(int l, int r, int pos, int x, int y) {
        if (x <= l && r <= y)
            return node[pos].w;
        int m = (l + r) >> 1;
        ll res = 0;
        if (x <= m)
            res += query(l, m, lson(pos), x, y);
        if (y > m)
            res += query(m + 1, r, rson(pos), x, y);
        return res;
    }

    // remove the point that the sum of [0, it] is x, return its id
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

int n, a[N], b[N], t, sum, mmin;
int m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        sgm.build(1, n, ROOT);
        sum = 0;
        repf (i, 1, n)
            scanf("%d", &a[i]);
        for (int i = n; i >= 1; i--) {
            b[i] = sgm.query(1, n, ROOT, 1, a[i]);
            sum += b[i];
            sgm.modify(1, n, ROOT, a[i], 1);
        }
		cout << sum << endl;
		cout << max(sum - m, 0) << endl;
    }
    return 0;
}
