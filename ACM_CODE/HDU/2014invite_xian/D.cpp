/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        D.cpp
*  Create Date: 2014-07-08 13:10:59
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

char b[] = "abcdefghijklm";
char b[] = "nopqrstuvwxyz";
char s[9];

int t;

void solve() {
	for (int i = 0; i < 13; i++)
		for (int j = i + 1; j < 13; j++)
			for (int k = j + 1; k < 13; k++)
				for (int l = k + 1; l < 13; l++) {
					s[0] = b[i];
					s[1] = b[j];
					s[2] = b[k];
					s[3] = b[l];
					s[4] = a[25-i];
					s[5] = a[25-j];
					s[6] = a[25-k];
					s[7] = a[25-l];
					if (t > 8) {
						t -= 8;
						printf("%s", s);
					} else {
						for (int i = 0; i < t; i++)
							printf("%c", s[i]);
						return;
					}
				}
}

int main() {
	while (~scanf("%d", &t)) {
		int cnt = 0;
		solve();
		puts("");
	}
	return 0;
}

