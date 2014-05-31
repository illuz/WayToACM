/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-05-30 23:40:23
*  Descripton:  Fixed
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
int k, len;
char a[N];

void boo() {
	for (int i = 0; i < len; i++) {
		int p = i;	// p是后面能换的那些数中最大的位置
		for (int j = 1; j <= k && i + j < len; j++) {
			if (a[i + j] > a[p]) {
				p = i + j;
			}
		}
		if (a[p] == a[i]) {	// 如果一样大就没意义了
			continue;
		}
		for (int j = p; j > i; j--)
			swap(a[j], a[j - 1]);
		k -= p - i;
		if (k <= 0)
			return;
	}
}

int main()
{
	scanf("%s%d", a, &k);
	len = strlen(a);
	boo();
	printf("%s\n", a);
	return 0;
}

