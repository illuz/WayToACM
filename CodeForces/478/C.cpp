/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-10-17 09:28:14
*  Descripton:   
*/

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

ll r, g, b;
int main() {
	cin >> r >> g >> b;
	cout << min(min(min((r+g+b)/3, r+g), r+b), g+b) << endl;
	return 0;
}

