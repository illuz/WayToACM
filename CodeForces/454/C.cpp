/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-08-02 00:16:56
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>

int main() {
	double m, n;
	scanf("%lf%lf", &m, &n);
	double sum = m;
	for(int i = 1; i <= m; i++) {
		sum -= pow((i-1) * 1.0 / m, n);
	}
	printf("%f\n", sum);
	return 0;
}

