/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        10.cpp
*  Create Date: 2014-08-05 16:27:58
*  Descripton:   
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 805;

int a[N][N], b[N][N], c[N][N];
int n;

int Scan() {
	int res = 0, ch, flag = 0;
	if((ch = getchar()) == '-')				//判断正负
		flag = 1;
	else if(ch >= '0' && ch <= '9')			//得到完整的数
		res = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';
	return flag ? -res : res;
}

int main() {
	while (~scanf("%d", &n)) {
		repf (i, 1, n) 
			repf (j, 1, n) {
				a[i][j] = Scan() % 3;
				c[i][j] = 0;
			}
		repf (i, 1, n) 
			repf (j, 1, n) {
				b[i][j] = Scan() % 3;
			}
		repf (k, 1, n) {
			repf (i, 1, n) {
				if (a[i][k]) {
					repf (j, 1, n) {
						c[i][j] += a[i][k] * b[k][j];
					}
				}
			}
		}
		repf (i, 1, n) {
			repf (j, 1, n) {
				if (j != 1) printf(" ");
				printf("%d", c[i][j] % 3);
			}
			printf("\n");
		}
	}
	return 0;
}

