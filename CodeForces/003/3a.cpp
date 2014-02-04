/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3a.cpp
*  Create Date: 2014-01-12 19:52:21
*  Descripton:   
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 0;
string a, b, c;
int h, w, cnt;

int main() {
	cin >> a >> b;
	h = b[0] - a[0];
	w = b[1] - a[1];
	while (h != 0 || w != 0) {
		if (h > 0)
			c.push_back('R'), h--;
		else if (h < 0)
			c.push_back('L'), h++;
		if (w > 0) 
			c.push_back('U'), w--;
		else if (w < 0)
			c.push_back('D'), w++;
		c.push_back('\n');
		cnt++;
	}

	cout << cnt << endl;
	cout << c;

	return 0;
}


