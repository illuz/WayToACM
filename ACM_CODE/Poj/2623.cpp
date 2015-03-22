/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        2623.cpp
*  Create Date: 2015-03-22 09:50:03
*  Descripton:   
*/

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
    if (n & 1)
        printf("%.1f\n", num[n/2] * 1.0);
    else
        printf("%.1f\n", (num[n/2] * 1.0 + num[n/2-1] * 1.0) / 2.0);
    return 0;
}


