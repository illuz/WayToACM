#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
typedef long long ll;  
const int N = 100100 << 2;  
const double PI = acos(-1.0);  
struct Node  
{  
	double x, h;  
	int id;  
	bool operator<(Node b) const { return x < b.x; }  
}node[N];  
Node S[N];  
double ans[N];  

bool check(Node a, Node b, Node c)  
{  
	if(c.h<0) c.h=0;  
	return (a.h-b.h) * (c.x-b.x) >= (b.x-a.x) * (b.h-c.h);  
}  
double getAngle(Node a, Node b)  
{  
	return atan((b.x-a.x)/a.h);  
}  
int n,Q;  
void get()  
{  
	int top = 0;  
	for(int i=0;i<n+Q;i++)  
	{  
		if(node[i].h<0)  
		{  
			while(top>=2 && check(S[top-1], S[top], node[i])) top--;  
			ans[node[i].id] += getAngle(S[top], node[i]);  
		}  
		else {  
			while(top && S[top].h <= node[i].h) top--;  
			while(top>=2 && check(S[top-1], S[top], node[i])) top--;  
			S[++top] = node[i];  
		}  
	}  
}  
int main()  
{  
	int re; cin>>re;  int ca=1;  
	while(re--)  
	{  
		cin>>n;  
		for(int i=0;i<n;i++) scanf("%lf%lf", &node[i].x, &node[i].h);  
		cin>>Q;  
		for(int i=n;i<n+Q;i++) scanf("%lf", &node[i].x), node[i].h = -1, node[i].id = i-n;  

		memset(ans,0,sizeof ans);  
		sort(node, node+n+Q);  
		get();  

		reverse(node, node+n+Q);  
		for(int i=0;i<n+Q;i++) node[i].x = 1e9 - node[i].x;  
		get();  

		printf("Case #%d:\n", ca++);  
		for(int i=0;i<Q;i++) printf("%.9f\n", ans[i] * 180 / PI);  
	}  
}  
