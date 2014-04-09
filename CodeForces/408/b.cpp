/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  File:        b.cpp
*  Create Date: 2014-03-30 15:40:00
*  Descripton:   
*/

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstdlib>
#include <string>
#include<cstdio>
#include <set>
using namespace std;
typedef long long LL;


const int maxn = 260 + 10;

int A[maxn] ,B[maxn];

int main(){
    string s;
    while(cin>>s){
        int n = s.size();
        for(int i = 0 ;i < n; ++i){
           ++ A[s[i] - 'a'];
        }
        cin>>s;
        n = s.size();
        for(int i = 0 ; i< n; ++i){
            ++ B[s[i] - 'a'];
        }
        int ans = 0;
        for(int i = 0 ;i < 26; ++ i){
            if(B[i]){
                if(A[i] >= B[i]) ans += B[i];
                else if(A[i] == 0){
                    ans = -1;
                    break;
                }
                else
                {
                    ans += A[i];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}