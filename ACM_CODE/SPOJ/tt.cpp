#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50;

ll dp[maxn][maxn][2];
char num[maxn];
int tmp[maxn];

//cur：当前位数，start：镜像回文判断的开始地方，flag：是否是镜像回文，limit：边界判断
ll dfs(int cur, int start, bool flag, bool limit) {
	if (cur == -1)
		return flag;
	if (!limit && dp[cur][start][flag] != -1)
		return dp[cur][start][flag];
	ll ans = 0;
	int end = limit?(num[cur]-48):9;
	for (int i = 0; i <= end; i++) {
		if (i == 0 || i == 1 || i == 8) {
			bool st = (cur==start && i == 0); //判断是否是0情况
			bool newFlag = flag;
			if (flag) {
				if (!st && cur < (start+1)/2)
					newFlag = (tmp[start-cur] == i);
			}
			tmp[cur] = i;
			ans += dfs(cur-1, st?start-1:start, newFlag, limit&&(i==end));
		}
	}
	if (!limit)
		dp[cur][start][flag] = ans;
	return ans;
}

ll cal(char str[])  {
	int len = strlen(str);	
	for (int i = 0; i < len; i++)
		num[i] = str[len-1-i];
	num[len] = 0;
	return dfs(len-1, len-1, 1, 1);
}

int main() {
	int t;
	char a[maxn], b[maxn];
	scanf("%d", &t);
	getchar();
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%s %s", a, b);
		ll ans = cal(b) - cal(a);
		int len = strlen(a);
		bool flag = true;
		for (int i = 0; i < len; i++)
			if ((a[i] != '0' && a[i] != '1' && a[i] != '8') || (a[i] != a[len-1-i])) {
				flag = false;
				break;
			}
		if (flag)
			ans++;
		printf("%lld\n", ans);
	}
	return 0;
}