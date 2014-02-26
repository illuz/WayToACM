/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11997.cpp
*  Create Date: 2014-02-26 20:55:20
*  Descripton:   
*/

#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d",&x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

const int N = 760;

int arr[N][N];
int k, tot;

struct Item {
	int s, b;
	bool operator < (const Item & b) const {
		return s > b.s;
	}
};

void merge(int r) {
	priority_queue<Item> q;
	rep (i, k)
		q.push( (Item){arr[0][i] + arr[r][0], i} );
	rep (i, k) {
		Item tmp = q.top();
		q.pop();
		arr[0][i] = tmp.s;
		if (tmp.b < k) {
			tmp.s += arr[r][tmp.b + 1] - arr[r][tmp.b];
			tmp.b++;
			q.push(tmp);
		}
	}
}

int main() {
	while (~RI(k)) {
		rep (i, k) {
			rep (j, k) RI(arr[i][j]);
			sort (arr[i], arr[i] + k);
		}

		repf (i, 1, k - 1)
			merge(i);

		printf("%d", arr[0][0]);
		repf (i, 1, k - 1)
			printf(" %d", arr[0][i]);
		puts("");
	}
	return 0;
}

