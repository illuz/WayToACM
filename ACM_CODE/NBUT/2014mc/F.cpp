/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        F.cpp
*  Create Date: 2014-05-04 16:21:58
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

const int N = 300100;
int a[N], b[N], n;

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memcpy(b, a, sizeof(a));
		sort(b, b + n);
		int j = n - 1;
		for (int i = n - 1; i >= 0; i--)
			if (a[i] == b[j])
				j--;
		printf("%d\n", j + 1);
	}
	return 0;
}

