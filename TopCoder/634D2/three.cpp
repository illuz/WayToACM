/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        three.cpp
*  Create Date: 2014-09-26 21:57:10
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 0;

class SpecialStrings {
public:
	string findNext(string s) {
		if (s == "0") return "1";
		int len = s.length(), pos = 0;
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] == '0') {
				pos = i;
				break;
			}
		}
		if (pos == 0)
			return "";
		for (int i = len - 1; i >= 0; i--) {
			if (s[i] == '0') {
				s[i] = '1';
				repf (j, i + 1, len - 1)
					s[j] = s[j - i - 1];
				if (i == len - 1)
					return s;
				else
					i = len;
			}
		}
		return s;
	}
};

int main() {
	// ios_base::sync_with_stdio(0);
	SpecialStrings a;
	string s;
	cin >> s;
	cout << a.findNext(s) << endl;
	return 0;
}

