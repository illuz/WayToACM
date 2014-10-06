/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        01_brute_force.cpp
*  Create Date: 2014-10-05 14:34:53
*  Descripton:  brute force 
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1010;

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

void Outll(ll a) {
    if(a > 9)
        Outll(a / 10);
    putchar(a % 10 + '0');
}

int t, a, b, m;
ll ans;
int ta, tb, x, y;
int tab[N];

int main() {
	// ios_base::sync_with_stdio(0);
	t = Scan();
	repf (cas, 1, t) {
		printf("Case #%d:\n", cas);
		a = Scan();
		b = Scan();
		m = Scan();
		repf (i, 1, 1000)
			tab[i] = tab[i - 1] + i + b;
		while (m--) {
			ta = Scan();
			tb = Scan();
			x = Scan();
			ans = 0;
			repf (i, 1, x) {
				y = i * tb / ta;
				ans += (ll)tab[y] * (a + i);
			}
			Outll(ans);
			puts("");
		}
	}
	return 0;
}

