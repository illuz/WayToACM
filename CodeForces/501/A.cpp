/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2015-01-12 17:03:18
*  Descripton:  
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

typedef long long ll;

ll getpoint(int p, int t) {
	return max(3 * 25 * p, p * 250 - p * t);
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	ll misha = getpoint(a, c);
	ll vasya = getpoint(b, d);
	if (misha > vasya)
		puts("Misha");
	else if (misha < vasya)
		puts("Vasya");
	else
		puts("Tie");
	return 0;
}

