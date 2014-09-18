/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3401.cpp
*  Create Date: 2014-09-17 00:08:25
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 2010;

int ap[N], bp[N], as[N], bs[N];
int t, T, P, W, ans, front, rear, pre;
int f[N][N];
int q[2][N<<1];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> T >> P >> W;
		repf (i, 1, T)
			cin >> ap[i] >> bp[i] >> as[i] >> bs[i];
		memset(f, -0x7f, sizeof(f));

		repf (i, 1, W + 1) {
			repf (j, 0, as[i])
				f[i][j] = -j * ap[i];
		}

		repf (i, 1, W + 1) {
			repf (j, 0, P)
				f[i][j] = max(f[i][j], f[i - 1][j]);
		}

		repf (i, W + 2, T) {
			pre = i - W - 1;
			// do nothing
			repf (j, 0, P)
				f[i][j] = max(f[i][j], f[i - 1][j]);
			// buy
			front = rear = 0;
			q[0][rear] = f[pre][0];
			q[1][rear++] = 0;
			repf (j, 1, P) {
				while (front < rear && q[1][front] < j - as[i])
					front++;
				f[i][j] = max(f[i][j], q[0][front] - j * ap[i]);
				while (front < rear && q[0][rear - 1] <= f[pre][j] + j * ap[i])
					rear--;
				q[0][rear] = f[pre][j] + j * ap[i];
				q[1][rear++] = j;
			}
			// sell
			front = rear = 0;
			q[0][rear] = f[pre][P] + P * bp[i];
			q[1][rear++] = P;
			for (int j = P - 1; j >= 0; j--) {
				while (front < rear && q[1][front] > j + bs[i])
					front++;
				f[i][j] = max(f[i][j], q[0][front] - j * bp[i]);
				while (front < rear && q[0][rear - 1] <= f[pre][j] + j * bp[i])
					rear--;
				q[0][rear] = f[pre][j] + j * bp[i];
				q[1][rear++] = j;
			}
		}
		ans = 0;
		repf (i, 0, P)
			ans = max(ans, f[T][i]);
		printf("%d\n", ans);
	}
	return 0;
}

