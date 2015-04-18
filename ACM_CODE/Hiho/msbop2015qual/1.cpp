/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1.cpp
*  Create Date: 2015-04-18 09:19:33
*  Descripton:   
*/

// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int t;
int ay, ad, by, bd;
string str;
map<string, int> m;

void pre() {
    m["January"] = 1;
    m["February"] = 2;
    m["March"] = 3;
    m["April"] = 4;
    m["May"] = 5;
    m["June"] = 6;
    m["July"] = 7;
    m["August"] = 8;
    m["September"] = 9;
    m["October"] = 10;
    m["November" ] = 11;
    m["December"] = 12;
}

inline bool check(int y) {
    return (y%4==0 && y%100 != 0) || (y%400 == 0);
}

int main() {
    pre();
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        int ans = 0;
        
        cin >> str;
        scanf("%d, %d", &ad, &ay);
        ad += m[str] * 100;

        cin >> str;
        scanf("%d, %d", &bd, &by);
        bd += m[str] * 100;

        if (ay == by) {
            if (check(ay) && ad <= 229 && bd >= 229)
                ans++;
        } else {
            if (ad > 229)
                ++ay;
            while (!check(ay))
                ++ay;
            if (bd < 229)
                --by;
            while (!check(by))
                --by;

            int cnt = max(0, (by - ay) / 400);
            ans += cnt * 97;
            ay += cnt * 400;
            for (int i = ay; i <= by; ++i)
                if (check(i))
                    ans++;
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}

