#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 2100
#define maxm 4100000
#define maxl 10

int n,m;
char s[maxn][maxl];
int id[maxm],eu[maxm],ev[maxm],ew[maxm],pnt[maxn];

int cmp(const int &i,const int &j){ return ew[i]<ew[j]; }
int find(int x){ if(x!=pnt[x]) pnt[x]=find(pnt[x]); return pnt[x]; }

int Kruskal(){
	int ret=0,i,j,p;
	for(i=1;i<=n;i++) pnt[i]=i;
	for(i=0;i<m;i++) id[i]=i;
	std::sort(id,id+m,cmp);
	for(j=-1,i=1;i<n;i++){
		while( p=id[++j], find(eu[p])==find(ev[p]) );
		ret+=ew[p];pnt[find(ev[p])]=find(eu[p]);
	}
	return ret;
}

void work(){
	int i,j,k,d;m=0;
	for(i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			for(d=0,k=0;k<7;k++)
				if(s[i][k]!=s[j][k])d++;
			eu[m]=i;ev[m]=j;ew[m++]=d;
		}
	//cout<<"m="<<m<<endl;
	printf("The highest possible quality is 1/%d.\n",Kruskal());
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}
