/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        138_bf.cpp
*  Create Date: 2014-04-17 15:37:39
*  Descripton:   
*/

#include <cstdio>
#include <cmath>

int cnt;

int main()
{
	cnt = 0;
	for (int b = 2; cnt < 10; b++) {
		double a = sqrt((b + 1.) * b / 2);
		if (a == floor(a)) {
			printf("%10.0f%10d\n", a, b);
			cnt++;
		}
	}

	cnt = 0;
	for (int a = 2; cnt < 10; a++) {
		double b = sqrt(2. * a *  a + 1. / 4) - 1. / 2;
		if (b == floor(b)) {
			printf("%10d%10.0f\n", a, b);
			cnt++;
		}
	}

	return 0;
}

