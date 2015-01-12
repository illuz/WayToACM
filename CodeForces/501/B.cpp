/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2015-01-12 17:12:37
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1010;

map<string, string> m1;
map<string, string> m2;
int q;
string a, b;

int main() {
	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (m2.find(a) != m2.end()) {
			string c = m2[a];
			m2.erase(m2.find(a));
			m1[c] = b;
			m2[b] = c;
		} else {
			m1[a] = b;
			m2[b] = a;
		}
	}
	cout << m2.size() << endl;
	for (map<string, string>::iterator i = m1.begin(); i != m1.end(); i++)
		cout << i->first << ' ' << i->second << endl;
	//for (auto &i : m1)
	//	cout << i.first << ' ' << i.second << endl;
	return 0;
}

