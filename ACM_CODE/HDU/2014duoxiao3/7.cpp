#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

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

#include <sstream>
#include <utility>
#include <cctype>
/****************************/
#define repf(i,a,b) for(ll i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) prllf("%d",x)
#define PIN(x) prllf("%d\n",x)
#define PS(x) prllf("%s",x)
#define PN() puts("")
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define rep(i,n) for(ll i=0;i<(n);i++)
#define repu(i,a,b) for(ll i=(a);i<(b);i++)
#define repd(i,a,b) for(ll i=(a);i>=(b);i--)
#define swap(a,b) {ll t=a;a=b;b=t;}
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> PII;
#define fi first
#define sd second
/****************************/
const ll INF = (ll)(1<<31) + 1;

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
const ll ROOT = 1;
const ll MAXN = 100005;


ll n, m;
vector<ll> v;

void init() {
	v.resize(80);
	v[0] = v[1] = 1;
	for (ll i = 2; i < 80; i++) {
		v[i]  = v[i-1] + v[i-2];
	}
}

inline ll bas(ll a) { return a > 0 ? a : -a; }

ll fab(ll x) {
	vector<ll>::iterator iter1, iter2;
	iter1 = lower_bound(v.begin(), v.end() ,x);
	iter2 = iter1;
	iter2--;
	if (bas(*iter1-x) < bas(*iter2-x))
		return *iter1;
	else return *iter2;
}

struct seg {
	ll w;
	ll flag;
};

struct segment_tree {
	seg node[MAXN << 2];

	void update(ll pos) {
		node[pos].w = node[lson(pos)].w + node[rson(pos)].w;
	}

	void build(ll l, ll r, ll pos) {
		node[pos].flag = 0;
		if (l == r) {
			node[pos].w = 0;
			return;
		}
		ll m = l + r >> 1;
		build(l, m, lson(pos));
		build(m + 1, r, rson(pos));
		update(pos);
	}

	void push(ll l, ll r, ll pos) {
		seg& father = node[pos] ;
		seg& lson = node[lson(pos)];
		seg& rson = node[rson(pos)];
		ll len = r + 1 - l;
		if (father.flag) {
			lson.flag = father.flag;
			rson.flag = father.flag;
			lson.w = father.flag;
			rson.w = father.flag;
			father.flag = 0;
		}
	}

	void modify(ll l, ll r, ll pos, ll x, ll y, ll z) {
		if (z == INF) {		// change to fib
			if (node[pos].flag == 1) {
				return;
			}
			if (l == r) {
				node[pos].flag = 1;
				node[pos].w = fab(node[pos].w);
				return;
			}
			//push(l, r, pos);
			ll m = (l + r) >> 1;
			if (x <= l && r <= y) {
				node[pos].flag = 1;
				modify(l, m, lson(pos), x, y, z);
				modify(m + 1, r, rson(pos), x, y, z);
				update(pos);
				return;
			}
			if (x <= m) modify(l, m, lson(pos), x, y, z);
			if (y > m) modify(m + 1, r, rson(pos), x, y, z);
			update(pos);
		} else {
			if (x <= l && r <= y) {
				node[pos].w += z;
				node[pos].flag = 0;
				return;
			}
			//push(l, r, pos);
			ll m = (l + r) >> 1;
			if (x <= m) modify(l, m, lson(pos), x, y, z);
			if (y > m) modify(m + 1, r, rson(pos), x, y, z);
			update(pos);
		}
	}

	ll query(ll l, ll r, ll pos, ll x, ll y) {
		if (x <= l && r <= y) return node[pos] .w;
		//push(l, r, pos);
		ll m = l + r >> 1;
		ll res = 0;
		if (x <= m) res += query(l, m, lson(pos), x, y);
		if (y > m) res += query(m + 1, r, rson(pos), x, y);
		return res;
	}
} tree;

int main() {
	init();
	//	ll x;
	//	rep (i, 100) {
	//		cin >> x;
	//		cout << fab(x) << endl;
	//	}
	ll op, l, r, ans;
	while (scanf("%lld%lld", &n, &m) != EOF) {
		memset(tree.node, 0, sizeof(tree.node));
		tree.build(1, n, 1);
		for (ll i = 0; i < m; i++) {
			scanf("%lld%lld%lld", &op, &l, &r);
			if (op == 1) {
				tree.modify(1, n, 1, l, l, r);	
			}
			else if (op == 2) {
				ans = tree.query(1, n, 1, l, r);	
				printf("%lld\n", ans);
			}
			else {
				tree.modify(1, n, 1, l, r, INF);
			}
		}
	}	
	return 0;
} 
