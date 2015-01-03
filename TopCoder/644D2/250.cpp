/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        250.cpp
*  Create Date: 2015-01-02 20:01:41
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;

class OkonomiyakiShop {
public:
	int count(vector <int> osize, int K) {
		int sz = osize.size();
		int ans = 0;
		for (int i = 0; i < sz; i++) {
			for (int j = i + 1; j < sz; j++) {
				if (abs(osize[i] - osize[j]) <= K)
					ans++;
			}
		}
		return ans;
	}
};

int main() {

	return 0;
}

