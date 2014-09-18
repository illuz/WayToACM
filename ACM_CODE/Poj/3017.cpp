/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3017.cpp
*  Create Date: 2014-09-17 21:41:41
*  Descripton:  dp 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1e5+10;

ll n, m, arr[N], sum[N];
ll dp[N], q[N];
int front, rear;

int main() {
	ios_base::sync_with_stdio(0);

	while (cin >> n >> m) {
		sum[0] = 0;
		repf (i, 1, n) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		front = rear = 1;
		q[rear] = 1;
		bool flag = arr[1] > m;
		int t = 0;
		dp[0] = 0;
		dp[1] = arr[1];
		repf (i, 2, n) {
			while (i > t && sum[i] - sum[t] > m)
				t++;
			if (i == t) {
				flag = 1;
				break;
			}
			while (front <= rear && arr[i] >= arr[q[rear]])
				rear--;
			q[++rear] = i;
			while (front <= rear && sum[i] - sum[q[front] - 1] > m)
				front++;
			dp[i] = dp[t] + arr[q[front]];
			repf (j, front, rear - 1)
				dp[i] = min(dp[i], dp[q[j]] + arr[q[j + 1]]);
		}
		cout << (flag ? -1 : dp[n]) << endl;
	}
	return 0;
}

