/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        test.cpp
*  Create Date: 2014-07-08 14:48:08
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

const int N = 5e5+10;

char s[N];

int main()
{
	cin >> s;
	for (int i = 0; i < 500000 - 4; i++) {
		for (int j = i + 1; j < 500000 - 4; j++) {
			if (s[i] == s[j] && s[i + 1] == s[j + 1] && s[i + 2] == s[j + 2] && s[i + 3] == s[j + 3]) {
				cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << endl;
				return 0;
			}
		}
	}
	return 0;
}

