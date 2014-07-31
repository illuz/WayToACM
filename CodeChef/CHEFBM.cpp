/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        CHEFBM.cpp
*  Create Date: 2014-05-06 21:08:36
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

typedef pair<int, int> PII;
#define x first
#define y second

const int N = 1e5 + 10;

PII pp[N];
int n, m, p;
int ans[N];

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &pp[i].x, &pp[i].y);
	}
	sort (pp, pp + p);
	int ar, ac, 
	for (int i = 0; i < p; i++) {
		//printf("%d %d\n", pp[i].x, pp[i].y);
		
	}
	return 0;
}

