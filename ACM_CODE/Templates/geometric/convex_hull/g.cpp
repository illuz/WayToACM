#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define inf 200000
using namespace std;

bool vis[15],tvis[15];
int n,m,minv,tn;

typedef struct point
{
    double x,y;
    int v;
    double l;
    int z;
    point(double xx=0,double yy=0,int vv=0,double ll=0,int zz=0):x(xx),y(yy),v(vv),l(ll),z(zz){}
}vector;

point p[15],ch[15];

bool operator < (point a,point b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
vector operator - (point a,point b)
{
    return vector(a.x-b.x,a.y-b.y);
}
double cross(vector a,vector b)
{
    return a.x*b.y-a.y*b.x;
}
double len(vector a)
{
    return sqrt(a.x*a.x+a.y*a.y);
}

int graph()
{
    int k,i;
    m=0;
    for(i=0;i<n;i++) if(!vis[i])
    {
        while(m>1 && cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    k=m;
    for(i=n-2;i>=0;i--) if(!vis[i])
    {
        while(m>k && cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    double s1=0,s2=0;
    for(i=0;i<m;i++) s1+=len(ch[i]-ch[(i+1)%m]);
    for(i=0;i<n;i++) if(vis[i]) s2+=p[i].l;
    return s1<=s2;
}
void dfs(int d)
{
    int i,mv=0,mn=0;
    if(d==n)
    {
        if(graph())
        {
            for(i=0;i<n;i++) if(vis[i]) 
            {
                mv+=p[i].v;mn++;
            }
            if(mv<minv || (mv==minv && tn>mn)) 
            {
                for(i=0;i<n;i++) tvis[i]=vis[i];
                minv=mv;
                tn=mn;
            }
        }
        return;
    }
    dfs(d+1);
    vis[d]=1;
    dfs(d+1);
    vis[d]=0;
}
int main()
{
    int i,j,t=0,a[15];
    while(scanf("%d",&n)!=EOF && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf%d%lf",&p[i].x,&p[i].y,&p[i].v,&p[i].l);
            p[i].z=i;
        }

        sort(p,p+n);
        minv=inf;tn=inf;
        memset(vis,0,sizeof(vis));

        dfs(0);
        if(t++) printf("\n");
        printf("Forest %d\n",t);
        printf("Cut these trees:");
        j=0;
        for(i=0;i<n;i++) if(tvis[i]) a[j++]=p[i].z+1;
        sort(a,a+j);
        for(i=0;i<j;i++) printf(" %d",a[i]);

        double s1=0,s2=0;
        for(i=0;i<n;i++) vis[i]=tvis[i];
        graph();
        for(i=0;i<m;i++) s1+=len(ch[i]-ch[(i+1)%m]);
        for(i=0;i<n;i++) if(vis[i]) s2+=p[i].l;
        printf("\nExtra wood: %.2lf\n",s2-s1);
    }
    return 0;
}
