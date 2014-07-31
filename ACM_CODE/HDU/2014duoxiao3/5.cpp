/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        5.cpp
*  Create Date: 2014-07-29 13:43:23
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

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
/****************************/
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define clr(a) memset(a,0,sizeof(a))
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() puts("")
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi first
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

int n;
ll i, len, res, v, ans;
string s, t;

bool cspace() {
	res = 1;
	v = 0;
	for (i++; s[i] != '$'; i++) {
		if (s[i] == ' ') {
			v++;
		} else {
			if (v) {
				res *= (v + 1);
				if (res * ans > 100000)
					return 0;
			}
			v = 0;
		}
	}
	if (v) {
		res *= (v+1);
		if (res * ans > 100000)
			return 0;
	}
	return 1;
}

bool cor() {
	res = 1;
	for (i++; s[i] != '}'; i++) {
		if (s[i] == '|') {
			res++;
			if (res * ans > 100000) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	while (~scanf("%d\n", &n)) {
		len = 0;
		s.clear();
		for (i = 0; i < n; i++) {
			getline(std::cin, t);
			s += t;
			len += t.length();
		}
		ans = 1;
		bool flag = true;
		for (i = 0; i < len; i++) {
			if (s[i] == '$') {
				if (!cspace()) {
					flag = false;
					break;
				}
				ans *= res;
				if (ans > 100000) {
					flag = false;
					break;
				}

			} else if (s[i] == '{') {
				if (!cor()) {
					flag = false;
					break;
				}
				if (res)
					ans *= res;
				if (ans > 100000) {
					flag = false;
					break;
				}
			}
		}
		if (flag || ans > 100000) cout << ans << endl;
		else cout << "doge" << endl;
	}

	return 0;
}

