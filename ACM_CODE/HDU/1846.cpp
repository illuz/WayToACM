/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1846.cpp
*  Create Date: 2014-09-20 10:05:26
*  Descripton:  game
*/

#include <iostream>
using namespace std;

int t, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n % (m + 1))
			cout << "first\n";
		else
			cout << "second\n";
	}
	return 0;
}

