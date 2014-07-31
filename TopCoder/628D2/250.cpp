/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        250.cpp
*  Create Date: 2014-07-22 19:04:05
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

class BishopMove {
public:
	int howManyMoves(int r1, int c1, int r2, int c2) {
		int d1 = abs(r1 - r2), d2 = abs(c1 - c2);
		if (d1 == d2) {
			if (d1) {
				return 1;
			} else {
				return 0;
			}
		}
		if ((d1 + d2) % 2) {
			return 0;
		} else {
			return 2;
		}
	}
};

int main()
{

	return 0;
}

