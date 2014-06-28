/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1028.cpp
*  Create Date: 2014-05-20 14:00:02
*  Descripton:  Combinatoric 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 130;

int a[N][N];
int n, m;

int main()
{
	for (int i = 0; i <= 120; i++)
		a[i][1] = a[1][i] = 1;
	for (int i = 2; i <= 120; i++)
		for (int j = 2; j <= 120; j++) {
			if (i > j)
				a[i][j] = a[i - j][j] + a[i][j - 1];
			else if (i == j)
				a[i][j] = a[i][j - 1] + 1;
			else
				a[i][j] = a[i][i];
		}
	while (~scanf("%d", &n)) {
		printf("%d\n", a[n][n]);
	}
	return 0;
}

