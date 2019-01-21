#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
using namespace std;

#define sqr(x) (x)*(x)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FF(i,a) for(int i=0;i<a;i++)

const double eps=1e-3;
const double INF=1e20;
const double pi=acos(-1.0);
struct Houxuan
{
    double x,y,dist;
}pp[30];
struct PT
{
    double x,y;
}hole[1000];
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
int n,cas;
int X,Y;
int main()
{
    int P=15,L=25;
    scanf("%d",&cas);
    srand((unsigned)time(NULL));
    while(cas--)
    {
        scanf("%d%d%d",&X,&Y,&n);
        double delta=double(max(X,Y))/(sqrt(1.0*n));
        FF(i,n)
            scanf("%lf%lf",&hole[i].x,&hole[i].y);
        FF(i,P)
        {
            pp[i].x=double(rand()%1000+1)/1000.000*X;
            pp[i].y=double(rand()%1000+1)/1000.000*Y;
            pp[i].dist=INF;
            FF(j,n)
                pp[i].dist=min(pp[i].dist,dis(pp[i].x,pp[i].y,hole[j].x,hole[j].y));
        }
        while(delta>eps)
        {
            FF(i,P)
            {
                Houxuan tmp=pp[i];
                FF(j,L)
                {
                    double theta=double(rand()%1000+1)/1000.000*10*pi;
                    Houxuan t;
                    t.x=tmp.x+delta*cos(theta);
                    t.y=tmp.y+delta*sin(theta);
                    if(t.x>X||t.x<0||t.y>Y||t.y<0)
                        continue;
                    t.dist=INF;
                    FF(k,n)
                    {
                        t.dist=min(t.dist,dis(t.x,t.y,hole[k].x,hole[k].y));
                    }
                    if(t.dist>pp[i].dist)
                        pp[i]=t;                    
                }
            }
            delta*=0.8;
        }
        int idx=0;
        FOR(i,1,P)
        {
            if(pp[i].dist>pp[idx].dist)
                idx=i;
        }    
        printf("The safest point is (%.1lf, %.1lf).\n",pp[idx].x,pp[idx].y);    
    }
    return 0;
}
