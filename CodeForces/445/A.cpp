/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-07-06 21:04:54
*  Descripton:  A 
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

const int N = 110;

char g[N][N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
	}
	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= m ; j++) {
			if (g[i][j] == '.') {
				if ((i + j) % 2) {
					g[i][j] = 'B';
				} else {
					g[i][j] = 'W';
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%s\n", g[i] + 1);
	}

	return 0;
}

