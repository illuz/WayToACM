/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        225.cpp
*  Create Date: 2014-07-08 09:55:44
*  Descripton:  brute force/ dfs 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> PII;
#define fi first
#define sd second
#define MP(x,y) make_pair(x,y)
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
const char trans[] = {'n','s','e','w'};
const int N = 60;

int t, n, k;
int tx, ty;
set<PII> vis, block;
string path;
vector<string> res;

bool check(int x, int y, int dir, int num) {
	if (dx[dir]) {
		while (num--) {
			x += dx[dir];
			if (block.count(MP(x, y)) || vis.count(MP(x, y))) {
				return false;
			}
		}
	} else {
		while (num--) {
			y += dy[dir];
			if (block.count(MP(x, y)) || vis.count(MP(x, y))) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int x, int y, int dir, int num) {
	if (abs(x) > n || abs(y) > n) {
		return;
	}
	if (num == n + 1) {
		if (x == 0 && y == 0) {
			res.push_back(path);
		}
		return;
	}

	int tx, ty;

	if (dir == -1) {	// if dir is -1, then go to 4 directions
		for (int i = 0; i < 4; i++) {
			if (!check(x, y, i, num))
				continue;
			path[num] = trans[i];
			tx = x + dx[i] * num;
			ty = y + dy[i] * num;
			vis.insert(MP(tx, ty));
			dfs(tx, ty, i, num + 1);
			vis.erase(MP(tx, ty));
		}
		return;
	}

	// go to the left or right
	int d1, d2;
	if (dir == 0 || dir == 1) {
		d1 = 2;
		d2 = 3;
	} else {
		d1 = 0;
	  	d2 = 1;
	}
	tx = x + dx[d1] * num;
	ty = y + dy[d1] * num;
	if (check(x, y, d1, num)) {
		path[num] = trans[d1];
		vis.insert(MP(tx, ty));
		dfs(tx, ty, d1, num + 1);
		vis.erase(MP(tx, ty));
	}

	tx = x + dx[d2] * num;
	ty = y + dy[d2] * num;
	if (check(x, y, d2, num)) {
		path[num] = trans[d2];
		vis.insert(MP(tx, ty));
		dfs(tx, ty, d2, num + 1);
		vis.erase(MP(tx, ty));
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		// init
		vis.clear();
		block.clear();
		res.clear();

		// read
		scanf("%d%d", &n, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", &tx, &ty);
			block.insert(MP(tx, ty));
		}

		path.resize(n + 1);
		dfs(0, 0, -1, 1);
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << endl;
		}
		printf("Found %d golygon(s).\n\n", res.size());
	}
	return 0;
}

