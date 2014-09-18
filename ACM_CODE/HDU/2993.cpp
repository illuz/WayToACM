/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2993.cpp
*  Create Date: 2014-09-17 23:56:17
*  Descripton:  dp
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 1e5 + 5;

ll sum[N];
int q[N], front, rear;
int n, k;

inline bool check(int a, int b, int c) {
	return (sum[c] - sum[b]) * (b - a) <= (sum[b] - sum[a]) * (c - b);
}

int Scan() {
	int res = 0, ch, flag = 0;
	if((ch = getchar()) == '-')
		flag = 1;
	else if(ch >= '0' && ch <= '9')
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}

int main() {
	while (~scanf("%d%d", &n, &k)) {
		repf (i, 1, n) {
			sum[i] = sum[i - 1] + Scan();
		}
		
		front = 0;
		rear = -1;
		double ans = 0;
		repf (i, k, n) {
			while (front < rear && check(q[rear - 1], q[rear], i - k))
				rear--;
			q[++rear] = i - k;
			while (front < rear && check(q[front + 1], q[front], i))
				front++;
			ans = max(ans, (sum[i] - sum[q[front]]) * 1. / (i - q[front]));
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

