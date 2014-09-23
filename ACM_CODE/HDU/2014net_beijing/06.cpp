/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        06.cpp
*  Create Date: 2014-09-21 13:03:49
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 2e5 + 10;

ll a[N], t;
ll n, m, l;

int main() {
	ios_base::sync_with_stdio(0);
	scanf("%lld", &t);
	repf (cas, 1, t) {
		printf("Case %d: ", cas);
		scanf("%lld%lld%lld", &n, &m, &l);
		repf (i, 1, n)
			scanf("%lld", &a[i]);
		a[0] = 0;
		a[++n] = m;
		sort(a + 1, a + n + 1);
		ll ans = 0;
		ll from = 0, to, next = 1;
		while (next <= n && from < m) {
			// try jump from i to next
			to = a[next];
			ll dis = to - from;
			if (dis <= 0) {
				next++;
				continue;
			}
			
			if (dis <= l) {
				// jump farther
				repf (j, next, n)
					if (a[j] - from <= l)
						next = j;
					else
						break;
				if (a[next] - from == l) {
					ans++;
					from = a[next];
					next++;
				} else {
					if (next == n) {
						ans += 1;
						break;
					}
					ans += 2;
					from = a[next] + l;
					next++;
				}
				cout << "small" << from << endl;
			} else {
				ans += 2 * (dis / (l + 1));
				from += dis / (l + 1) * (l + 1);
				cout << "big" << from << endl;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

