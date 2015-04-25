/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        1.cpp
*  Create Date: 2015-04-25 14:07:18
*  Descripton:   
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 100010;

int t, n, q;
int op, x, y;
int ans;
vector<int> mp[N];
int fa[N];
int color[N];
bool vis[N];

int main() {
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            mp[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d%d", &x, &y);
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        memset(color, 0, sizeof(color));
        
        printf("Case #%d:\n", cas);

        ans = 1;
        scanf("%d", &q);
        for (int i = 0; i < q; ++i) {
            scanf("%d", &op);
            if (op == 1) {
                printf("%d\n", ans);
            } else {
                scanf("%d%d", &x, &y);
                if (color[x] == y)
                    continue;
                for (int v : mp[x]) {
                    if (color[v] == color[x])
                        ans++;
                    if (color[v] == y)
                        ans--;
                }
                color[x] = y;
            }
        }
    }
    return 0;
}

