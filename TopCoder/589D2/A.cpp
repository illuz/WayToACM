 /*
 *   Author:        illuz <iilluzen@gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          A.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-08-27 19:03:19
 *   Descripton:    tc 589 250 
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
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

const int MAXN = 100;

class GooseTatterrattatDiv2 {
public:
	int getmin(string S) {
		int len = S.size();
		int Max, ab[27];
		mc(ab);
		rep(i, len) ab[S[i] - 'a']++;
		Max = ab[0];
		rep(i, 26) if (Max < ab[i]) Max = ab[i];
		return len - Max;
	}
};

int main() {
	string a;
	cin >> a;
	GooseTatterrattatDiv2 b;
	cout << b.getmin(a);
	return 0;
}

