/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-05-21 23:33:25
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[5], ans;
string s;

int main()
{
	for (int i = 1; i <= 4; i++)
		cin >> a[i];
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		ans += a[s[i] - '0'];
	cout << ans << endl;
	return 0;
}

