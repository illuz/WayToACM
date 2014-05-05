/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        J.cpp
*  Create Date: 2014-05-04 14:27:51
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

int n, d;
int dd, mm, yy;
int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int rm[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	while (~scanf("%d", &n)) {
		d = dd = n / 86400 + 1;
		yy = mm = 0;
		for (int i = 1970; ; i++) {
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
				yy++;
				if (d <= 366) {
					for (int i = 0; i < 12; i++) {
						mm++;
						if (rm[i] < d)
							d -= rm[i];
						else
							break;
					}
					break;
				} else {
					d -= 366;
					mm += 12;
				}
			}
			else {
				yy++;
				if (d <= 365) {
					for (int i = 0; i < 12; i++) {
						mm++;
						if (m[i] < d)
							d -= m[i];
						else
							break;
					}
					break;
				} else {
					d -= 365;
					mm += 12;
				}
			}
		}

		printf("year: %d\nmonth: %d\nday: %d\n", yy, mm, dd); 
	}
	return 0;
}

