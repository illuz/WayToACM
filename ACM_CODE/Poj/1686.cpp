/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        1686.cpp
*  Create Date: 2014-08-04 20:05:00
*  Descripton:  simulate, expression 
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 90;

int prior(char c) {
    if(c == '(')
        return 0;
    else if (c == '*')
        return 2;
    else
        return 1;
}

void convert(char* s, char* tmp) {
	int len = strlen(s), n = 0;
	int res, rhs, lhs;
	stack<int> st;

	for (int i = 0; i < len; i++) {
		char r = s[i];
		if (r == ' ')
			continue;
		if ((r >= 'a' && r <= 'z') || (r >= '0' && r <= '9'))
			tmp[n++] = r;
		else {
			if (st.empty() || r == '(')
				st.push(r);
			else if (r == ')') {
				while (!st.empty() && st.top() != '(') {
					tmp[n++] = st.top();
					st.pop();
				}
				st.pop();
			} else {
				while (!st.empty() && prior(r) <= prior(st.top())) {
					tmp[n++] = st.top();
					st.pop();
				}
				st.push(r);
			}
		}
	}

	while (!st.empty()) {
		tmp[n++] = st.top();
		st.pop();
	}
	tmp[n] = 0;
}

int calc(char* t) {
	int len = strlen(t);
	int rhs = 0, lhs = 0;
	stack<int> st;

	for (int i = 0; i < len; i++) {
		if (t[i] >= '0' && t[i] <= '9') 
			st.push(t[i] - '0');
		else if (t[i] <= 'z' && t[i] >= 'a')
			st.push(t[i]);
		else {
			rhs = st.top();
			st.pop();
			lhs = st.top();
			st.pop();
			if (t[i] == '+')
				st.push(rhs + lhs);
			else if (t[i] == '-')
				st.push(lhs - rhs);
			else
				st.push(rhs * lhs);
		}
	}
	return st.top();
}

int main() {
	char str[N], temp[N];
	int n;
	scanf("%d\n",&n);
	while (n--) {

		gets(str);
		convert(str, temp);
		int ans1 = calc(temp);

		gets(str);
		convert(str, temp);
		int ans2 = calc(temp);

		if (ans1 == ans2)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
