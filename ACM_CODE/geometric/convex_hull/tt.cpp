#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 15 + 1;
const int INF = 1000000000;

struct Tree
{
    double x;
    double y;
    int v;
    int l;
    Tree(){}
    Tree(int xx, int yy):x(xx), y(yy){}
    bool operator < (const Tree& e) const
    {
        return x < e.x || (x == e.x && y < e.y);
    }
}t[maxn];

Tree operator - (Tree A, Tree B){return Tree(A.x - B.x, A.y - B.y);}

double Cross(Tree A, Tree B){return A.x * B.y - A.y * B.x;}
double Dis(Tree A, Tree B) {return hypot(A.x - B.x, A.y - B.y);}

int ConvexHull(Tree *p, int n, Tree* ch)        //求凸包
{
    sort(p, p + n);
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        while(m > 1 && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--)
    {
        while(m > k && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}

double Perimeter(Tree *ret, int m)
{
    double perimeter = 0;
    for(int i = 1; i < m; i++) perimeter += Dis(ret[i], ret[i-1]);
    perimeter += Dis(ret[0], ret[m-1]);
    return perimeter;
}

int main()
{
    int n, i, Case = 1, bit;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; i++) scanf("%lf%lf%d%d", &t[i].x, &t[i].y, &t[i].v, &t[i].l);
        int min_val = INF;      //砍掉的最小价值
        int min_cnt = INF;      //砍掉的最小价值时砍掉的树的数量
        double exc_len = 0;     //做好围栏后剩余木材长度
        int ans = 0;        //砍掉的方法，二进制映射
        for(bit = 0; bit < (1<<n); bit++)     //枚举每一种砍树的方法
        {
            Tree buf[maxn], ret[2*maxn];      //buf缓冲，ret求凸包后的点组
            double cut_len = 0;        //这一种方法砍掉的树的总长度
            int cut_val = 0;        //这一种方法砍掉的树的总价值
            int cut_cnt;        //这一种方法砍掉的树的总数量
            int m = 0;      //使用这一种方法后剩下的树的数量
            for(i = 0; i < n; i++)      //扫描这种方法
            {
                if(bit&(1<<i))        //被砍掉的
                {
                    cut_len += t[i].l;
                    cut_val += t[i].v;
                }
                else        //剩下的
                {
                    buf[m].x = t[i].x;
                    buf[m++].y = t[i].y;
                }
            }
            if(cut_val > min_val) continue;
            cut_cnt = n - m;
            int cnt = ConvexHull(buf, m, ret);      //求凸包
            double perimeter = Perimeter(ret, cnt);     //凸包周长
			printf("%f %f %d\n", perimeter, cut_len, bit);
            if(cut_len >= perimeter)      //砍掉的树满足长度要求
            {
                if(cut_val < min_val || (cut_val == min_val && cut_cnt < min_cnt))
                {
                    min_val = cut_val;
                    min_cnt = cut_cnt;
                    exc_len = cut_len - perimeter;
                    ans = bit;
                }
            }
        }
        if(Case > 1) printf("\n");
        printf("Forest %d\n", Case++);
        printf("Cut these trees:");
        for(i = 0; i < n; i++) if(ans&(1<<i)) printf(" %d", i+1);
        printf("\n");
        printf("Extra wood: %.2f\n", exc_len);
    }
    return 0;
}
