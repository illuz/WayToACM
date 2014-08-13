/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2.cpp
*  Create Date: 2014-08-08 10:22:16
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 2010;

struct P {
	ll v;
	int bi;
	bool operator <(const P b) const {
		return v > b.v;
	}
};

ll arr[3][N];
priority_queue<P> q;
bool vis[N][N];
int t, n, m;
ll rd;

// calc smallest n numbers of sorted a + b into a
void merge(int a, int b, int c) {
	while (!q.empty())
		q.pop();
	repf (i, 0, n - 1) {
		q.push((P){arr[a][i] + arr[b][0], 0});
	}
	repf (i, 0, n - 1) {
		ll v = q.top().v;
		int bi = q.top().bi;
		q.pop();
		arr[c][i] = v;
		if (bi + 1 < n) {
			q.push((P){v - arr[b][bi] + arr[b][bi+1], bi + 1});
		}
	}
	repf (i, 0, n - 1) {
		arr[a][i] = arr[c][i];
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		// read arr[0]
		repf (j, 0, n - 1) {
			scanf("%lld", &arr[0][j]);
		}
		sort(arr[0], arr[0] + n);

		repf (i, 1, m - 1) {
			repf (j, 0, n - 1) {
				scanf("%lld", &arr[1][j]);
			}
			sort(arr[1], arr[1] + n);
			merge(0, 1, 2);		// merge cur, pre to next arr
		}

		printf("%lld", arr[0][0]);
		repf (i, 1, n - 1) {
			printf(" %lld", arr[0][i]);
		}
		puts("");
	}
	return 0;
}

