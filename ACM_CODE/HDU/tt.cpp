#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[10][80][90][90],digit[11];

int dfs(int pos,int prefix,int mod,int res,bool doing)
{
    if(pos<0){
        if(prefix==0||mod!=prefix) return 0;
        return res==0;
    }
    if(!doing&&dp[pos][prefix][mod][res]!=-1) return dp[pos][prefix][mod][res];
    int end=doing?digit[pos]:9;
    int ret=0;
    for(int i=0;i<=end;i++)
      ret+=dfs(pos-1,prefix+i,mod,(res*10+i)%mod,doing&&i==end);
    if(!doing) dp[pos][prefix][mod][res]=ret;
    return ret;
}
int cal(int n)
{
    int pos=0;
    for(;n;n/=10) digit[pos++]=n%10;
    int ret=0;
    for(int i=1;i<=pos*9;i++)
      ret+=dfs(pos-1,0,i,0,1);
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int T,cas=1;
    scanf("%d",&T);
    int l,r;
    while(T--)
    {
        scanf("%d%d",&l,&r);
        printf("Case %d: %d\n",cas++,cal(r)-cal(l-1));
    }
    return 0;
}