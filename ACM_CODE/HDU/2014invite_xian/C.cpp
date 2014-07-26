/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-07-08 15:31:46
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
const int INF = 0X7f7f7f7f;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = {0,-1,0,1};
const int dy[] = {1,0,-1,0};
const int fx[] = {-1,-1,-1,0,0,1,1,1};
const int fy[] = {-1,0,1,-1,1,-1,0,1};
/****** TEMPLATE ENDS *******/

const int N = 1010;

ll g[N][N], mod[1000100];
int n, m;
ll X0, X1, X2, Y0, Y1, Y2;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		cin >> X0 >> X1 >> Y0 >> Y1;
		for (int i = 0; i <	n; i++) {
			for (int j = 0; j < n; j++) {
				if (i * n + j == 0) {
					continue;
				} else if (i * n + j == 1) {
					g[i][j] = (X0 * 90123 + Y0) % 8475871 + 1;
					continue;
				}
				X2 = (12345 + X1 * 23456 + X0 * 34567 + X1 * X0 * 45678) % 5837501;
				Y2 = (56789 + Y1 * 67890 + Y0 * 78901 + Y1 * Y0 * 89012) % 9860381;
				X0 = X1;
				Y0 = Y1;
				X1 = X2;
				Y1 = Y2;
				if (i == j) {
					g[i][j] = 0;
				} else {
					g[i][j] = (X2 * 90123 + Y2) % 8475871 + 1;
				}
			}
		}

	}
	return 0;
}

