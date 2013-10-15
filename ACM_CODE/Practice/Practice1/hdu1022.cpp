/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        hdu1022.cpp
*  Create Date: 2013-10-10 20:08:15
*  Descripton:  hdu1022, stack simulation 
*/

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

int n, ans[1005], cnt;
string I, O;
stack<char> s;

int main() {
	while (scanf("%d", &n) != EOF) {
		while (!s.empty()) s.pop();
		cin >> I >> O;
		int cur = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			s.push(I[i]);
			ans[cnt++] = 1;					// 1 = in
			while (!s.empty() && s.top() == O[cur]) {
				cur++;
				s.pop();
				ans[cnt++] = 2;				// 2 = out
			}
		}
		if (s.empty()) {
			puts("Yes.");
			for (int i = 0; i < cnt; i++)
				if (ans[i] == 1) puts("in");
				else puts("out");
		} else puts("No.");
		puts("FINISH");
	}
	return 0;
}

