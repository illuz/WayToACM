/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-07-25 10:49:46
*  Descripton:   
*/

#include <iostream>
#include <string>
#define f(a) (a*(a-1)/2)
using namespace std;

string s;
long long r[2][2];

int main() {
	cin >> s;
	for (int i = 0; s[i]; i++)
		r[i&1][s[i]-'a']++;
	cout << r[0][0] * r[1][0] + r[0][1] * r[1][1] << ' '
	  	<< f(r[0][0]) + f(r[0][1]) + f(r[1][0]) + f(r[1][1]) + s.length() << endl;
	return 0;
}

