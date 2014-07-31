/*
 *  Author:      illuz <iilluzen[at]gmail.com>
 *  File:        500.cpp
 *  Create Date: 2014-07-22 19:12:34
 *  Descripton:   
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class BracketExpressions {
	int flag = 0;
	string exp;
	int len;
	char ch[6] = {'(',')','[',']','{','}'};

public:
	bool Verification() {
		string str = exp;
		stack<char> myStack;
		int i = 0 ;
		while(str[i] != '\0') {
			switch(str[i])
			{
				case '(' : myStack.push('('); break; 
						   //如果为左括号，则入栈 
				case '[' : myStack.push('['); break;
				case '{' : myStack.push('{'); break; 
				case ')' : if(myStack.empty()) return false;
							   else if(myStack.top() != '(') return false; //如果字符为左括号，则看起是否匹配，
							   //匹配就出栈，否则返回不匹配 
							   else myStack.pop(); break;
				case ']' : if(myStack.empty()) return false;
							   else if(myStack.top() != '[') return false;
							   else  myStack.pop(); break;
				case '}' : if(myStack.empty()) return false;
							   else if(myStack.top() != '{') return false;
							   else  myStack.pop(); break;
			}
			i++;
		}
		if(myStack.empty())//检索完所有的字符后，如果最后栈为空，则括号匹配成功，否则匹配失败 
			return true;
		return false;
	}

	void dfs(int pos) {
		if (flag) return;
		if (pos == len) {
			if (Verification())
				flag = 1;
			return;
		}
		if (exp[pos] == 'X') {
			for (int i = 0; i < 6; i++) {
				exp[pos] = ch[i];
				dfs(pos + 1);
			}
			exp[pos] = 'X';
		} else {
			for (int i = 0; i < 6; i++) {
				if (exp[pos] == ch[i]) {
					dfs(pos + 1);
					return;
				}
			}
			flag = -1;
		}
	}

	string ifPossible(string ex) {
		exp = ex;
		len = ex.length();
		dfs(0);
		if (flag == 1) {
			return "possible";
		} else {
			return "impossible";
		}
	}

};

int main() {
	string tt;
	BracketExpressions a;
	cin >> tt;
	cout << a.ifPossible(tt) << endl;
	return 0;
}

