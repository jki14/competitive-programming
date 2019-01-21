//============================================================================
// Name        : QuickerSuffixArray
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 例为POJ2774,求两个字符串的最长相同连续子串( O(n)实现 )
//============================================================================

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

const int pone=0xffffffff;

int na,nb,n,ans;
int sa[S],rak[N],hig[N];
int buf[S],ct[N],sx[N],sax[N];
char a[N],b[N],s[N];

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

void build(){
	n=strlen(s)+1;
	makesa();lcp();
}

void work(){
	int i,k=0;
	na=strlen(a);nb=strlen(b);

	for(i=0;i<na;i++)s[k++]=a[i];s[k++]='$';
	for(i=0;i<nb;i++)s[k++]=b[i];s[k++]=0;

	build();

	ans=0;
	for(i=1;i<n;i++){

		if( ((sa[i]<na && sa[i-1]>na) || (sa[i]>na && sa[i-1]<na))  && hig[i]>ans )ans=hig[i];
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%s%s",a,b)!=EOF)work();
	return 0;
}

