/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-07-24 23:32:17
*  Descripton:   
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 0;
int a, b;

int main() {
	scanf("%d%d", &a, &b);
	if (min(a, b) % 2) {
		puts("Akshat");
	} else {
		puts("Malvika");
	}
	return 0;
}

