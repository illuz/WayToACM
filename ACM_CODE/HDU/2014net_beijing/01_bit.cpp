/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        01_bit.cpp
*  Create Date: 2014-10-05 15:17:24
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1005;

struct Node {
	int x;
	int y;
	double p;
	Node(int _x = 0, int _y = 0){
		x = _x;
		y = _y;
		p = 1.0 * _y / _x;
	}
	bool operator <(const Node &b) const {
		return p < b.p;
	}
};

struct Query {
	int x;
	int id;
	ll ans;
	double p;
	Query(int _id = 0, int _a = 0, int _b = 0, int _x = 0){
		id = _id;
		x = _x;
		p = 1.0 * _b / _a;
	}
	bool operator <(const Query &b) const {
		return p < b.p;
	}
};

bool cmp_id(Query a, Query b) {
	return a.id < b.id;
}

vector<Node> pt;
vector<Query> q;
int t, a, b, m, ta, tb, x;

// BIT
ll bit[N];
inline int lowbit(int x) { return x&(-x); }
void update(int pos, ll val) {
	for (int x = pos; x <= 1000; x += lowbit(x))
		bit[x] += val;
}
ll query(int pos) {
	ll ret = 0;
	for (int x = pos; x >= 1; x -= lowbit(x))
		ret += bit[x];
	return ret;
}

int main() {
	//  pre
	repf (i, 1, 1000)
		repf (j, 1, 1000) {
			pt.push_back(Node(i, j));
		}
	sort(pt.begin(), pt.end());

	scanf("%d", &t);
	repf (cas, 1, t) {
		scanf("%d%d%d", &a, &b, &m);

		q.clear();
		repf (i, 0, m - 1) {
			scanf("%d%d%d", &ta, &tb, &x);
			q.push_back(Query(i, ta, tb, x));
		}
		sort(q.begin(), q.end());

		memset(bit, 0, sizeof(bit));
		int pos = 0;
		repf (i, 0, m - 1) {
			while (pt[pos].p <= q[i].p) {
				update(pt[pos].x, (ll)(pt[pos].x + a) * (pt[pos].y + b));
				pos++;
			}
			q[i].ans = query(q[i].x);
		}
		
		sort(q.begin(), q.end(), cmp_id);
		printf("Case #%d:\n", cas);
		repf (i, 0, m - 1) {
			printf("%lld\n", q[i].ans);
		}
	}
	return 0;
}

