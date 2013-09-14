 /*
 *   Author:        illuz <iilluzen[at]gmail.com>
 *   Blog:          http://blog.csdn.net/hcbbt
 *   File:          pairs.cpp
 *   Lauguage:      C/C++
 *   Create Date:   2013-09-06 09:06:47
 *   Descripton:    pairs, sort 
 */
#include <cstdio>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)

set<int> m;

int main() {
	int n, k, t;
	scanf("%d%d", &n, &k);
	rep(i, n) {
	   	scanf("%d", &t);
		m.insert(t);
	}
	int cnt = 0;
	for (set<int>::iterator i = m.begin(); i != m.end(); i++) {
		t = *i;
		if (m.count(t + k))
		   cnt++;	
	}
	printf("%d\n", cnt);
	return 0;
}

