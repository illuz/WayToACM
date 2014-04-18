/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-04-18 13:45:48
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

const int N = 12;
int t;
double s, a;
char ch[1000];

int main()
{
	scanf("%d", &t);
	while (t--) {
		s = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf", &a);
			s += a;
		}
		s /= N;
		sprintf(ch, "%.2lf", s);
		int len = strlen(ch);
		if (ch[len - 1] == '0' && ch[len - 2] == '0')
			ch[len - 3] = 0;
		if (ch[len - 1] == '0')
			ch[len - 1] = 0;
		printf("$%s\n", ch);
	}
	return 0;
}

