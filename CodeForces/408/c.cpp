/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        c.cpp
*  Create Date: 2014-03-30 15:24:56
*  Descripton:   
*/

#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
int main()
{
	int a,b;
	while(cin>>a>>b){
		for(int i=1;i<b;i++){
			int j=(int)sqrt(b*b-i*i+0.5);
			if(j*j+i*i==b*b&&(a*i)%b==0){
				int s=a*i/b;
				int t=(int)sqrt(a*a-s*s+0.5);
				if(s*s+t*t==a*a){
					cout<<"YES"<<endl;
					cout<<0<<" "<<j<<endl;
					cout<<i<<" "<<0<<endl;
					cout<<t<<" "<<s+j<<endl;
					return 0;
				}
			}
		}
		puts("NO");
	}
}
