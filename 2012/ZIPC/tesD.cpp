#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 210000
#define S 1100000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=LONG_MAX;
const int low=LONG_MIN;

int a[N],sum[N];
int c[S],d[S];
int n,m,k,lef,rig;

inline int max (const int &x,const int &y){ return (x>y)?x:y; }

void build(const int &i,const int &l,const int &r){d[i]=0;
	if(l==r){
		c[i]=sum[l];
	}else{int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		c[i]=max(c[L],c[R]);
	}
}

void modif(const int &i,const int &l,const int &r,const int &u,const int &v,const int &x){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		d[i]+=x;
	}else{int mid=(l+r)>>1;
		if(d[i]){
			modif(L,l,  mid,lef,rig,d[i]);
			modif(R,mid+1,r,lef,rig,d[i]);
			d[i]=0;
		}
		modif(L,l,  mid,u,v,x);
		modif(R,mid+1,r,u,v,x);
		c[i]=max((c[L]+d[L]),(c[R]+d[R]));
	}
}

int querr(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r)return low;
	if(u<=l && r<=v){
		return c[i]+d[i];
	}else{int mid=(l+r)>>1;
		if(d[i]){
			modif(L,l,  mid,lef,rig,d[i]);
			modif(R,mid+1,r,lef,rig,d[i]);
			d[i]=0;c[i]=max((c[L]+d[L]),(c[R]+d[R]));
		}		
		int lefval=querr(L,l,  mid,u,v);
		int rigval=querr(R,mid+1,r,u,v);
		return max(lefval,rigval);
	}
}


 void edit(int x,int y)
 {
     int det = y - a[x];
     a[x] = y;
     int ll = x-k+1;
     if(ll <1)    ll = 1;
     int rr = x;
     if(x > n - k +1)    rr = n-k+1;
     if(ll>rr)while(1);
     modif(0,1,n-k+1,ll,rr,det);
 }

 int main()
 {
     int totcase,i;
     scanf("%d",&totcase);
     while(totcase--)
     {
         scanf("%d%d%d",&n,&m,&k);
         for(i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
         }
         sum[1] = 0;
         for(i=1;i<=k;i++)    sum[1] += a[i];
         for(i=2;i<=n-k+1;i++)    sum[i] = sum[i-1] - a[i-1] + a[i+k-1];
         build(0,1,n-k+1);
         int p,x,y;
         while(m--)
         {
             scanf("%d%d%d",&p,&x,&y);
             if(p==0)
             {
                 edit(x,y);
             }
             else if(p ==1 )
             {
                 int xx = a[x],yy = a[y];
                 edit(y,xx);
                 edit(x,yy);
             }
             else
             {
		 if(x>y-k+1)while(1);
                 printf("%d\n",querr(0,1,n-k+1,x,y-k+1));
             }
         }
     }
     return 0;
 }

