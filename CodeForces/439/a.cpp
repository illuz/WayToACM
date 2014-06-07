/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a.cpp
*  Create Date: 2014-06-04 23:36:13
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

const int N = 110;
int t[N], n, d, sum, cnt;

int main()
{
	cin >> n >> d;
	sum = (n - 1) * 10;
	cnt = (n - 1) * 2;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	if (sum > d) {
		puts("-1");
		return 0;
	}
	cout << cnt + (d - sum) / 5 << endl;
	return 0;
}

