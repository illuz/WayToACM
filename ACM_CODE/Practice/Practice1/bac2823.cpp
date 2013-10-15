#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

const int MAXN = 1000005;
int n, k, t;

struct Num {
	int val;
	int ind;
} arr[MAXN];

void Max() {
	deque<Num> d;
	d.push_front(arr[0]);
	if (k == 1) printf("%d ", arr[0].val);
	for (int i = 1; i < n; i++) {
		while (!d.empty() && d.back().val < arr[i].val)
			d.pop_back();
		d.push_back(arr[i]);
		while (!d.empty() && d.front().ind < i - k + 1)
			d.pop_front();
		if (i >= k - 1)
			if (i == n - 1) printf("%d\n", d.front().val);
			else printf("%d ", d.front().val);
	}
}

void Min() {
	deque<Num> d;
	d.push_front(arr[0]);
	if (k == 1) printf("%d ", arr[0].val);
	for (int i = 1; i < n; i++) {
		while (!d.empty() && d.back().val > arr[i].val)
			d.pop_back();
		d.push_back(arr[i]);
		while (!d.empty() && d.front().ind < i - k + 1)
			d.pop_front();
		if (i >= k - 1)
			if (i == n - 1) printf("%d\n", d.front().val);
			else printf("%d ", d.front().val);
	}
}

int main() {
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			arr[i].val = t;
			arr[i].ind = i;
		}
		Min();
		Max();
	}
	return 0;
}
