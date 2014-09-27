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
		int sz = s.size(), sum = 0;
		repf (i, 0, sz - 1) sum += s[i];
		// cout << "sum" << sum << endl;
		if ((K - 1) * N >= sum)
			return 0;
		sort(s.begin(), s.end());

		sum = 0;
		repf (i, sz - K, sz - 1) {
			sum += s[i];
		}
		int t = N - (N * K - sum);
		if (t < 0) t = 0;
		if (N == K) return t;
		else
			return s[sz - K - 1];
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
