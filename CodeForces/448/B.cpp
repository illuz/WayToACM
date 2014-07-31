/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-07-17 22:31:59
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

string s, t;
int vis[30];

int main() {
	cin >> s >> t;
	int tlen = t.length(), slen = s.length();
	for (int i = 0; i < tlen; i++) {
		vis[t[i] - 'a']++;
	}
	for (int i = slen - tlen + 1; i < slen; i++) {
		vis[s[i] - 'a']--;
	}

	// need
	for (int i = 0; i < 26; i++) {
		if (vis[i]) {
			cout << "need tree" << endl;
			return 0;
		}
	}

	// auto
	for (int i = 0; i < slen - tlen + 1; i++) {
		//cout << s.substr(i, tlen) << endl;
		if (s.substr(i, tlen) == t) {
			cout << "automaton" << endl;
			return 0;
		}
	}

	// array
	if (slen == tlen) {
		cout << "array" << endl;
	} else {
		cout << "both" << endl;
	}

	return 0;
}

