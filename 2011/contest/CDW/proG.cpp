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

const int low = LONG_MIN;

int n,m,p;
int f[S],fp[S],fd[S];
int g[S],fv[N],gv[N];

void buildf(const int &i,const int &l,const int &r){
	f[i]=fd[i]=0;fp[i]=l;
	if(l<r){
		int mid=(l+r)>>1;
		buildf(L,l,  mid);
		buildf(R,mid+1,r);
	}
}

void update(const int &i){
	int path=(f[L]+fd[L]>f[R]+fd[R])?L:R;
	f[i]=f[path]+fd[path];fp[i]=fp[path];
}

void fadd(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d);
void gadd(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d);

void fclear(const int &i,const int &l,const int &r,const int &x){
	if(x<l || x>r)return;

	//printf("fclear (%d, %d->%d ,%d)\n",i,l,r,x);

	if(l==r){
		//printf("tolow %d %d->%d\n",i,l,r);
		f[i]=low;fd[i]=0;
	}else{
		int mid=(l+r)>>1;
		fclear(L,l,  mid,x);
		fclear(R,mid+1,r,x);
		update(i);

		//printf("%d: f=%d fd=%d fp=%d\n",i,f[i],fd[i],fp[i]);

	}
}

void gclear(const int &i,const int &l,const int &r,const int &x){
	if(x<l || x>r)return;
	if(l==r){
		g[i]=0;
	}else{
		int mid=(l+r)>>1;
		if(g[i]){
			gadd(L,l,  mid,1,n,g[i]);
			gadd(R,mid+1,r,1,n,g[i]);
			g[i]=0;
		}
		gclear(L,l,  mid,x);
		gclear(R,mid+1,r,x);
	}
}

/*int fque(const int &i,const int &l,const int &r,const int &x){	
	if(l==r)return f[i];
	int mid=(l+r)>>1;
	if(fd[i]){
		fadd(L,l,  mid,1,n,fd[i]);
		fadd(R,mid+1,r,1,n,fd[i]);
		fd[i]=0;
	}
	if(x>mid)
		return fque(R,mid+1,r,x);
	else
		return fque(L,l,  mid,x);
}

int gque(const int &i,const int &l,const int &r,const int &x){
	if(l==r)return g[i];
	int mid=(l+r)>>1;
	if(g[i]){
		gadd(L,l,  mid,1,n,g[i]);
		gadd(R,mid+1,r,1,n,g[i]);
		g[i]=0;
	}
	if(x>mid)
		return gque(R,mid+1,r,x);
	else
		return gque(L,l,  mid,x);
}*/

void fillblack(const int &i,const int &l,const int &r){
	if(l==r){
		if(!fv[l])fv[l]=-f[i];
		gv[l]=g[i];
	}else{
		int mid=(l+r)>>1;
		if(fd[i]){
			fadd(L,l,  mid,1,n,fd[i]);
			fadd(R,mid+1,r,1,n,fd[i]);
			fd[i]=0;
		}
		if(g[i]){
			gadd(L,l,  mid,1,n,g[i]);
			gadd(R,mid+1,r,1,n,g[i]);
			g[i]=0;
		}
		fillblack(L,l,  mid);
		fillblack(R,mid+1,r);
	}
}

void fadd(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	
	if(v<l || u>r)return;

	//printf("fadd (%d , %d->%d , %d->%d ,%d)\n",i,l,r,u,v,d);

		if(u<=l && r<=v){
		if(l==r)
			f[i]+=d;
		else fd[i]+=d;
		while(f[i]+fd[i]>=p){

			//printf("uplevel %d val=%d pa=%d\n",fp[i],f[i],fd[i]);

			int pos=fp[i];
			fv[fp[i]]=f[i]+fd[i];
			fclear(0,1,n,pos);
			gclear(0,1,n,pos);	
		}
	}else{
		int mid=(l+r)>>1;
		if(fd[i]){
			fadd(L,l,  mid,1,n,fd[i]);
			fadd(R,mid+1,r,1,n,fd[i]);
			fd[i]=0;
		}
		fadd(L,l,  mid,u,v,d);
		fadd(R,mid+1,r,u,v,d);
		update(i);
	}
}

void gadd(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		g[i]+=d;
	}else{
		int mid=(l+r)>>1;
		if(g[i]){
			gadd(L,l,  mid,1,n,g[i]);
			gadd(R,mid+1,r,1,n,g[i]);
			g[i]=0;
		}
		gadd(L,l,  mid,u,v,d);
		gadd(R,mid+1,r,u,v,d);
	}
}

#define LEN 11

char ch,cstr[LEN];

int readunsigned(){
	int ret;

	do{
		ch = getchar() ;
	}while(ch<'0');
	ret = ch - '0' ;

	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}

	return ret;
}

void putunsigned(const int &x){
	int k=x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	while(r--){
		putchar(cstr[r]);
	}
	//putchar('\n');
}

void work(){
	/* Init */
	buildf(0,1,n);
	memset(g,0,sizeof(g));
	memset(fv,0,sizeof(fv));
	/* Core */
	for(int i=0;i<m;i++){
		int u,v,d;
		//scanf("%d%d%d",&u,&v,&d);
		u=readunsigned();v=readunsigned();d=readunsigned();
		gadd(0,1,n,u,v,(d<<1));fadd(0,1,n,u,v,d);

		//for(int j=1;j<=n;j++)printf("fque(%d)=%d gque(%d)=%d\n",j,fque(0,1,n,j),j,gque(0,1,n,j));

	}
	/* Result */
	fillblack(0,1,n);
	for(int i=1;i<=n;i++){
		if(i>1)putchar(' ');
		if(fv[i]>0){
			putunsigned(fv[i]+gv[i]);
			//printf("%d",fv[i]+gv[i]);
		}else{
			putunsigned(-fv[i]);
			//printf("%d",-fv[i]);
		}
	}
	putchar('\n');
}

int main(){
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)
		work();
	return 0;
}

