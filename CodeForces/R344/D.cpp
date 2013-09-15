/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        D.cpp
*  Create Date: 2013-09-15 01:30:30
*  Descripton:  CF200.2 D
*/

#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

char ch;

int main() {
	stack<char> s;
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		if (s.empty())
			s.push(ch);
		else {
			char t = s.top();
			if (t == ch)
				s.pop();
			else
				s.push(ch);
		}
	}
	if (s.size())
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
