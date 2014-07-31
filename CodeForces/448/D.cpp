/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-07-17 23:32:18
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

const int N = 1e5 + 10;
int n, m, k;

int calc(int mid) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += min(m, mid / i);
		if (mid / i == 0) {
			break;
		}
	}
	return ret;
}

int main() {
	while (~scanf("%d%d%d", &n, &m, &k)) {
		int l = 1, r = n * m, mid, mm;
		while (l < r) {
			mid = (l + r) / 2;
			mm = calc(mid);
			if (mm < k) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		printf("%d\n", mid);
	}
	return 0;
}

