/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        a_tab2.cpp
*  Create Date: 2014-06-08 00:07:15
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

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cout << i << '\t';
	}
	cout << "//	i" << endl;
	for (int i = 1; i < n; i++) {
		cout << floor(n/i) << '\t';
	}
	cout << "//	floor(n/k)" << endl;
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += floor(n/i);
		cout << sum << '\t';
	}
	cout << "//	sum" << endl;
	return 0;
}

