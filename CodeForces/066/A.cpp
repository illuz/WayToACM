/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-04-15 20:58:47
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string a;

int main()
{
	cin >> a;
	if (a[0] == '-') {
		a = a.substr(1);
		if (a.length() < 3 || (a.length() == 3 && a <= "128")) puts("byte");
		else if (a.length() < 5 || (a.length() == 5 && a <= "32768")) puts("short");
		else if (a.length() < 10 || (a.length() == 10 && a <= "2147483648")) puts("int");
		else if (a.length() < 19 || (a.length() == 19 && a <= "9223372036854775808")) puts("long");
		else puts("BigInteger");
	}
	else {
		if (a.length() < 3 || (a.length() == 3 && a <= "127")) puts("byte");
		else if (a.length() < 5 || (a.length() == 5 && a <= "32767")) puts("short");
		else if (a.length() < 10 || (a.length() == 10 && a <= "2147483647")) puts("int");
		else if (a.length() < 19 || (a.length() == 19 && a <= "9223372036854775807")) puts("long");
		else puts("BigInteger");
	}
	return 0;
}

