/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        B.cpp
*  Create Date: 2014-08-26 22:43:09
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 30;

int n, k, cnt[N];
string str;
vector<int> v;

int main() {
	while (cin >> n >> k) {
		cin >> str;
		memset(cnt, 0, sizeof(cnt));
		v.clear();
		int len = str.length();
		repf (i, 0, len - 1) {
			cnt[str[i] - 'A']++;
		}
		repf (i, 0, N - 1)
			if (cnt[i])
				v.push_back(cnt[i]);
		sort(v.begin(), v.end());

		ll ans = 0;
		int sz = v.size();
		for (int i = sz - 1; i >= 0; i--) {
			if (k >= v[i]) {
				ans += (ll)v[i] * v[i];
				k -= v[i];
			} else {
				ans += (ll)k * k;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

