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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repf(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define swap(a, b) {int t = a; a = b; b = t;}
#define mc(a) memset(a, 0, sizeof(a))
#define MAXN 100

class KeyDungeonDiv2 {
public:
	int countDoors(vector <int>, vector <int>, vector <int>);
};

int KeyDungeonDiv2::countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
	int sum = 0;
	for (int i = 0; i < doorR.size(); i++) {
		int k = keys[2];
		if (doorR[i] <= keys[0] && doorG[i] <= keys[1]) {
			sum++;
			continue;
		}
		if (doorR[i] > keys[0]) {
			if (k < (doorR[i] - keys[0]))
				continue;
			else
				k -= doorR[i] - keys[0];
		}
		if (doorG[i] > keys[1]) {
			if (k < doorG[i] - keys[1])
				continue;
			else
				k -= doorG[i] - keys[1];
		}
		if (k >= 0)
			sum++;
	}
	return sum;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

