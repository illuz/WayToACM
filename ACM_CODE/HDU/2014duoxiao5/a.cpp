#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[500005],b[1000005];

long long num;

void msort(int s, int t)
{
	int mid = (t+s)/2;
	int qb = 1, bn = t-s+1;
	int i,j;
	if (s>=t) return;
	msort(s,mid);
	msort(mid+1,t);
	for (i=s,j=mid+1; i<=mid && j<=t; )
	{
		if (a[i]<=a[j])
		{
			b[qb] = a[i];
			i++;
		}
		else
		{
			b[qb] = a[j];
			num += mid-i+1;
			j++;
		}
		qb++;
	}
	while(j<=t)
	{
		b[qb] = a[j];
		qb++;
		j++;
	}
	while(i<=mid)
	{
		b[qb] = a[i];
		qb++;
		i++;
	}
	for (i=1,j=s; i<qb; i++,j++)
	{
		a[j] = b[i];
	}
}
int main()
{
	int n,i, m;

	while(scanf("%d%d", &n, &m)!=EOF)
	{
		for (i=1; i<=n; i++)
			scanf("%d", &a[i]);
		num = 0;
		msort(1, n);
		cout << max((long long)0, num - m) << endl;
	}
	return 0;
}
