/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1000.cpp
*  Create Date: 2014-07-22 19:52:43
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#include <cmath>
#include <cstdlib>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
using namespace std;
class InvariantSets {
public:
	int g[60][60];
	int fa[60];
	int find(int x) {
		if (fa[x] == x) return x;
		else return fa[x] = find(fa[x]);
	}

	long long countSets(vector <int> f) {
		for (int i = 0; i <= f.size(); i++)
			fa[i] = i;
		for (int i = 0; i < f.size(); i++) {
			g[i][f[i]]++;
			fa[find(i)] = find(f[i]);
		}
		int root = 0;
		for (int i = 0; i < f.size(); i++) {
			if (fa[i] == i) {
				root++;
			}
		}
	}
};

int main() {

	return 0;
}

