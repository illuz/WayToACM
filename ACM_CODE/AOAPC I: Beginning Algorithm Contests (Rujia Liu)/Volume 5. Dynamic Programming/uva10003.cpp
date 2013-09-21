/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        uva10003.cpp
*  Create Date: 2013-09-20 15:27:56
*  Descripton:  greedy test , WRONG ANSWER
*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main() {
	int n, p, t, len;
	while (scanf("%d", &len) && len) {
		while (!q.empty()) q.pop();
		scanf("%d", &n);
		p = 0;
		while (n--) {
			scanf("%d", &t);
			q.push(t - p);
			p = t;
		}
		q.push(len - t);
		int sum = 0;
		while (1) {
			int a = q.top();
			q.pop();
			if (q.empty()) {
				printf("The minimum cutting is %d.\n", sum);
				break;
			}
			int b = q.top();
			q.pop();
			sum += a + b;
			q.push(a + b);
		}
	}
	return 0;
}

