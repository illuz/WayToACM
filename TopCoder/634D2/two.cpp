/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        two.cpp
*  Create Date: 2014-09-26 22:36:58
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

class ShoppingSurveyDiv2 {
public:
	int minValue(int N, vector<int> s) {
		int sz = s.size(), sum = 0;
		repf (i, 0, sz - 1) sum += s[i];
		int t = N - (N * sz - sum);
		if (t < 0) t = 0;
		return t;
	}
};

int main() {
	// ios_base::sync_with_stdio(0);
	int n, m, t;
	vector<int> v;
	cin >> n >> m;
	repf (i, 0, m - 1) {
		cin >> t;
		v.push_back(t);
	}
	ShoppingSurveyDiv2 a;
	cout << a.minValue(n, v);
	return 0;
}

