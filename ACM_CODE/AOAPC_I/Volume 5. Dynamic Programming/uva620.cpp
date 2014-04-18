/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva620.cpp
*  Create Date: 2013-10-24 15:33:53
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
const int MAXN = 1100;

char cell[MAXN];
int n, ans;

int dfs(int beg, int end) {
	if (beg == end && cell[beg] == 'A')
		return 1;
	if (end >= beg + 1 && cell[end] == 'A' && dfs(beg, end - 1))
		return 1;
	if (end >= beg + 2 && cell[end] == 'B' && cell[end - 1] == 'A'  && dfs(beg, end - 2))
		return 2;
	if (end >= beg + 2 && cell[beg] == 'B' && cell[end] == 'A'  && dfs(beg + 1, end - 1))
		return 3;
	return 0;
}

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", cell);
		int len = strlen(cell);
		switch(dfs(0, len - 1)) {
			case 0: printf("MUTANT\n"); break;
			case 1: printf("SIMPLE\n"); break;
			case 2: printf("FULLY-GROWN\n"); break;
			case 3: printf("MUTAGENIC\n"); break;
		}
	}
	return 0;
}

