/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        A.cpp
*  Create Date: 2014-07-08 12:17:42
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
string tmp;
int cnt;

int main() {
	cnt = 0;
	while (cin >> tmp) {
		int len = tmp.length();
		for (int i = 0; i < len - 4 + 1; i++) {
			if (
					tolower(tmp[i]) == 'd' &&
					tolower(tmp[i + 1]) == 'o' &&
					tolower(tmp[i + 2]) == 'g' &&
					tolower(tmp[i + 3]) == 'e')
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}

