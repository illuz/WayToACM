/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1075_map.cpp
*  Create Date: 2014-09-23 13:48:38
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

string a, b;
char s[3010];
map<string, string> mp;

int main() {
	// ios_base::sync_with_stdio(0);
	cin >> a;
	while (cin >> a) {
		if (a == "END")
			break;
		cin >> b;
		mp[b] = a;
	}
	cin >> a;
	getchar();
	while (1) {
		gets(s);
		if (!strcmp(s, "END"))
			break;
		int len = strlen(s);
		a = "";
		repf (i, 0, len - 1) {
			if (islower(s[i])) {
				a += s[i];
			} else {
				if (mp.find(a) != mp.end())
					cout << mp[a];
				else
					cout << a;
				a = "";
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}

