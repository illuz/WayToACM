/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        cc.cpp
*  Create Date: 2014-06-05 00:45:31
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

const int N = 1e5 + 10;
deque<int> odd, even;
vector<int> ans[N];
int n, k, p, t, cnt;

int main()
{
	scanf("%d%d%d", &n, &k, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t % 2 == 0)
			even.push_back(t);
		else
			odd.push_back(t);
	}
	int need = k - p, rest = odd.size() - need;
	while (need > 0 && !odd.empty()) {
		need--;
		ans[cnt++].push_back(odd.front());
		odd.pop_front();
	}
	if (need != 0) {
		puts("NO");
		return 0;
	}

	if (p == 0) {	// 不需要偶数就全部放最后一个里面
		if (odd.size() % 2 == 1) {	// 剩下的奇数没有不成对
			puts("NO");
			return 0;
		}
		while (!odd.empty()) {
			ans[cnt - 1].push_back(odd.front());
			odd.pop_front();
		}
		while (!even.empty()) {
			ans[cnt - 1].push_back(even.front());
			even.pop_front();
		}
	} else {
		while (p > 0 && !even.empty()) {	// 先把偶数尽量凑成剩下组
			p--;
			ans[cnt++].push_back(even.front());
			even.pop_front();
		}
		if (p == 0) {	// 如果凑够了
			if (odd.size() % 2 == 1) {	// 剩下的奇数没有不成对
				puts("NO");
				return 0;
			}
			while (!odd.empty()) {
				ans[cnt - 1].push_back(odd.front());
				odd.pop_front();
			}
			while (!even.empty()) {
				ans[cnt - 1].push_back(even.front());
				even.pop_front();
			}
		} else {		// 如果凑不够，也就是现在even是空的，而且剩下的都得交给odd凑
			while (p > 0 && !odd.empty()) {	// odd俩一对
				p--;
				ans[cnt].push_back(odd.front());
				odd.pop_front();
				if (odd.empty()) {
					puts("NO");
					return 0;
				}
				ans[cnt++].push_back(odd.front());
				odd.pop_front();
			}
			if (p == 0) {	// 凑够了，把剩余的odd都放最后一个
				if (odd.size() % 2 == 1) {
					puts("NO");
					return 0;
				}
				while (!odd.empty()) {
					ans[cnt - 1].push_back(odd.front());
					odd.pop_front();
				}
			} else {	// 如果odd凑完，还欠偶数
				puts("NO");
				return 0;
			}
		}
	}

	if (cnt != k) {
		puts("NO");
		return 0;
	}

	puts("YES");
	for (int i = 0; 1; i++) {
		if (ans[i].size() == 0)
			break;
		printf("%d", ans[i].size());
		for (int j = 0; j < ans[i].size(); j++)
			printf(" %d", ans[i][j]);
		puts("");
	}
	return 0;
}

