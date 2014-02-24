/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        11995.cpp
*  Create Date: 2014-02-24 21:56:48
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define rep(i,n) for(int i=0;i<(n);i++)

stack<int> s;
queue<int> q;
priority_queue<int> pq;
bool iss, isq, ispq;
int n, o, a;

int main() {
	while (~RI(n)) {
		iss = isq = ispq = 1;
		while (!s.empty()) s.pop();
		while (!q.empty()) q.pop();
		while (!pq.empty()) pq.pop();

		rep (i, n) {
			RII(o, a);
			if (o == 1) {
				if (iss) s.push(a);
				if (isq) q.push(a);
				if (ispq) pq.push(a);
			}
			else {
				if (iss)
					if (s.empty() || s.top() != a) iss = 0; else s.pop();
				if (isq)
					if (q.empty() || q.front() != a) isq = 0; else q.pop();
				if (ispq)
					if (pq.empty() || pq.top() != a) ispq = 0; else pq.pop();
			}
		}
		a = iss + isq + ispq;
		if (a == 1) {
			if (iss) puts("stack");
			else if (isq) puts("queue");
			else puts("priority queue");
		}
		else if (a) puts("not sure");
		else puts("impossible");
	}
	return 0;
}

