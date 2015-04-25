/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        3.cpp
*  Create Date: 2015-04-25 14:30:50
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1010;
const int M = 500010;
const int INF = 0x3f3f3f3f;

int t;
int n, ans;
int s[N];
int prm[M];

// template begin
bool mp[N][N], mask[N];
int nx, ny, dis;
int cx[N], cy[N];
int dx[N], dy[N];

bool SearchPath() {
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for(int i = 0; i < nx; i++) {
        if(cx[i] == -1) {
            Q.push(i);
            dx[i] = 0;
        }
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(dx[u] > dis) break;
        for(int v = 0; v < ny; v++) {
            if(mp[u][v] && dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if(cy[v] == -1) dis = dy[v];
                else {
                    dx[cy[v]] = dy[v] + 1;
                    Q.push(cy[v]);
                }
            }
        }
    }
    return dis != INF;
}

bool FindPath(int u) {
    for(int v = 0; v < ny; v++) {
        if(!mask[v] && mp[u][v] && dy[v] == dx[u] + 1) {
            mask[v] = 1;
            if(cy[v] != -1 && dy[v] == dis)
                continue;
            if(cy[v] == -1 || FindPath(cy[v])) {
                cy[v] = u; cx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int Match() {
    int res = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    while(SearchPath()) {
        memset(mask, 0, sizeof(mask));
        for(int i = 0; i < nx; i++) {
            if(cx[i] == -1)
                res += FindPath(i);
        }
    }
    return res;
}

// template end

void pre() {
    prm[0] = prm[1] = 1;
    for (int i = 2; i < M; i++) {
        if (i * i >= M) break;
        for (int j = i * i; j < M; j += i)
            prm[j] = 1;
    }
}

int main() {
    pre();

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &s[i]);
        }
        sort(s, s + n);

        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[j] % s[i] == 0 && prm[s[j] / s[i]] == 0)
                    mp[i][j] = mp[j][i] = 1;
            }
        }
        nx = ny = n;

        printf("Case #%d: %d\n", cas, n - Match() / 2);
    }
    return 0;
}

