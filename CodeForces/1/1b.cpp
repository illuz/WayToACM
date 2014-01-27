/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1b.cpp
*  Create Date: 2014-01-10 10:36:16
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int n, r, c;
string a;
int t;

void output(int a) {
	if (a <= 0) return;
	if (a % 26 == 0) {
	   output(a / 26 - 1);
	   cout << 'Z';
	}
	else {
		output(a / 26);
		cout << char(a % 26 + 'A' - 1);
	}
}

int main() {
	cin >> n;
	while (n--) {
		cin >> a;
		int len = a.length();
		r = c = 0;
		if (a[0] == 'R' && a[1] < 'A' && (t = a.find("C")) > 0) {
			for (int i = t + 1; i < len; i++) {
				c = c * 10 + (a[i] - '0');
			}
			output(c);
			cout << a.substr(1, t - 1) << endl;
		}
		else {
			for (int i = 0; i < len; i++)
				if (a[i] < 'A') {
					t = i;
					break;
				}
			for (int i = 0; i < t; i++)
				r = r * 26 + (a[i] - 'A' + 1);
			cout << 'R' << a.substr(t) << 'C' << r << endl;
		}
	}
	return 0;
}

