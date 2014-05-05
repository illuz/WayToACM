/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-05-04 13:51:41
*  Descripton:   
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

const int N = 20;
int p[N];
int n, m, a, b;

int main()
{
	while (~scanf("%d%d", &n, &m)) {
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			p[b + 10] += a;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			p[b + 10] += a;
		}
		for (int i = N - 1; i >= 0; i--) {
			if (p[i])
				printf("%d %d\n", p[i], i - 10);
		}
	}
	return 0;
}

