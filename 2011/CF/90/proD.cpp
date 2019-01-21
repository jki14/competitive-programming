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

#define N 2100000
#define S 8100000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=0x3fffffff;
const int minlen=256;
const int pone=0xffffffff;

int n,m,x,y,rig,c[S];
int f[N],sa[S],bk[N],rak[N],hig[N];
int buf[S],ct[N],sx[N],sax[N];
char src[N],des[N],s[N];

inline int leq(const int &a,const int &b,const int &x,const int &y){
	return (a<x || (a==x && b<=y) ) ;
}

inline int leq(const int &a,const int &b,const int &c,const int &x,const int &y,const int &z){
	return (a<x || (a==x && leq(b,c,y,z)) ) ;
}

inline int geti(const int &t,const int &nx,int sa[]){
	return sa[t]<nx ? sa[t]*3+1 : (sa[t]-nx)*3+2;
}

static void radix(int a[],int b[],int s[],const int &n,const int &k){
	int i,t,sum;
	memset(ct,0,(k+1)*sizeof(int));
	for(i=0;i<n;i++)ct[s[a[i]]]++;
	for(i=sum=0;i<=k;i++){
		t=ct[i];ct[i]=sum;sum+=t;
	}
	for(i=0;i<n;i++)b[ct[s[a[i]]]++]=a[i];
}

void suffix(int s[],int sa[],int n,int k){
	int i,j,e,p,t;
	int name=0,cx=-1,cy=-1,cz=-1;
	int nx=(n+2)/3,ny=(n+1)/3,nz=n/3,nxz=nx+nz;
	int *syz=s+n+3,*sayz=sa+n+3;
	for(i=j=0;i<n+(nx-ny);i++)
		if(i%3!=0)syz[j++]=i;
	radix(syz ,sayz,s+2,nxz,k);
	radix(sayz,syz ,s+1,nxz,k);
	radix(syz ,sayz,s  ,nxz,k);
	for(i=0;i<nxz;i++){
		if(s[sayz[i]]!=cx || s[sayz[i]+1]!=cy || s[sayz[i]+2]!=cz){
			name++;cx=s[sayz[i]];
			cy=s[sayz[i]+1];cz=s[sayz[i]+2];
		}
		if(sayz[i] % 3==1)syz[sayz[i]/3]=name;
		else syz[sayz[i]/3+nx]=name;
	}
	if(name<nxz){
		suffix(syz,sayz,nxz,name);
		for(i=0;i<nxz;i++)syz[sayz[i]]=i+1;
	}else{
		for(i=0;i<nxz;i++)sayz[syz[i]-1]=i;
	}
	for(i=j=0;i<nxz;i++)
		if(sayz[i]<nx)sx[j++]=3*sayz[i];
	radix(sx,sax,s,nx,k);
	for(e=p=0,t=nx-ny;e<n;e++){
		i=geti(t,nx,sayz);j=sax[p];
		if(sayz[t]<nx ? leq(s[i],syz[sayz[t]+nx],s[j],syz[j/3]):leq(s[i],s[i+1],syz[sayz[t]-nx+1],s[j],s[j+1],syz[j/3+nx])){
			sa[e]=i;
			if(++t==nxz){
				for(e++;p<nx;p++,e++)sa[e]=sax[p];
			}
		}else{
			sa[e]=j;
			if(++p==nx)for(++e;t<nxz;++t,++e)sa[e]=geti(t,nx,sayz);
		}
	}
}

void makesa(){
	memset(buf,0,4*n*sizeof(int));
	memset(sa ,0,4*n*sizeof(int));
	for(int i=0;i<n;i++)buf[i]=s[i]&pone;
	suffix(buf,sa,n,255);
}

void lcp(){
	int i,j,k;
	for(i=0;i<n;i++)rak[sa[i]]=i;
	memset(hig,0,sizeof(hig));
	for(j=rak[hig[i=k=0]=0];i<n-1;i++,k++){
		while(k>=0 && s[i]!=s[sa[j-1]+k]){
			hig[j]=k--;
			j=rak[sa[j]+1];
		}
	}
}

void build(const int &i,const int &l,const int &r){
	if(l==r){
		c[i]=hig[l];
		return;
	}else{int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		c[i]=min(c[L],c[R]);
	}
}

int getmin(const int &i,const int &l,const int &r,const int &u,const int &v){
	//printf("l=%d r=%d u=%d v=%d\n",l,r,u,v);
	if(u>r || v<l)return -1;
	if(u<=l && r<=v)return c[i];
	int mid=(l+r)>>1;
	int resl=getmin(L,l,  mid,u,v);
	int resr=getmin(R,mid+1,r,u,v);
	if(resl==-1)return resr;
	if(resr==-1)return resl;
	return min(resl,resr);
}


void buildsa(){
	n=strlen(s)+1;
	makesa();lcp();
	for(int i=0;i<n;i++){
		bk[sa[i]]=i;
		//printf("%d : sa=%d hig=%d\n",i,sa[i],hig[i]);
	}
	rig=n-1;build(0,1,rig);
	n=strlen(src);
}

void work(){
	n=strlen(src);//printf("n=%d\n",n);
	if(n<2 || ((int)strlen(des))!=n){ 
		//printf("lenX");
		printf("-1 -1\n");return; 
	}
	
	m=0;
	for(int i=n-1;i>=0;i--)s[m++]=src[i];
	s[m++]=1;
	for(int i=0;i<n;i++)s[m++]=des[i];
	s[m]=0;
	
	memset(f,0xff,sizeof(f));
	for(int k,i=1;s[i];i++){
		for(k=f[i-1];k>=0 && s[k+1]!=s[i];)k=f[k];
		if(s[k+1]==s[i])f[i]=k+1;
		//printf("f[%d]=%d\n",i,f[i]);
	}
	
	m=0;
	for(int i=0;i<n;i++)s[m++]=des[i];
	s[m++]=1;
	for(int i=0;i<n;i++)s[m++]=src[i];
	s[m]=0;
	buildsa();

	x=-1;y=-1;//printf("n=%d\n",n);
	for(int i=0;i<n;i++){
		if(src[i]!=des[n-i-1])break;
		//printf("i=%d\n",i);
		if(f[m-i-2]==-1)continue;
		//printf("f[m-i-2]=%d n=%d\n",f[m-i-2],n);
		int j=max(n-f[m-i-2]-1,i+1);
		//printf("j=%d\n",j);
		//printf("i=%d j=%d\n",i,j);
		if(j==i+1){
			x=i;y=j;continue;
		}
		int u=bk[0],v=bk[n+i+2],len=j-i-1;
		if(u>v)swap(u,v);
		//printf("%d->%d\n",u,v);
		//printf("maxlen=%d len=%d\n",getmin(0,1,rig,u+1,v),len);
		if(getmin(0,1,rig,u+1,v)>=len){
			x=i;y=j;
		}
	}

	if(x<0)
		printf("-1 -1\n");
	else
		printf("%d %d\n",x,y);
}

int main(){
	while(gets(src)){
		gets(des);
		work();
	}
	//printf("%d [%c]\n",(int)'$',(char)1);
	return 0;
}
