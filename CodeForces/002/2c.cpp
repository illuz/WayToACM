/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        2c.cpp
*  Create Date: 2014-01-13 20:41:28
*  Descripton:  simulate annealing 
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
const double EPS = 1e-2;
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

const int MAXN = 160;
const int TIME = 1;	//退火次数
const double MAX_T = 10000.0;	// 高温
const double RATIO = 0.999;		// 衰减率
const double PER_T = 15;		// 每轮随机次数

int n;
double x11[MAXN], y11[MAXN], r[MAXN];
double ans = 0x7f7f7f7f, ansx, ansy;

double dis(double a1, double a2, double b1, double b2) {
	return sqrt((a1-a2)*(a1-a2) + (b1-b2)*(b1-b2));
}

double compute(double x, double y) {
    double v = 0;
	double ang[3];
	rep(i, 3)
		ang[i] = dis(x, x11[i], y, y11[i]) / r[i];
	v += (ang[0] - ang[1]) * (ang[0] - ang[1]);
	v += (ang[0] - ang[2]) * (ang[0] - ang[2]);
	v += (ang[1] - ang[2]) * (ang[1] - ang[2]);
    return v;
}

void solve() {
	double bit = 1;
	rep(i, TIME) {
		// 随机出一个点并算出函数值
		ansx = (x11[0] + x11[1] + x11[2]) / 3;
		ansy = (y11[0] + y11[1] + y11[2]) / 3;
		ans = compute(ansx, ansy);
		// 降温过程
		for (double t = MAX_T; t > EPS; t *= RATIO) rep(j, PER_T) {
			// 计算新生点的函数值 以及与上一次误差
			bool flag = false;
			rep(i, 4) {
				double tx = ansx + (double)dx[i] * bit;
				double ty = ansy + (double)dy[i] * bit;
				double newv = compute(tx, ty);
				// 更新ans
				if (ans > newv) {
					ans = newv;
					ansx = tx;
					ansy = ty;
					flag = 1;
				}
			}
			if (!flag) bit *= 0.5;
		}
	}
	if (compute(ansx, ansy) < 1e-6)
		printf("%.5f %.5f\n", ansx, ansy);
}

int main() {
	rep(i, 3)
		scanf("%lf%lf%lf", &x11[i], &y11[i], &r[i]);
	solve();
	return 0;
}

