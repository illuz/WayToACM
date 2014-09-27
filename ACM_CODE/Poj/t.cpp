/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        t.cpp
*  Create Date: 2014-09-26 14:06:41
*  Descripton:   
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;

int p[205],d[205];
int dp[21][805],path[21][805];
int ans[21];
int n,m,N;

void init() {
	memset(dp,-1,sizeof(dp));
	memset(path,0,sizeof(path));
	N=m*20;
	dp[0][N]=0;
}

void dp_work() {
	int i,j,k,t1,t2,t3;
	for(i=0;i < m; i++) {
		for(j=0;j<=N*2;++j) {
			if(dp[i][j]>=0) {
				for(k=1;k<=n;++k) {
					if(dp[i][j]+p[k]+d[k]>dp[i+1][j+p[k]-d[k]]) {
						t1=i;t2=j;
						while(t1>0 && path[t1][t2]!=k) {
							t3=path[t1][t2];
							t2-=p[t3]-d[t3];
							t1--;
						}
						if(t1==0) {
							dp[i+1][j+p[k]-d[k]]=dp[i][j]+p[k]+d[k];
							path[i+1][j+p[k]-d[k]]=k;
						}
					}
				}
			}
		}
	}
}

int main() {
	int i,j,k,pans,dans,ca=1;
	while(scanf("%d %d",&n,&m),(n||m)) {
		init();
		for(i=1;i<=n;++i)
			scanf("%d %d",&p[i],&d[i]);
		dp_work();
		i=0;
		while(dp[m][N-i]<0 && dp[m][N+i]<0)
			i++;

		if(dp[m][N+i]>dp[m][N-i])
			k=N+i;
		else
			k=N-i;

		pans=(dp[m][k]+k-N)/2;
		dans=(dp[m][k]-k+N)/2;
		printf("Jury #%d\n",ca++);
		printf("Best jury has value %d for prosecution and value %d for defence:\n",pans,dans);

		for(i=0;i < m; i++)
		{
			ans[i]=path[m-i][k];
			k-=p[ans[i]]-d[ans[i]];
		}

		sort(ans,ans+m);

		for(i=0;i < m; i++)
			printf(" %d",ans[i]);
		printf("\n\n");
	}
	return 0;
}
