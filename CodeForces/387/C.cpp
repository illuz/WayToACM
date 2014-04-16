/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-04-16 15:50:25
*  Descripton:  387C 
*/

#include <cstdio>
#include <cstring>

const int N = 100010;
char s[N];
int cur, l, ans;

bool check(int la, int l)
{
	int lb = l - la;
	if (la > lb) return true;
	else if (la < lb) return false;
	else {
		for (int i = 0; i < la; i++) {
			if (s[i] > s[i + la])
				return true;
			if (s[i] < s[i + la])
				return false;
		}
		return true;
	}
}

int main()
{
	scanf("%s", s);
	l = strlen(s);
	cur = l - 1;
	while (cur >= 0) {
		if (s[cur] != '0') {
			if (check(cur, l)) {
				ans++;
				l = cur;
			}
		}
		cur--;
	}
	printf("%d\n", ans + 1);
	return 0;
}

