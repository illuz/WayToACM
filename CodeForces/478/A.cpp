/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-10-17 08:57:28
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

int c, s;

int main() {
	s = 0;
	repf (i, 1, 5) {
		cin >> c;
		s += c;
	}
	if (s % 5 || s == 0)
		puts("-1");
	else
		printf("%d\n", s / 5);
	return 0;
}

