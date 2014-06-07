/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        E.cpp
*  Create Date: 2014-06-07 13:57:55
*  Descripton:   
*/

#include <cstdio>
#include <cstring>

const int N = 110;
const char cmp[] = "XTCPC";

int t;
char s[N];

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%s", s);
		int len = strlen(s);
		int j = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] == cmp[j])
				j++;
		}
		if (j == 5)
			printf("Case %d: Yes\n", cas);
		else
			printf("Case %d: No\n", cas);
	}
	return 0;
}

