/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-06-07 15:41:15
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

stack<int> s, ss;

int t, n;
int a[N], big[N], bige[N];
ll ans, tmp;

int main()
{
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%d", &n);
		while (!s.empty())
			s.pop();
		while (!ss.empty())
			ss.pop();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			// 左边小的个数
			while (!s.empty() && a[s.top()] > a[i])
				s.pop();
			if (s.empty())
				big[i] = i;
			else
				big[i] = i - s.top() - 1;
			s.push(i);
			// 左边大的个数
			while (!ss.empty() && a[ss.top()] < a[i])
				ss.pop();
			if (ss.empty())
				bige[i] = i;
			else
				bige[i] = i - ss.top() - 1;
			ss.push(i);
		}
		while (!s.empty())
			s.pop();
		while (!ss.empty())
			ss.pop();
		ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			// 右边小或等于的个数
			while (!s.empty() && a[s.top()] >= a[i])
				s.pop();
			if (s.empty())
				tmp = n - i - 1;
			else
				tmp = s.top() - i - 1;
			ans -= (tmp + big[i] + tmp * big[i]) * a[i];
			s.push(i);
			// 右边大或等于的个数
			while (!ss.empty() && a[ss.top()] <= a[i])
				ss.pop();
			if (ss.empty())
				tmp = n - i - 1;
			else
				tmp = ss.top() - i - 1;
			ans += (tmp + bige[i] + tmp * bige[i]) * a[i];
			ss.push(i);
		}
		ans += n * (n + 1) / 2;
		printf("Case %d: ", cas);
		cout << ans << endl;
	}
	return 0;
}

