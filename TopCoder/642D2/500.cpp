/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        500.cpp
*  Create Date: 2014-12-17 10:18:58
*  Descripton:  greedy?
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1010;

class LightSwitchingPuzzle {
private:
	bool vis[1010];
public:
	int minFlips(string st) {
		memset(vis, 0, sizeof(vis));
		int len = st.length();
		int ans = 0;
		for (int i = 1; i <= len; i++) {
			bool tmp = (st[i - 1] == 'Y');
			for (int j = 1; j <= i; j++)
				if (i % j == 0 && vis[j])
					tmp = !tmp;
			if (tmp) {
				vis[i] = 1;
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	LightSwitchingPuzzle s;
	string st;
	while (cin >> st)
		cout << s.minFlips(st) << endl;
	return 0;
}

