/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-05-04 17:08:12
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 100010;
int n, t, a[N], rec[N], cnt;

int main()
{
	while (~scanf("%d", &n)) {
		memset(rec, -1, sizeof(rec));
		cnt = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			a[i] = t;
			cnt++;
			if (rec[t] != -1) {
				int j = rec[t] + 1;
				memset(rec, -1, sizeof(rec));
				cnt = i - j + 1;
				while (j < i)
					rec[a[j++]] = j;
			}
			ans += cnt;
			rec[t] = i;
		}
		cout << ans << endl;
	}
	return 0;
}

