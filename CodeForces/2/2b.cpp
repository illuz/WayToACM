/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2b.cpp
*  Create Date: 2014-01-11 10:17:43
*  Descripton:   
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1010;

// [0] -> 2, [1] -> 5
int d[MAXN][MAXN][2];	// dp
int r[MAXN][MAXN][2];	// record the init dp
int p[MAXN][MAXN][2];	// path
int n, x, y, t;
vector<pair<int, int> > z;	// zero pos

int calc2(int x) {
	int n = 0;
	while (x >= 2 && x % 2 == 0) {
		x /= 2;
		n++;
	}
	return n;
}

int calc5(int x) {
	int n = 0;
	while (x >= 5 && x % 5 == 0) {
		x /= 5;
		n++;
	}
	return n;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			if (t == 0)
				z.push_back(make_pair(i, j));
			d[i][j][0] = calc2(t);
			d[i][j][1] = calc5(t);
		}
	// pre
	for (int i = n - 2; i >= 0; i--) {
		d[n - 1][i][0] += d[n - 1][i + 1][0];
		d[n - 1][i][1] += d[n - 1][i + 1][1];
		d[i][n - 1][0] += d[i + 1][n - 1][0];
		p[i][n - 1][0] = 1;
		d[i][n - 1][1] += d[i + 1][n - 1][1];
		p[i][n - 1][1] = 1;
	}
	memcpy(r, d, sizeof(d));
	// dp 2
	for (int i = n - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--) {
			if (d[i + 1][j][0] > d[i][j + 1][0])
				d[i][j][0] += d[i][j + 1][0], p[i][j][0] = 0;
			else
				d[i][j][0] += d[i + 1][j][0], p[i][j][0] = 1; 
		}
	// dp 5
	for (int i = n - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--) {
			if (d[i + 1][j][1] > d[i][j + 1][1])
				d[i][j][1] += d[i][j + 1][1], p[i][j][1] = 0;
			else
				d[i][j][1] += d[i + 1][j][1], p[i][j][1] = 1; 
		}
	// cout << d[0][0][0] << ' ' << d[0][0][1] << endl;

	// replace 0 with 10
	int len = z.size();
	if (len) {
		for (int i = 0; i < len; i++) {
			r[z[i].first][z[i].second][0] = 10;
			r[z[i].first][z[i].second][1] = 10;
		}
		// rp 2 without 0
		for (int i = n - 2; i >= 0; i--)
			for (int j = n - 2; j >= 0; j--) {
				if (r[i + 1][j][0] > r[i][j + 1][0])
					r[i][j][0] += r[i][j + 1][0];
				else
					r[i][j][0] += r[i + 1][j][0]; 
			}
		// rp 5 without 0
		for (int i = n - 2; i >= 0; i--)
			for (int j = n - 2; j >= 0; j--) {
				if (r[i + 1][j][1] > r[i][j + 1][1])
					r[i][j][1] += r[i][j + 1][1];
				else
					r[i][j][1] += r[i + 1][j][1]; 
			}
		if (min(r[0][0][0], r[0][0][1]) > 0) {
			puts("1");
			x = z[0].first;
			for (int i = 0; i < x; i++) printf("D");
			for (int i = 0; i < n - 1; i++) printf("R");
			for (int i = x; i < n - 1; i++) printf("D");
			puts("");
			return 0;
		}
		else {
			puts("0");
			if (d[0][0][0] < d[0][0][1]) t = 0;
			else t = 1;
			for (int i = 0; i < 2 * n - 2; i++)
				if (p[x][y][t]) {
					printf("D");
					x += 1;
				}
				else {
					printf("R");
					y += 1;
				}
			puts("");
			return 0;
		}
	}

	if (d[0][0][0] < d[0][0][1]) {
		printf("%d\n", d[0][0][0]);
		t = 0;
	}
	else {
		printf("%d\n", d[0][0][1]);
		t = 1;
	}
	// output path
	for (int i = 0; i < 2 * n - 2; i++)
		if (p[x][y][t]) {
			printf("D");
			x += 1;
		}
		else {
			printf("R");
			y += 1;
		}
	puts("");
	return 0;
}

