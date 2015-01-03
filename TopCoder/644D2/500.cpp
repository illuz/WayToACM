/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        500.cpp
*  Create Date: 2015-01-03 09:48:22
*  Descripton:  string sort, brute force
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 0;

class LostCharacter {
public:
	vector<int> getmins(vector<string> str) {
		vector<int> ans(str.size());
		for (int  i = 0; i < str.size(); i++) {
			vector<string> tmp = str;
			for (int j = 0; j < tmp.size(); j++) {
				for (int k = 0; k < tmp[j].size(); k++) {
					if (tmp[j][k] == '?')
						tmp[j][k] = (i == j) ? 'a' : 'z';
				}
			}
			string target = tmp[i];
			sort(tmp.begin(), tmp.end());
			ans[i] = find(tmp.begin(), tmp.end(), target) - tmp.begin();
		}
		return ans;
	}
};

int main() {

	return 0;
}

