
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repu(i, a, b) for (int i = (a); i < (b); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define ms(a, i) memset(a, i, sizeof(a))
#define sqr(x) ((x) * (x))
#define FI(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
typedef long long LL;
typedef unsigned long long ULL;

/****** TEMPLATE ENDS ******/

const int MAXN = 10000;
int vis[MAXN][MAXN];
	string win(vector <string> v) {
		int len = v.size();
		rep(i, len) if (v[i].find("ooooo") != string::npos)
		return "found";
		mc(vis);
		rep(i, len - 4) {
			int l = v[i].size();
			rep(j, l)
			if (vis[i][j] == 0 && v[i][j] == 'o') {
				vis[i][j] = 1;
				int cnt = 1;
				repf(k, 1, 4) {
					if (v[i + k][j] == 'o') cnt++;
					else break;
					vis[i + k][j] = 1;
				}
				if (cnt == 5) return "found";
			}
		}
		mc(vis);
		rep(i, len - 4) {
			int l = v[i].size();
			rep(j, l - 4)
			if (vis[i][j] == 0 && v[i][j] == 'o') {
				vis[i][j] = 1;
				int cnt = 1;
				repf(k, 1, 4) {
					if (v[i + k][j + k] == 'o') cnt++;
					else break;
					vis[i + k][j] = 1;
				}
				if (cnt == 5) return "found";
			}
		}
		mc(vis);
		rep(i, len - 4) {
			int l = v[i].size();
			repu(j, 4, l)
			if (vis[i][j] == 0 && v[i][j] == 'o') {
				vis[i][j] = 1;
				int cnt = 1;
				repf(k, 1, 4) {
					if (v[i + k][j - k] == 'o') cnt++;
					else break;
					vis[i + k][j] = 1;
				}
				if (cnt == 5) return "found";
			}
		}
		return "not found";
	}

int main() {
	vector<string> a;
	int n;
	string b;
	cin >> n;
	while (n--) {
		cin >> b;
		a.push_back(b);
	}
	cout << win(a);
}
