#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxp 1100
#define maxl 100

int n,m,p,res;
int l,r,L[maxp],R[maxp];
int g[maxp][maxp],v[maxp],pnt[maxp],k;
int c[maxp],d[maxp];
char cstr[maxl];

int find(const int &x){
	for(int y=1;y<=r;y++)
		if(v[y]!=k && g[x][y]){v[y]=k;
			if(!pnt[y] || find(pnt[y])){
				pnt[y]=x;
				return 1;
			}
		}
	return 0;
}

void work(){
	int i,j;l=r=0;res=p;
	for(i=0;i<p;i++){
		scanf("%s",cstr);
		if(cstr[0]=='C'){
			L[++l]=i;	
			sscanf(cstr,"C%d",&c[i]);
			scanf("%s",cstr);
			sscanf(cstr,"D%d",&d[i]);
		}else{
			R[++r]=i;
			sscanf(cstr,"D%d",&d[i]);
			scanf("%s",cstr);
			sscanf(cstr,"C%d",&c[i]);
		}
	}
	memset(g,0,sizeof(g));
	for(i=1;i<=l;i++)
		for(j=1;j<=r;j++)
			if(c[L[i]]==c[R[j]] || d[L[i]]==d[R[j]])g[i][j]=1;
	memset(pnt,0,sizeof(pnt));
	memset(v,0,sizeof(v));
	for(i=1;i<=l;i++){
		k=i;
		if(find(i))res--;
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)
		work();
	return 0;
}

