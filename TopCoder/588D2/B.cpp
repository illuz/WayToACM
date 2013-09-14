#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class GUMIAndSongsDiv2 {
public:
	struct T {
		int d, t;
	} t[20];
	void Sort(int n) {
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (t[i].t > t[j].t) {
					T tmp = t[i];
					t[i] = t[j];
					t[j] = tmp;
				}
	}
	int maxSongs(vector <int>, vector <int>, int);
};

int GUMIAndSongsDiv2::maxSongs(vector <int> duration, vector <int> tone, int tt) {
	int n = duration.size();
	for (int i = 0; i < n; i++) {
		t[i].d = duration[i];
		t[i].t = tone[i];
	}
	Sort(n);
	int dp[10000000][2] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = t[i].d + 1; j <= tt; j++) {
			int x = j - t[i].t;
			if (dp[x][0] == 0) {
				dp[x][0] = 1, dp[x][1] = t[i].t;
				continue;
			}
			int dt = abs(t[i].t - dp[x][1]);
			if (x - dt > 0 && dp[x - dt][0] + 1 > dp[j][0])
				dp[j][0] = dp[x - dt][0] + 1, dp[j][1] = t[i].t;
		}
	}
	return dp[17][0];
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
