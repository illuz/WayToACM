/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-05-22 00:20:28
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 110;
const int MOD = 1e9 + 7;
ll D[N][2];
int n, d, k;

ll dp(int r, bool b)
{
	if (D[r][b] != -1)
		return D[r][b];
	if (r == 0)
		return D[r][b] = b;
	D[r][b] = 0;
	for (int i = 1; i <= min(r, k); i++)
		if (b || i >= d)
			D[r][b] = (D[r][b] + dp(r - i, 1)) % MOD;
		else
			D[r][b] = (D[r][b] + dp(r - i, 0)) % MOD;
	return D[r][b];
}

int main()
{
	memset(D, -1, sizeof(D));
	scanf("%d%d%d", &n, &k, &d);
	cout << dp(n, 0) << endl;
	return 0;
}

