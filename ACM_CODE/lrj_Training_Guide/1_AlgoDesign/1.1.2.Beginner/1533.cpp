/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1533.cpp
*  Create Date: 2014-07-05 20:47:03
*  Descripton:  bfs + hash 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int N = 16;
const int next[15][6] = {
	{-1, -1, -1, -1, 2, 3}, {-1, 1, -1, 3, 4, 5}, {1, -1, 2, -1, 5, 6}, 
	{-1, 2, -1, 5, 7, 8}, {2, 3, 4, 6, 8, 9}, {3, -1, 5, -1, 9, 10}, 
	{-1, 4, -1, 8, 11, 12}, {4, 5, 7, 9, 12, 13}, {5, 6, 8, 10, 13, 14}, 
	{6, -1, 9, -1, 14, 15}, {-1, 7, -1, 12, -1, -1}, {7, 8, 11, 13, -1, -1}, 
	{8, 9, 12, 14, -1, -1}, {9, 10, 13, 15, -1, -1}, {10, -1, 14, -1, -1, -1}
};

struct Statue {
	int st;
	int num;
	int way[2][N];
	int cnt;
	Statue(int _st = (1<<16) - 1, int _num = 15) {
		st = _st;
		num = _num;
		cnt = 0;
	}
};

queue<Statue> q;
set<int> s;

int t, n;

bool bfs(int n) {

	// init
	s.clear();
	while (!q.empty()) {
		q.pop();
	}

	// bfs
	q.push(Statue(((1<<16)-1)^(1<<(n-1)), 14));

	while (!q.empty()) {
		Statue tmp = q.front();
		q.pop();

		for (int i = 0; i < 15; i++) {		// for every point
			if ((tmp.st>>i)&1) {			// if the point is black
				for (int j = 0; j < 6; j++) {	// for every direction
					if (next[i][j] != -1 && ((tmp.st>>(next[i][j]-1))&1)) {	// if there is a black
						int tt = i, rec;
						Statue cp = tmp;
						cp.num++;
						while (tt >= 0 && (cp.st>>tt)&1) {			// go to the straight black
							cp.st -= (1<<tt);
							cp.num--;
							tt = next[tt][j] - 1;
						}
						if (tt < 0) {
							continue;
						}
						cp.st |= (1<<tt);
						if (!s.count(cp.st)) {			// if not duplicate then push
							s.insert(cp.st);
							cp.way[0][cp.cnt] = i + 1;
							cp.way[1][cp.cnt] = tt + 1;
							cp.cnt++;
							if (cp.num == 1 && (cp.st>>(n-1))&1) {
								printf("%d\n%d %d", cp.cnt, cp.way[0][0], cp.way[1][0]);
								for (int i = 1; i < cp.cnt; i++) {
									printf(" %d %d", cp.way[0][i], cp.way[1][i]);
								}
								puts("");
								return 0;
							}
							q.push(cp);
						}
					}
				}
			}
		}
	}
	puts("IMPOSSIBLE");
	return false;
}


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		bfs(n);
	}
	return 0;
}

