/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        d.cpp
*  Create Date: 2014-01-.12 21.127:03
*  Descripton:   
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
/****************************/
#define LL(x) ((x)<<1)
#define RR(x) ((x)>>1)
#define MP(x,y) make_pair(x,y)
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define RD(x) scanf("%lf",&x)
#define RDD(x,y) scanf("%lf%lf",&x,&y)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d",&x)
#define PIN(x) printf("%d\n",x)
#define PS(x) printf("%s",x)
#define PN() printf("")
#define rep(i,n) for(int i=0;i<(n);i++)
#define repu(i,a,b) for(int i=(a);i<(b);i++)
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define swap(a,b) {int t=a;a=b;b=t;}
#define clr(a) memset(a,0,sizeof(a))
#define sqr(x) ((x)*(x))
#define FI(i,x) for(typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
/****************************/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
/****************************/
const int INF = 0x7f7f7f7f;
const double EPS = 1e-8;
const double PI=acos(-1.0);
const int dx[]= {0,-1,0,1};
const int dy[]= {1,0,-1,0};
const int fx[]= {-1,-1,-1,0,0,1,1,1};
const int fy[]= {-1,0,1,-1,1,-1,0,1};
/***************************************/
void openfile()
{
	    freopen("data.in","rb",stdin);
		    freopen("data.out","wb",stdout);
}
/****** TEMPLATE ENDS *******/

double a, v, l, d, w;
double s1, t1, s2, t2;

int main() {
	RDD(a, v);
	scanf("%lf%lf%lf", &l, &d, &w);
	// 到达最大速度的时间和路程
	t1 = v / a;
	s1 = t1 * v / 2;
	if (w >= v) {
		if (s1 > l) {
			printf("%.12f", sqrt(2 * l / a));
		}
		else {
			printf("%.12f", t1 + (l - s1) / v);
		}
	}
	else {
		// 能不能在加到ｗ前到达
		// 到达w的时间和路程
		t2 = w / a;
		s2 = t2 * w / 2;
		if (s2 >= l) 
			printf("%.12f", sqrt(2 * l / a));
		else {
			if (s2 >= d) {
				if (l > s1)
					printf("%.12f", (l - s1) / v + t1);
				else
					printf("%.12f", sqrt(2 * l / a));
				return 0;
			}
			// v-w的时间和路程
			double t3 = (v - w) / a;
			double s3 = t3 * (w + v) / 2;
			if (s2 + s3 + s3 <= d) {
				double t4;
				if (s3 <= l - d)
					t4 = (l - d - s3) / v + t3;
				else
					t4 = sqrt(2 * (l - d + s2) / a);
				printf("%.12f", t2 + t3 + t3 + (d - (s2 + s3 + s3)) / v + t4);
			}
			else {
				double s5 = d / 2 + s2 / 2;
				double t5 = sqrt(2 * s5 / a);
				double s6 = l - d + s2;
				double t6;
				if (s6 > s1)
					t6 = t1 + (s6 - s1) / v;
				else
					t6 = sqrt(2 * s6 / a);
				printf("%.12f", (t5 - t2) * 2 + t6);
			}
		}
	}
	return 0;
}

