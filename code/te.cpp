#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

#define clr(x,y) memset(x,y,sizeof x)
typedef long long ll;
const int maxn = 100000 + 2;
const ll Mod = 1e9 + 7;


struct point{
    double x,y;
};
point p[N],s[N][N];
int n,top[N];
bool vis[N];
inline bool zero(double x)
{
    return fabs(x)<eps;
}
double dis(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double dir(point p1,point p2,point p3)
{
    return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);
}
bool comp(point p1,point p2)
{
    double te=dir(p[0],p1,p2);
    if(te<0)return 1;
    if(zero(te)&&dis(p[0],p1)<dis(p[0],p2))return 1;
    return 0;
}
void Graham(int k)
{
    int pos;
    double minx=inf,miny=inf;
    for(int i=0;i<n;i++)
    {
        if(p[i].x<minx||(p[i].x==minx&&p[i].y<miny))
        {
            minx=p[i].x;
            miny=p[i].y;
            pos=i;
        }
    }
    swap(p[0],p[pos]);
    sort(p+1,p+n,comp);
    p[n]=p[0];
    s[k][0]=p[0],s[k][1]=p[1], s[k][2]=p[2];
    top[k]=2;
    for(int i=3;i<=n;i++)
    {
        while(top[k]>=2&&dir(s[k][top[k]-1],s[k][top[k]],p[i])>=0)top[k]--;
        s[k][++top[k]]=p[i];
    }
}
double square(int k)
{
    double ans=0;
    for(int i=0;i<top[k]-1;i++)
        ans-=dir(s[k][0],s[k][i],s[k][i+1]);
    return ans/2;
}
struct Node {
    double x,y;
}a[maxn];
char s[maxn];
int temp[maxn];
double X,Y;


bool cmp(Node t1,Node t2) {
    
}
int main() {
    scanf("%lf,%lf",&X,&Y);
    scanf("%s",s);
    int len = strlen(s);
    int cnt = 0;
    int x = 0;
    for(int i = 0;i < len;i ++) {
        if(s[i] == ',' || i == len - 1) {
            temp[++ cnt] = x;
            x = 0;
        }
        x = x * 10 + s[i] - '0';
    }
    for(int i = 1;i <= cnt ;i += 2) {
        p[i/2].x = temp[i];
        p[i/2].y = temp[i + 1]；
    }
    for(int i=0;i<cnt;i++)
        {
            double sq=square(i);
            if(!vis[i]&&inside(sq,x,y,i))
            {
                vis[i]=1;
                ans+=sq;
                break;
            }
        }
    int n = cnt / 2;
    
    return 0;
}