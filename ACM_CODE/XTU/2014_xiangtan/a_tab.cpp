/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a_tab.cpp
*  Create Date: 2014-06-07 15:10:47
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

const int N = 0;

int s(int v) {
	int ret = 0;
	for (int i = 1; i <= v; i++)
		ret += v % i;
	return ret;
}

int main()
{
	for (int i = 1; i < 20; i++) {
		printf("%d,", s(i));
	}
	return 0;
}

