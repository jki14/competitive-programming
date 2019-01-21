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

#define max(x,y) ((x>y)?x:y)

const int inf=LONG_MAX;
const int low=LONG_MIN;

int a[N],s[N];
int c[S],d[S];
int n,m,k,lef,rig;

void build(const int &i,const int &l,const int &r){d[i]=0;
	if(l==r){
		c[i]=s[l];
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
		c[i]=max(c[L]+d[L],c[R]+d[R]);
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
			d[i]=0;c[i]=max(c[L]+d[L],c[R]+d[R]);
		}		
		int lefval=querr(L,l,  mid,u,v);
		int rigval=querr(R,mid+1,r,u,v);
		return max(lefval,rigval);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);lef=1;rig=n-k+1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		s[n+1]=0;
		for(int i=n;i>0;i--)s[i]=s[i+1]+a[i]-(((i+k<=n))?a[i+k]:0);
		build(0,lef,rig);
		int p,u,v,x,y;int val,va2;
		for(int i=0;i<m;i++){
			scanf("%d",&p);
			switch(p){
				case 0:
					scanf("%d%d",&u,&val);
					val-=a[u];a[u]+=val;
					v=u;u=u-k+1;
					modif(0,lef,rig,u,v,val);
					break;
				case 1:
					scanf("%d%d",&x,&y);val=a[y];va2=a[x];
					val-=a[x];a[x]+=val;
					u=x-k+1;v=x;
					modif(0,lef,rig,u,v,val);
					va2-=a[y];a[y]+=va2;
					u=y-k+1;v=y;
					modif(0,lef,rig,u,v,va2);
					break;
				case 2:
					scanf("%d%d",&u,&v);v=v-k+1;
					printf("%d\n",querr(0,lef,rig,u,v));
			}
		}
	}
	return 0;
}

