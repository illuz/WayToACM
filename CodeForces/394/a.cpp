/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-02-20 23:31:27
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define RI(x) scanf("%d",&x)
#define rep(i,n) for(int i=0;i<(n);i++)

string s;
int a, b, c;

bool print(int a, int b, int c) {
	if (a < 1 || b < 1 || c < 1) return false;
	if (a + b != c) return false;
	rep(i, a) putchar('|');
	putchar('+');
	rep(i, b) putchar('|');
	putchar('=');
	rep(i, c) putchar('|');
	return true;
}

int main() {
	cin >> s;
	a = s.find('+');
	b = s.find('=') - a - 1;
	c = s.length() - a - b - 2;
	if (print(a, b, c)) return 0;
	if (print(a + 1, b - 1, c)) return 0;
	if (print(a - 1, b + 1, c)) return 0;
	if (print(a + 1, b, c - 1)) return 0;
	if (print(a - 1, b, c + 1)) return 0;
	if (print(a, b - 1, c + 1)) return 0;
	if (print(a, b + 1, c - 1)) return 0;
	puts("Impossible");
	return 0;
}

