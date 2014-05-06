/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2607.cpp
*  Create Date: 2014-05-05 23:37:31
*  Descripton:  It's wrong, I don't know why.
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <sstream>
#include <utility>
#include <cctype>
using namespace std;
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi firsst
#define sd second
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 100100;
const int MOD = 2012;

int n;
int up[N], down[N], rec[30];
// 递增/递减/记录每个字母的权值
char s[N];

int main()
{
	while (~scanf("%d", &n)) {
		scanf("%s", s);
		int ans = 0;

		memset(rec, 0, sizeof(rec));
		for (int i = 0; i < n; i++)	{
			int t = 0;
			for (int j = 0; j < s[i] - 'a'; j++)
				t = (t + rec[j]);
			if (rec[s[i] - 'a'])
				up[i] = t - rec[s[i] - 'a'] + 1;
			else
				up[i] = t;
			rec[s[i] - 'a'] = t + 1;
			rec[s[i] - 'a'] %= MOD;
			printf("%d ", up[i]);
		}
		puts("");

		memset(rec, 0, sizeof(rec));
		for (int i = n - 1; i >= 0; i--)	{
			int t = 0;
			for (int j = 0; j < s[i] - 'a'; j++)
				t = (t + rec[j]);
			down[i] = t;
			rec[s[i] - 'a'] = t + 1;
			rec[s[i] - 'a'] %= MOD;
			printf("%d ", down[i]);
			ans = (ans + (long long)up[i] * down[i]) % MOD;
		}
		puts("");

		printf("%d\n", ans);
	}
	return 0;
}

