/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-07-25 00:34:20
*  Descripton:   
*/

#include <iostream>
using namespace std;
typedef long long ll;

ll t, k, n, d1, d2, md;

bool jg(ll a, ll b, ll c) {
	ll s = a + b + c;
	if (k < s || (k - s) % 3)
		return 0;
	ll  t = n - k - (3 * max(max(a, b), c) - s);
	if (t < 0 || t % 3)
		return 0;
	return 1;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k >> d1 >> d2;
		md = max(d1, d2);
		if (jg(0, d1, d1 + d2) ||
			jg(d1 + d2, d2, 0) ||
			jg(d1, 0, d2) ||
			jg(md - d1, md, md - d2))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

