#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;

typedef long long ll;

ll num[2*maxn];

ll gcd(ll a,ll b) {
	return b?gcd(b,a%b):a;
}


ll Scan()     //输入外挂
{
	ll res=0,ch,flag=0;
	if((ch=getchar())=='-')
		flag=1;
	else if(ch>='0'&&ch<='9')
		res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}
void Out(ll a)    //输出外挂
{
	if(a>9)
		Out(a/10);
	putchar(a%10+'0');
}

int main() {
	ll t, n, q;
	t = Scan();
	while (t--) {
		n = Scan();
		for (int i = 1; i <= n; i++)
			num[i] = Scan();
		q = Scan();
		int op, l, r, x;
		while (q--) {
			op = Scan();
			l = Scan();
			r = Scan();
			x = Scan();
			if (op == 1) {
				for (int i = l; i <= r; i++)
					num[i] = x;
			}
			else {
				for (int i = l; i <= r; i++)
					if (num[i] > x) 
						num[i] = gcd(num[i], x);
			}
		}
		for (int i = 1; i <= n; i++) {
			Out(num[i]);
			putchar(' ');
		}
		puts("");
	}
}
