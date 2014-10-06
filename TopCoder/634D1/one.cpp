/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        one.cpp
*  Create Date: 2014-09-27 00:20:49
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

class ShoppingSurveyDiv1 {
public:
	int minValue(int N, int K, vector<int> s) {
		for (int r = 0; r < N; r++) {
			vector<int> x = s;
			for (int & y : x) {
				y = max(0, y - r);
			}
			int s = accumulate(x.begin(), x.end(), 0);
			int mx = *max_element(x.begin(), x.end());
			if (mx <= N - r && (K - 1) * (N - r) >= s) {
				return r;
			}
		}
	}
};

int main() {
	// ios_base::sync_with_stdio(0);
	int n, m, t, k;
	while (cin >> n >> k >> m) {
		vector<int> v;
		repf (i, 0, m - 1) {
			cin >> t;
			v.push_back(t);
		}
		ShoppingSurveyDiv1 a;
		cout << a.minValue(n, k, v) << endl;
	}
	return 0;
}
