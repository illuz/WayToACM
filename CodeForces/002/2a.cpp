/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2a.cpp
*  Create Date: 2014-01-10 16:07:38
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
map<string, int> rec;
int n, score[1010];
string name[1010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> score[i];
		m[name[i]] += score[i];
	}
	int mm = 0, cnt = 0;
	for (map<string, int>::iterator i = m.begin(); i != m.end(); i++) {
		if ((*i).second > mm) {
			mm = (*i).second;
		   	cnt = 0;
			//rec[cnt++] = (*i).first;
			rec.clear();
			rec[(*i).first] = 0;
		}
		else if ((*i).second == mm) {
			//rec[cnt++] = (*i).first;
			rec[(*i).first] = 0;
		}
	}

	if (rec.size() == 1)
		cout << (*rec.begin()).first << endl;
	else for (int i = 0; i < n; i++) {
		if (rec.count(name[i])) {
			rec[name[i]] += score[i];
			if (rec[name[i]] >= mm) {
				cout << name[i] << endl;
				break;
			}
		}
	}
	return 0;
}

