/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        G.cpp
*  Create Date: 2014-06-07 14:08:03
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

const int N = 0;

int t, w, h;

int deal(int x) {
	if (x % 2)
		return 0;
	else
		return 1 + deal(x / 2);
}

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d%d", &w, &h);
		if ((deal(w) + deal(h)) % 2) {
			printf("Case %d: Alice\n", cas);
		} else {
			printf("Case %d: Bob\n", cas);
		}
	}
	return 0;
}

