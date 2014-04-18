/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        10006.cpp
*  Create Date: 2014-04-17 16:45:45
*  Descripton:   
*/

#include <cstdio>
#include <cmath>

const int N = 1e5;

bool nprime[N];
int n;

void init()
{
	for (int i = 2; i <= sqrt(N) + 1; i++)
		if (!nprime[i])
			for (int j = i * i; j < N; j += i)
				nprime[j] = true;
}

long long powmod(int a, int n, int m)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return a % m;
	long long res;
	res = powmod(a, n >> 1, m);
	res = (res * res) % m;
	if (n&1)
		res = a * res % m;
	return res;
}
bool judge(int n)
{
	if (!nprime[n])
		return false;
	for (int i = 1; i < n; i++)
		if (powmod(i, n, n) != i)
			return false;
	return true;
}

int main()
{
	init();
	while (scanf("%d", &n) && n)
		if (judge(n))
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	return 0;
}

