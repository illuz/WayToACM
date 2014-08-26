/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        BIT.cpp
*  Create Date: 2014-08-26 09:37:09
*  Descripton:  binary indexed tree, nlog(n)
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
} bit;


int main() {

	return 0;
}

