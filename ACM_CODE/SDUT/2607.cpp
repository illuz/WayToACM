/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2607.cpp
*  Create Date: 2014-05-06 09:05:15
*  Descripton:  dp 
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

char s[N];
int n, go[26][N], og[26][N];

int dp(int p)
{
	if (go[s[p] - 'a'][p] != -1)
		return go[s[p] - 'a'][p];
	for (int i = 0; i < s[p]; i++)
		go[v] += dp(i, p - 1);
}

int main()
{
	while(~scanf("%d", &n)) {
		scanf("%s", s);
		memset(go, -1, sizeof(go));
		memset(og, -1, sizeof(og));
		for (int i = 0; i < n; i++)
			dp(i);
		for (int i = 0; i < n; i++)
			pd(i);
	}
	return 0;
}

