/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2562.cpp
*  Create Date: 2014-08-06 20:45:53
*  Descripton:  Highly Composite Number
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int M = 1000;

ll n;
ll bestNum;
ll bestSum;
ll hcm[M][2];
ll prim[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};  

// current is num, use the prim[k], sum of divisors, the limit of prim[k] you can use
void getNum(ll num, int k, ll sum, int limit) {
	if (sum > bestSum) {
		bestSum = sum;
		bestNum = num;
	} else if (sum == bestSum && num < bestNum) {
		bestNum = num;
	}
	
	ll p = prim[k];
	for (int i = 1; i <= limit; i++, p *= prim[k]) {		// use i prim[k]s
		if (num * p > n) break;
		getNum(num *= prim[k], k + 1, sum * (i + 1), i);
	}
}

// clac log2(n)
int log2(ll n) {
	int ret = 0;
	ll p = 1;
	while (p < n) {
		p <<= 1;
		ret++;
	}
	return ret;
}

// return the number of Highly Composite Number in [1, n]
// and save the HCM in hcm[][2]
int gethcm() {
	int ret = 0;
	n = 500000;		// [1, n]
	while (n > 0) {
		bestNum = 1;
		bestSum = 1;
		getNum(1, 0, 1, log2(n));
		cout << bestNum << ' ' << bestSum << endl;

		hcm[ret][0] = bestNum;
		hcm[ret][1] = bestSum;
		n = bestNum - 1;
		ret++;
	}
	return ret;
}

int main() {
	while (cin >> n) {
		bestNum = 1;
		bestSum = 1;
		getNum(1, 0, 1, 50);
		cout << bestNum << endl;
	}
}
