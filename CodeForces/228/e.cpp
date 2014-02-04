/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        e.cpp
*  Create Date: 2014-02-04 15:56:49
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d",&x)
#define rep(i,n) for(int i=0;i<(n);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)

const int N = 110;
int n, m, t, a, b, mid[N], c;

int main() {
	RI(n);
	rep(i, n) {
		RI(m);
		rep(i, m) {
		   	RI(t);
			if (m&1 && i==m>>1) { mid[c++]=t; continue; }
			if (i<m>>1) a+=t; else b+=t;
		}
	}
	sort(mid,mid+c);
	int f = 0;
	repd(i,c-1,0)
		if (1&++f) a+=mid[i];
		else b+=mid[i];
	printf("%d %d",a,b);
	return 0;
}

