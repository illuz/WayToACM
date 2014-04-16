/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-04-16 16:29:58
*  Descripton:   
*/

#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	printf("%s", n&(n - 1) ? "NO" : "YES");
	return 0;
}

