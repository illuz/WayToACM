/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-09-07 12:51:45
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 60;

char ch[N];
int t;

int main() {
	scanf("%d", &t);
	while (t--) {
		string str;
		scanf("%s", ch);
		int len = strlen(ch);
		for (int i = 0; i < len; i++)
			if ((ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= 'A' && ch[i] <= 'Z'))
				str += ch[i];
		len = str.length();
		int fin = 0;
		// cout << str << endl;
		for (int i = 1; i < len / 2 && !fin; i++)
			for (int j = 1; j < len / 2 && !fin; j++) {
				//cout << str.substr(0, i) << endl;
				string A = str.substr(0, i);
				//cout << str.substr(i, j) << endl;
				string B = str.substr(i, j);
				if (A == B) continue;
				if (A + B + A + B + A == str) {
					//cout << A << ' ' << B << endl;
					//cout << "Yes" << endl;
					fin = 1;
					continue;
				}
				if (len - (i + j) * 3 > 0) {
					string AB = A + B;
					string C = str.substr(2 * (i + j), len - (i + j) * 3);
					if (A == C || B == C) continue;
					// cout << AB << ' ' << C << endl;
					if (AB + AB + C + AB == str) {
					//	cout << "Yes" << endl;
						fin = 1;
						continue;
					}
				}
			}
		if (fin) puts("Yes");
		else puts("No");
	}
	return 0;
}

