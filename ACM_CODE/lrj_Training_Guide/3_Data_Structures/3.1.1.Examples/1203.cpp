/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1203.cpp
*  Create Date: 2014-02-24 23:15:36
*  Descripton:   
*/

#include <cstdio>
#include <queue>
using namespace std;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define PIN(x) printf("%d\n",x)
#define rep(i,n) for(int i=0;i<(n);i++)

const int N = 1001;

struct Elem {
	int step;
	int num;
	int cur;
	bool operator < (const Elem & b) const {
		return cur > b.cur || (cur == b.cur && num > b.num);
	}
} tmp;

priority_queue<Elem> range;
char ch[10];
int q, p, n;

int main() {
	while (!range.empty()) range.pop();
	while (scanf("%s", ch) && ch[0] != '#') {
		RII(q, p);
		range.push((Elem){p, q, p});
	}
	RI(n);
	rep (i, n) {
		tmp = range.top();
		range.pop();
		PIN(tmp.num);
		tmp.cur += tmp.step;
		range.push(tmp);
	}
	return 0;
}

