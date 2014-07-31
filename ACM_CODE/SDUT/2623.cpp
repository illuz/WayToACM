/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2623.cpp
*  Create Date: 2014-05-06 14:51:59
*  Descripton:  probality dp 
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

const int N = 10000;

int n;
double a, b, c, d, e;
double p[N];

int main()
{
	while (scanf("%d", &n) && n) {
		scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
		for (int i = 0; i < n; i++)
			p[i] = i;
		for (int i = n - 1; i > 0; i--) {
			p[0] = a * p[0] + b * p[1] + 1;
			for (int j = 1; j < i; j++) {
				p[j] = c * p[j] + d * p[j + 1] + e * p[j - 1] + 1;
			}
		}
		printf("%.2f\n", p[0]);
	}
	return 0;
}

