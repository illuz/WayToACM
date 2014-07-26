/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2089.cpp
*  Create Date: 2014-07-26 09:55:48
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)

const int N = 10;

int n, m;
int bits[N];
int dp[N][3];	// [len][x]
				// 0->luck
				// 1->luck and highest is 2
				// 2->unluck

void init() {
	dp[0][0] = 1;	// len is 0 and luck is 1, becauses the dp[1][1] will equal it.
	dp[0][1] = dp[0][1] = 0;

	repf(i, 1, N - 1) {

		dp[i][0] = dp[i - 1][0] * 9		// i-1_luck without 4
					- dp[i - 1][1];		// and without 62

		dp[i][1] = dp[i - 1][0];		// equal to i-1_luck_2 + '6'

		dp[i][2] = dp[i - 1][2] * 10	// unluck is always unluck
			+ dp[i - 1][0]				// i-1_luck + '4'
			+ dp[i - 1][1];				// i-1_luck_2 + '6'

	}
}

int solve(int num) {
	int len = 0, rec = num, ans, flag;

	// get bits array
	while (num) {
		bits[++len] = num % 10;
		num /= 10;
	}
	bits[len + 1] = 0;
	
	ans = 0;	// the unluck num
	flag = 0;	// if appear unluck 
	repd (i, len, 1) {
		ans += dp[i - 1][2] * bits[i];	// unluck is always unluck

		if (flag) {						// if unluck appeared
			ans += dp[i - 1][0] * bits[i];	// all luck become unluck
		} else {
			if (bits[i] > 4) {
				ans += dp[i - 1][0];	// i-1_luck + '4'
			}
			if (bits[i] > 6) {
				ans += dp[i - 1][1];	// i-1_luck_2 + '6'
			}
			if (bits[i + 1] == 6 && bits[i] > 2) {
				ans += dp[i][1];
			}
		}

		if (bits[i] == 4 || (bits[i + 1] == 6 && bits[i] == 2)) {
			flag = 1;
		}
	}

	return rec - ans;
}

int main() {
	init();
	while (~RII(n, m) && (n || m)) {
		PIN(solve(m + 1) - solve(n));
	}
	return 0;
}

