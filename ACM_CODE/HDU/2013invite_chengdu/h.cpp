/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        h.cpp
*  Create Date: 2014-05-09 13:22:51
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

double BASE = 2.34375;
int n;
char u[8];

int main()
{
	while (~scanf("%d", &n)) {
		for (int cas = 1; cas <= n; cas++) {
			scanf("%*d%s", u);
			printf("Case #%d: ", cas);
			if (u[1] == 'B')
				printf("0.00");
			else if (u[1] == 'K')
				printf("2.34");
			else if (u[1] == 'M')
				printf("4.63");
			else if (u[1] == 'G')
				printf("6.87");
			else if (u[1] == 'T')
				printf("9.05");
			else if (u[1] == 'P')
				printf("11.18");
			else if (u[1] == 'E')
				printf("13.26");
			else if (u[1] == 'Z')
				printf("15.30");
			else if (u[1] == 'Y')
				printf("17.28");
			printf("%%\n");
		}
	}
	return 0;
}

