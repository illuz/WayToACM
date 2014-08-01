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
	double a, b;
	scanf("%lf%lf", &a, &b);
	double sum = a;
	for(int i = 1; i <= a; i++) {
		sum -= pow((i-1) * 1.0 / (a), b);
	}
	printf("%f\n", sum);
	return 0;
}

