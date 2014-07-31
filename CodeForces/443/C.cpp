#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string s[105];
bool tool[12];
int ans[105];
int n;

int getVal(char c) {
	if(c=='R')  return 1;
	if(c=='G')  return 2;
	if(c=='B')  return 3;
	if(c=='Y')  return 4;
	if(c=='W')  return 5;
}

bool judge(int t) {
	for(int i=0;i<10;i++)
		if(t&(1<<i))
			tool[i]=1;
		else tool[i]=0;
	for(int i=0;i<n;i++) {
		ans[i]=0;
		int t=getVal(s[i][0]);
		if(tool[t-1])
			ans[i]+=t*10;
		if(tool[5+s[i][1]-'1'])
			ans[i]+=5+s[i][1]-'1';
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++) {
			if(s[i]!=s[j]&&ans[i]==ans[j])
				return false;
		}
	return true;
}

int hehe(int t) {
	int ans=0;
	for(int i=0;i<10;i++)
		if(t&(1<<i))
			ans++;
	return ans;
}

int main() {
	int res=10;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<(1<<10);i++) {
		if(judge(i)) {
			res=min(res,hehe(i));
		}
	}
	printf("%d\n",res);
	return 0;
}
