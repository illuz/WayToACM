/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-04-28 00:29:59
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

const int N = 1010;

int a[N], n, m, sum, mmax;
vector<int> in, ex;

int main()
{
	int mmax = -0x7fffffff;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			in.clear();
			ex.clear();
			sum = 0;
			for (int k = i; k <= j; k++) {
				sum += a[k];
				in.push_back(a[k]);
			}
			for (int k = 0; k < i; k++)
				ex.push_back(a[k]);
			for (int k = j + 1; k < n; k++)
				ex.push_back(a[k]);
			sort(in.begin(), in.end());
			sort(ex.begin(), ex.end());
			int l = 0, r = ex.size() - 1, p = m;
			while (p-- && l < in.size() && r >= 0) {
				if (in[l] < ex[r]) {
					sum -= in[l];
					sum += ex[r];
					l++;
					r--;
				}
			}
			mmax = max(mmax, sum);
		}
	printf("%d\n", mmax);
	return 0;
}

