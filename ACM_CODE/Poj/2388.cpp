/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2388.cpp
*  Create Date: 2015-03-22 09:34:33
*  Descripton:  Find the middle num.
*/

// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
int n, t;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    printf("%d\n", num[n/2]);
    return 0;
}

