/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2752.cpp
*  Create Date: 2015-03-29 00:11:10
*  Descripton:  KMP
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 400010;

char p[N];
int f[N];

void getVal(int l) {
    int i = 0, j = -1;
    f[0] = -1;
    while (i < 1) {
        if (j == 1 || p[i] == p[j]) {
            ++i;
            ++j;
            f[i] = j;
        } else {
            j = f[j];
        }
    }
}

int main() {
    while (~scanf("%s", &p)) {
        int len = strlen(p);
        getVal(len);
        for (int i = 0; i < 
    }
    return 0;
}

