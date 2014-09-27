/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        one.cpp
*  Create Date: 2014-09-26 21:01:23
*  Descripton:   
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;

class MountainRanges {
public:
	int countPeaks(vector<int> h) {
		int ret = 0, sz = h.size();
		if (sz == 1) {
			return 1;
		}
		if (sz == 2) {
			return h[0] != h[1];
		}
		if (h[0] > h[1])
			ret++;
		if (h[sz - 1] > h[sz - 2])
			ret++;
		// cout << sz << ' ' << ret;
		repf (i, 1, sz - 2) {
			if (h[i] > h[i - 1] && h[i] > h[i + 1])
				ret++, i++;
		}
		return ret;
	}
};

int main() {
	// ios_base::sync_with_stdio(0);
	MountainRanges a;
	int n, t;
	vector<int> v;
	cin >> n;
	while (n--) {
		cin >> t;
		v.push_back(t);
	}
	cout << a.countPeaks(v) << endl;
	return 0;
}

