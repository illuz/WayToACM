#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
#define ll long long
#define int64 __int64
#define M 50005
#define N 1005
#define inf 1000010
#define mod 1000000009

int dig[25] , num[25];
ll dp[25][25][2];

ll Dfs(int index , int len , int fg , int lim)
{
	if (!index) return 1;
	if (!lim && dp[index][len][fg] != -1)return dp[index][len][fg];
	int i , up = lim ? dig[index] : 9;
	ll ret = 0;
	for (i = 0 ; i <= up ; i++)
	{
		if (!fg)//若之前一直未出现过非零位，则长度不定
		{
			num[index] = i;
			//若传递下去的i==0，则长度继续减小
			ret += Dfs(index-1 , len-!i , fg||i , lim&&i==up);
		}
		else//长度已定的情况下，则判断当前位在对称轴的哪边
		{
			int temp = (len+1)>>1;

			//由于数字奇偶不同做出的判断不同，所以需要分开写条件
			bool condition = len&1 ? index < temp : index <= temp;

			if(condition)
			{
				if (num[len+1-index] == i)
					ret += Dfs(index-1 , len , fg , lim&&i==up);
			}
			else
			{
				num[index] = i;
				ret += Dfs(index-1 , len , fg , lim&&i==up);
			}
		}
	}
	if (!lim)dp[index][len][fg] = ret;
	return ret;
}

ll Solve(ll k)
{
	int len = 0;
	while (k)
	{
		dig[++len] = k%10;
		k /= 10;
	}
	return Dfs(len,len,0,1);
}

int main()
{
	ll x , y;
	int t , tcase = 1;
	scanf("%d",&t);
	memset(dp , -1 , sizeof dp);
	while (t--)
	{
		scanf("%lld%lld",&x,&y);
		if (x > y)swap(x,y);
		printf("Case %d: %lld\n",tcase++,Solve(y)-Solve(x-1));
	}
	return 0;
}