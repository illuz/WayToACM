/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        Matrix.cpp
*  Create Date: 2014-07-31 10:35:19
*  Descripton:  Matrix template 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>
#include <cstdlib>
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

const int N = 10;

// 1. change N
struct Matrix {
	int n;			// n*n matrix
	int v[N][N];	// value of matrix

	Matrix(int _v = 1) {
		init();
		repf (i, 0, N)
			v[i][i] = _v;
	}

	void init() {
		memset(v, 0, sizeof(v));
	}

	Matrix operator * (const Matrix &b) const {
		Matrix c;
		c.init();
		repf (i, 0, cnt - 1)
			rpef (j, 0, cnt - 1)
				repf (k, 0, cnt - 1)
					c.v[i][j] = (c.v[i][j] + (v[i][k] * b.v[k][j]) % MOD) % MOD;
		return c;
	}

	Matrix operator ^ (ll b) {
		Matrix a = *this, res(1);
		while (b) {
			if (b&1)
				res = res * a;
			a = a * a;
			b >>= 1;
		}
		return res;
	}
};

int main() {

	return 0;
}

