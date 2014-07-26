#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

long long n,dp[25][3];
int digit[25];

long long DFS(int pos,int status,int limit){
    if(pos==-1) // 如果到了已经枚举了最后一位，并且在枚举的过程中有49序列出现 
        return status==2;
    if(!limit && dp[pos][status]!=-1)   // 对于有限制的询问我们是不能够记忆化的 
        return dp[pos][status];
    long long ans=0;
    int s,end=limit?digit[pos]:9;   // 确定这一位的上限是多少
    for(int i=0;i<=end;i++){    // 每一位有这么多的选择 
        s=status;       // 有点else s = statu 的意思 
        if(status==1 && i==9)
            s=2;
        if(status==0 && i==4)
            s=1;
        if(status==1 && i!=4 && i!=9)
            s=0;
        ans+=DFS(pos-1,s,limit && i==end);
    }
    if(!limit)
        dp[pos][status]=ans;
    return ans;
}

long long Cal(long long x){
    int cnt=-1;
    while(x){
        digit[++cnt]=x%10;
        x/=10;
    }
    return DFS(cnt,0,1);
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
		cin >> n;
		cout << Cal(n) << endl;
        //scanf("%I64d",&n);
        //printf("%I64d\n",Cal(n));
    }
    return 0;
}
