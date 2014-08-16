/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        C.cpp
*  Create Date: 2014-08-16 00:47:18
*  Descripton:   
*/

#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1110;

int a[N], sum;
int n, d, k, m[N][N];

void dfs(int x) {
    if(sum >= n)
		return;
    if(x >= d) {
        for (int i = 0; i < d; i++)
			m[i][sum] = a[i];
        sum++;
        return;
    }
    for(int i = 1; i <= min(k, 1001); i++) {
        a[x] = i;
        dfs(x + 1);
    }
}

int main() {
    while (~scanf("%d%d%d", &n, &k, &d)) {
        memset(m, 0, sizeof(m));
        sum = 0;
        dfs(0);
        if(sum < n)
			puts("-1");
        else {
            for(int i = 0; i < d; i++) {
                for(int j = 0; j < n; j++)
					printf("%d ", m[i][j]);
                puts("");
            }
        }
    }
    return 0;
}
