#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

#define maxn 110
#define maxm 110
#define maxp 1100
#define maxl 100

int g[maxp][maxp],mk[maxp],pnt[maxp];
int l,r,id[maxp];
int n,m,p,k,res;
int a[maxp],b[maxp];

char cstr[maxl];

string str;
map<string,int> s;

int find(const int &x){
	if(mk[x])return 0;
	mk[x]=1;
	for(int y=1;y<=r;y++)
		if(g[x][y]){
			if(pnt[y]==0 || find(pnt[y])){
				pnt[y]=x;
				return 1;
			}
		}
	return 0;
}

void work(){
	int i,j;s.clear();k=0;
	for(i=0;i<p;i++){
		scanf("%s",cstr);str=cstr;
		if(!s[str])
			j=s[str]=++k;
		else
			j=s[str];
		a[i]=j;
		scanf("%s",cstr);str=cstr;
		if(!s[str])
			j=s[str]=++k;
		else
			j=s[str];
		b[i]=j;
	}
	memset(g,0,sizeof(g));res=p;
	memset(id,0,sizeof(id));l=r=0;
	for(i=0;i<p;i++){if(!id[i])id[i]=++l;
		for(j=i+1;j<p;j++){
			if(id[i]>0){
				if(a[i]==b[j] || a[j]==b[i]){if(!id[j])id[j]=--r;
					g[id[i]][-id[j]]=1;
					//printf("Link %d -> %d\n",id[i],-id[j]);
				}
			}else{
				if(a[i]==b[j] || a[j]==b[i]){if(!id[j])id[j]=++l;
					g[id[j]][-id[i]]=1;
					//printf("Link %d -> %d\n",id[j],-id[i]);
				}
			}
		}
	}
	//for(i=0;i<p;i++)printf("id[%d]=%d\n",i,id[i]);
	memset(pnt,0,sizeof(pnt));r=-r;
	//printf("l=%d r=%d\n",l,r);
	for(i=1;i<=l;i++){
		memset(mk,0,sizeof(mk));
		if(find(i))res--;
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)
		work();
	return 0;
}

