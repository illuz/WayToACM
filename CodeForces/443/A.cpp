/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-06-19 23:31:44
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

const int N = 30;
int vis[N];
char tmp[100];

int main()
{
	scanf("%s", tmp);
	if (tmp[1] == '}') {
		puts("0");
		return 0;
	}
	vis[tmp[1] - 'a'] = 1;
	while (~scanf("%s", tmp)) {
		vis[tmp[0] - 'a'] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (vis[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}

