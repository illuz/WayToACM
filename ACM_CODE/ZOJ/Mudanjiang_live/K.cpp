/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        K.cpp
*  Create Date: 2014-10-12 12:33:22
*  Descripton:   
*/

// #define HDU
// don't forget to change lld to I64d

#ifdef HDU
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
#include <bitset>
#include <sstream>
#include <utility>
#include <cctype>
typedef __int64 ll;
#else	// c++11
#include <bits/stdc++.h>
typedef long long ll;
#endif

using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 1010;
int num, op, t;
int rec[N], cnt;
string s;

int main() {
	scanf("%d", &t);
	while (t--) {
		cin >> s;
		int len = s.length();
		op = num = 0;
		repf (i, 0, len - 1) {
			if (s[i] == '*')
				op++;
			else
				num++;
		}
		// cout << op << ' ' << num << endl;
		int ans = 0;
		if (op >= num) {
			num = op - num + 1;
			op = 0;
			ans += num;
		} else {
			num = op = 0;
		}
		cnt = 0;
		memset(rec, 0, sizeof(rec));
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] != '*') rec[cnt++] = i;
		}
		cnt = 0;
		repf (i, 0, len - 1) {
			if (s[i] == '*') op++;
			else num++;
			if (op >= num) {
				swap(s[rec[cnt++]], s[i]);
				num++;
				op--;
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}

