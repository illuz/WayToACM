#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int main()
{
	char ch, tmp = 0;
	long n, a, b, d[maxn] = {0};
	int i = 1;
	scanf("%c", &tmp);
	while (scanf("%c", &ch))
	{
		if (ch == tmp)
			d[i] = d[i - 1] + 1;
		else
			d[i] = d[i - 1];
		i++;
		tmp = ch;
		if (ch == '\n')
			break;
	}
	scanf("%ld", &n);
	while (n--)
	{
		scanf("%ld%ld", &a, &b);
		cout << d[b - 1] - d[a - 1] << endl;
	}
	return 0;
}
