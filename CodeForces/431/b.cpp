/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-05-21 23:43:23
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;
char ch;
int g[N][N], mmax;
int a[5] = {0, 1, 2, 3, 4};

int main()
{
	int i = 0, j = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &g[i][j]);
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++) {
			g[j][i] = g[i][j] = g[i][j] + g[j][i];
		}
	do {
		mmax = max(mmax, g[a[0]][a[1]] + g[a[1]][a[2]] + g[a[2]][a[3]] * 2 + g[a[3]][a[4]] * 2);
	} while (next_permutation(a, a + 5));
	cout << mmax << endl;
	return 0;
}

