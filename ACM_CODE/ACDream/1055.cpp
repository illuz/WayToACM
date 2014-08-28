/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1055.cpp
*  Create Date: 2014-08-26 09:32:08
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;
const int N = 401000;

struct BIT {
	ll arr[N<<1];
	int size;

	void init(int _size = N) {
		memset(arr, 0, sizeof(arr));
		size = _size - 1;
	}

	void add(int x, ll d) {
		while (x <= size) {
			arr[x] += d;
			x += ((x)&(-x));
		}
	}

	ll sum(int x) {
		ll ret = 0;
		while (x > 0) {
			ret += arr[x];
			x -= ((x)&(-x));
		}
		return ret;
	}

	void debug(int idx = N - 1) {
		cout << "---------" << endl;
		cout << "size=" << size << endl;
		cout << "arr[0~index]:\n";
		repf (i, 0, idx) {
			cout << arr[i] << ' ';
		}
		cout << endl;
		cout << "---------" << endl;
	}
} lb, rb;

struct Query {
	char op[2];
	int l;
	int r;
} Q[N];

int n;
int D[N];
int idx[N];
map<int, int> mp;

void init() {
	mp.clear();
	int cnt = 0;

	int id = 1;
	repf (i, 0, n - 1) {
		scanf("%s", Q[i].op);
		if (Q[i].op[0] == 'D') {
			scanf("%d%d", &Q[i].l, &Q[i].r);
			D[id++] = i;
			idx[cnt++] = Q[i].l;
			idx[cnt++] = Q[i].r;
		} else if (Q[i].op[0] == 'C') {
			scanf("%d", &Q[i].l);
		} else {
			scanf("%d%d", &Q[i].l, &Q[i].r);
			idx[cnt++] = Q[i].l;
			idx[cnt++] = Q[i].r;
		}
	}
	sort(idx, idx + cnt);
	idx[cnt] = -1;
	int tmp = 1;
	repf (i, 0, cnt - 1) {
		if (idx[i] != idx[i + 1]) {
			mp[idx[i]] = tmp++;
		}
	}
}

void solve() {
	lb.init(mp.size() + 1);
	rb.init(mp.size() + 1);
	repf (i, 0, n - 1) {
		Query &q = Q[i];
		if (q.op[0] == 'D') {
			lb.add(mp[q.l], 1);
			rb.add(mp[q.r], 1);
		} else if (q.op[0] == 'C') {
			int id = D[Q[i].l];
			lb.add(mp[Q[id].l], -1);
			rb.add(mp[Q[id].r], -1);
		} else {
//			rb.debug(5);
//			lb.debug(5);
//			cout << rb.sum(q.l - 1)<< ' ';
//			cout << lb.sum(mp.size()) << ' ';
//			cout << mp.size() << ' ';
//			cout << q.r << ' ';
//			cout <<  lb.sum(q.r)<< endl;
			printf("%lld\n",  lb.sum(mp[q.r]) - rb.sum(mp[q.l] - 1));
		}
	}
}

int main() {
	while (~scanf("%d", &n)) {
		init();
		solve();
	}
	return 0;
}

