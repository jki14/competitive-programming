#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-5
#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)
using namespace std;void RD(int &x){scanf("%d",&x);}void RD(u32 &x){scanf("%u",&x);}void RD(double &x){scanf("%lf",&x);}void RD(int &x,int &y){scanf("%d%d",&x,&y);}void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}void RD(int &x,int &y,int &z,int &t){scanf("%d%d%d%d",&x,&y,&z,&t);}void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}void RD(char &x){x=getchar();}void RD(char *s){scanf("%s",s);}void RD(string &s){cin>>s;}void PR(int x) {printf("%d\n",x);}void PR(int x,int y) {printf("%d %d\n",x,y);}void PR(i64 x) {printf("%lld\n",x);}void PR(u32 x) {printf("%u\n",x);}void PR(double x) {printf("%.5lf\n",x);}void PR(char x) {printf("%c\n",x);}void PR(char *x) {printf("%s\n",x);}void PR(string x) {cout<<x<<endl;}const int INF=1000000000;const int N=400005;char s1[N],s2[N],p1[N],p2[N];int n,Next1[N],Next2[N];void reverse(char *s,int len){    int L=0,R=len-1;    while(L<R) swap(s[L++],s[R--]);}void getNext(char s[],int len,int next[]){    next[0]=-1;    int i=0,j=-1;    while(i<len)    {        if(j==-1||s[i]==s[j]) next[++i]=++j;        else j=next[j];    }}int pos[2][N];void match(char s[],int sLen,char p[],int pLen,int next[],int pos[]){    int i=0,j=0;    while(i<sLen)    {        if(j==-1||s[i]==p[j])        {            i++;j++;            pos[j]=min(pos[j],i);        }        else j=next[j];        if(j==pLen) j=next[j];    }}int main(){    RD(s1);    int len=strlen(s1);    strcpy(s2,s1); reverse(s2,len);    int ans=0,i,j,L;    RD(n);    while(n--)    {        RD(p1); strcpy(p2,p1); L=strlen(p1); reverse(p2,L);        if(L<=1) continue;        FOR1(i,L) pos[0][i]=pos[1][i]=INF;        getNext(p1,L,Next1);        match(s1,len,p1,L,Next1,pos[0]);        getNext(p2,L,Next2);        match(s2,len,p2,L,Next2,pos[1]);        FOR1(i,L) if(pos[0][i]+pos[1][L-i]<=len)        {            ans++;            break;        }    }    PR(ans);    return 0;}
