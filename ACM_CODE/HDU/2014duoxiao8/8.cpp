#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef __int64 LL;
const int maxn = (int) 1e5 + 10;
int main(){

	LL x, k;
	int T = 1;
	while(cin>>x>>k &&x ){
		LL d;
		d = x;
		for(int i = 2; i<= k; ++ i){
			d = d - d / (i);
			if(d < i) break;
		}
		printf("Case #%d: %I64d\n",T++,k * d);
	}
	return 0;
}
