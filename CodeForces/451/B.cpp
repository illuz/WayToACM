/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        B.cpp
*  Create Date: 2014-07-24 23:49:35
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n, beg, end, flag;
int a[N], b[N];
bool cont;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}

	sort(b, b + n);
	beg = 0;
	end = n - 1;
	while (beg < n && a[beg] == b[beg])
		beg++;
	while (end >= 0 && a[end] == b[end])
		end--;
	if (beg == n) {
		printf("yes\n");
		printf("1 1\n");
		return 0;
	}
	flag = true;
	for (int i = 0; i <= end - beg; i++) {
//		cout << b[beg + i] << ' ' << a[end - i] << endl;
		if (b[beg + i] != a[end - i]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("yes\n");
		printf("%d %d\n", beg + 1, end + 1);
	} else {
		printf("no\n");
	}

	return 0;
}

