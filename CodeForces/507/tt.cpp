#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll h,n,ans;
    while(cin>>h>>n)
    {
        int flag=1;
        ans=0;
        while(h)
        {
            ll left = (1LL<<h);
            if(flag)
            {
                if(n>left/2LL)
                {
                    ll total = 1LL<<(h+1);
                    total = (total-1)>>1;
                    ans+=total;
                    ans+=1;
                    n = n-(1LL<<(h-1));
                    flag=1;
                }
                else
                {
                    ans+=1;
                    flag=0;
                }
            }
            else
            {
                if(n>left/2LL)
                {
                    ans+=1;
                    flag=1;
                    n = n-(1LL<<(h-1));
                }
                else
                {
                    ll total = 1LL<<(h+1);
                    total = (total-1)>>1;
                    ans+=total;
                    ans+=1;
                }
            }
            h--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
