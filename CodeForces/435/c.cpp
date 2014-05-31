/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-05-31 00:22:36
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;

int n, a, cx, cy, num[N * 2], up, down;
char m[N * 2][N];

int main()
{
	scanf("%d", &n);
	cx = N;
  	cy = 0;
	up = down = N;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i % 2 == 0) {
			while (a--) {
				m[cx][cy] = '/';
				num[cx] = cy + 1;
				cx--;
				cy++;
			}
			cx++;
			up = max(cx, up);
			down = min(cx, down);
		} else {
			while (a--) {
				m[cx][cy] = '\\';
				num[cx] = cy + 1;
				cx++;
				cy++;
			}
			cx--;
			up = max(cx, up);
			down = min(cx, down);
		}
	}

	// find the most left
	int left = 0;
	for (int i = down; i <= up; i++)
		left = max(left, num[i]);

	// Output
	for (int i = down; i <= up; i++) {
		if (num[i] != 0) {
			for (int j = 0; j < left; j++)
				if (m[i][j] == 0)
					putchar(' ');
				else
					putchar(m[i][j]);
			if (i != up)
				puts ("");
		}
	}

	return 0;
}

