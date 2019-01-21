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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

#define L ((i<<1)+1)
#define R ((i<<1)+2)

#define N 210000
#define S 1100000

const int inf=LONG_MAX;
const int low=LONG_MIN;

int a[N],s[N];
int c[S],d[S];
int n,m,k;

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
			modif(L,l,  mid,1,n,d[i]);
			modif(R,mid+1,r,1,n,d[i]);
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
			modif(L,l,  mid,1,n,d[i]);
			modif(R,mid+1,r,1,n,d[i]);
			d[i]=0;c[i]=max(c[L]+d[L],c[R]+d[R]);
		}		
		int lefval=querr(L,l,  mid,u,v);
		int rigval=querr(R,mid+1,r,u,v);
		return max(lefval,rigval);
	}
}

void opt0(const int &x,const int &y){
	int d=y-a[x];a[x]=y;
	modif(0,1,n,x-k+1,x,d);
}

void opt1(const int &x,const int &y){
	int valx=a[x],valy=a[y];
	opt0(x,valy);opt0(y,valx);
}

void opt2(const int &x,const int &y){
	printf("%d\n",querr(0,1,n,x,y-k+1));
}

int main(){	//cout<<"inf="<<inf<<endl;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		s[n+1]=0;for(int i=n;i>0;i--)s[i]=s[i+1]+a[i]-(i+k<=n?a[i+k]:0);
		n=n-k+1;build(0,1,n);
		for(int i=0;i<m;i++){
			int p,x,y;scanf("%d%d%d",&p,&x,&y);
			switch(p){
				case 0:opt0(x,y);break;
				case 1:opt1(x,y);break;
				case 2:opt2(x,y);break;
			}
		}
	}
	return 0;
}

