#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int MAXN = 1000005;
int n, k, t, arr[MAXN], que[MAXN];

void solve(bool flag) {
	int head(0), rear(0);
	memset(que, 0, sizeof(que));
	if (k == 1) printf("%d ", arr[0]);
	for (int i = 1; i < n; i++) {
		if (flag) while (head <= rear && arr[i] > arr[que[rear]])
			rear--;
		else while (head <= rear && arr[i] < arr[que[rear]])
			rear--;
		que[++rear] = i;
		if (que[head] < i - k + 1) head++;
		if (i >= k - 1)
			if (i == n - 1) printf("%d\n", arr[que[head]]);
			else printf("%d ", arr[que[head]]);
	}
}

int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		solve(0);
		solve(1);
	}
	return 0;
}
