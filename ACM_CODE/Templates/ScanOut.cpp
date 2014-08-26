/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        Scan.cpp
*  Create Date: 2014-08-05 20:41:07
*  Descripton:   
*/

#include <bits/stdc++.h>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

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

void Out(int a) {
    if(a > 9)
        Out(a / 10);
    putchar(a % 10 + '0');
}

const int N = 0;

int main() {

	return 0;
}

