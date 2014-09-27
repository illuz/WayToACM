#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
   int to,next, id;
}e[100010];

int n,num,pre[50010];
int pos[50010],idx;
int b[100010],f[100010];
int dp_min[100010][25];
int val[50010],up[50010];

void addedge(int x,int y) {
   num++;
   e[num].to=y;e[num].next=pre[x];
   pre[x]=num;
}

void dfs(int k,int deep)
{
   b[++idx]=deep;
   f[idx]=k;
   pos[k]=idx;
   for (int i=pre[k];i!=0;i=e[i].next)
   if (pos[e[i].to]==0)
   {
      dfs(e[i].to,deep+1);
	  b[++idx]=deep;
	  f[idx]=k;
   }
}
void build_RMQ()
{
   for (int i=1;i<=idx;i++)
	   dp_min[i][0]=i;
   for (int j=1;(1<<j)<=idx;j++)
   for (int i=0;i+(1<<j)-1<=idx;i++)
   if (b[dp_min[i][j-1]]<b[dp_min[i+(1<<(j-1))][j-1]])
	   dp_min[i][j]=dp_min[i][j-1];
   else
	   dp_min[i][j]=dp_min[i+(1<<(j-1))][j-1];
}
int query(int i,int j)
{
   int d=(j-i+1),k;
   for (k=0;(1<<k)<=d;k++);
   k--;
   if (b[dp_min[i][k]]<b[dp_min[j-(1<<k)+1][k]])
		return dp_min[i][k];
	else
		return dp_min[j-(1<<k)+1][k];
}
int get_LCA(int x,int y)
{
   if (pos[x]<pos[y])
	   return f[query(pos[x],pos[y])];
   else
	   return f[query(pos[y],pos[x])];
}
void calc(int k,int d)
{
   for (int i=pre[k];i!=0;i=e[i].next)
   if (e[i].to!=d)
   {
      calc(e[i].to,k);
	  val[k]+=up[e[i].to];  
   }
   up[k]+=val[k];
}

void calc2(int k,int d)
{
   for (int i=pre[k];i!=0;i=e[i].next)
   if (e[i].to!=d)
   {
      calc2(e[i].to,k);
	  val2[k]+=up[e[i].to];  
   }
   up[k]+=val2[k];
}
void calc3(int k,int d)
{
   for (int i=pre[k];i!=0;i=e[i].next)
   if (e[i].to!=d)
   {
      calc3(e[i].to,k);
	  val3[k]+=up[e[i].to];  
   }
   up[k]+=val3[k];
}

int main()
{
   int test;
   scanf("%d",&test);
   for (int ii=1;ii<=test;ii++)
   {
      scanf("%d",&n);
	  for (int i=0;i<n;i++) up[i]=val[i]=pos[i]=pre[i]=0;
	  idx=num=0;
	  for (int i=1;i<n;i++)
	  {
	     int x,y;
		 scanf("%d%d",&x,&y);
		 addedge(x,y);
		 addedge(y,x);
	  }
	  dfs(0,0);
	  build_RMQ();
	  int q;
	  scanf("%d",&q);
	  for (int i=1;i<=q;i++)
	  {
	     int x,y,z;
		 scanf("%d%d%d",&x,&y,&z);
		 val[x]+=z;
		 val[y]+=z;
		 val[get_LCA(x,y)]-=z;
		 up[get_LCA(x,y)]-=z;
	  }
	  calc(0,0);
	  printf("Case #%d:\n",ii);
	  for (int i=0;i<n;i++)
		  printf("%d\n",val[i]);
   }
   return 0;
}