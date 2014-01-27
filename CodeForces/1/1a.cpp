/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1a.cpp
*  Create Date: 2014-01-10 10:29:39
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	long long n, m, a;
	cin >> n >> m >> a;
	cout << ((n - 1) / a + 1) * ((m - 1) / a + 1) << endl;
	return 0;
}

