/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-08-26 22:06:35
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define RI(x) scanf("%d",&x)
typedef long long ll;

const int N = 3e5 + 10;

int n, arr[N];
ll sum;

int main() {
	while (~RI(n)) {
		repf (i, 0, n - 1) {
			RI(arr[i]);
		}
		sort(arr, arr + n);
		sum = -arr[n - 1];
		repf (i, 0, n - 1) {
			sum += (ll)(i + 2) * arr[i];
		}
		cout << sum << endl;
	}
	return 0;
}

