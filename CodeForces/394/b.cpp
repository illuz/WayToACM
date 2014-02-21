/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-02-21 16:47:20
*  Descripton:   
*/

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

vector<int> v;
int p, x, r, u;

int main() {
	cin>>p>>x;
	rep(i, 10) {
		r=i;u=0;
		rep(j,p){
			v.push_back(r);
			r=r*x+u;
			u=r/10;
			r=r%10;
		}
		if(r==i&&v[p-1]&&!u){rep(i,p)putchar(v[p-i-1]+48);return 0;}
		v.clear();
	}
	puts("Impossible");
	return 0;
}

