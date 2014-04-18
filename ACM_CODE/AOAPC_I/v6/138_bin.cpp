/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        138_bin.cpp
*  Create Date: 2014-04-17 14:54:28
*  Descripton:  binary search 
*/

#include <cstdio>

int cnt = 0;

void binary_search(int b)
{
	int l = 0, r = b;
	long long p, q, mid;
	while (l < r - 1) {
		mid = l + (r - l) / 2;
		p = (1 + mid) * mid / 2;
		q = (b + mid) * (b - mid + 1) / 2;
		if (p < q)
			l = mid;
		else if (p > q)
			r = mid;
		else {
			printf("%10d%10d\n", (int)mid, b);
			cnt++;
			return;
		}
	}
}

int main()
{
	for (int i = 1; cnt < 10; i++)
		binary_search(i);
	return 0;
}

