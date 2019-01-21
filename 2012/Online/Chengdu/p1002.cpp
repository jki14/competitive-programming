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

#define N 500

const int inf=0x3fffffff;
const int dis=inf>>1;

int c[N][N];
int hig[N],cap[N];
int n,m,flow,aug;
int S,T,src,des;

int check(int v){
	int i,augo,minh;
    	minh=n;
    	augo=aug;
    	if(v==T){
        	flow+=aug;
        	return true;
    	}
    	for(i=1;i<=n;i++){
        	if(c[v][i]>0){
            		if(hig[i]+1==hig[v]){
                		if(c[v][i]<aug)aug=c[v][i];
                		if(check(i)) break;
                		if(hig[S]>=n) return false;
                		aug=augo;
            		}
            		if(hig[i]<minh)minh=hig[i];
        	}
    	}
    	if(i>n){
        	cap[hig[v]]--;
        	if(cap[hig[v]]==0) hig[S]=n;
        	hig[v]=minh+1;
        	cap[hig[v]]++;
        	return false;
    	}else{
        	c[v][i]-=aug;c[i][v]+=aug;
        	return true;
    	}
}
int main(){
	int i,tmp;
	while(scanf("%d%d",&n,&m)!=EOF){
		scanf("%d%d",&src,&des);
        	memset(c,0,sizeof(c));
        	memset(hig,0,sizeof(hig));
        	memset(cap,0,sizeof(cap));
		n+=2;for(i=1;i<=n-2;i++){
            		scanf("%d",&tmp);
            		c[i][i+n]=tmp;
        	}
		S=n-1;T=n;c[S][S+n]=0;c[T][T+n]=0;
		c[S+n][src]=c[src+n][S]=c[des+n][T]=c[T+n][des]=dis;
        	for(i=0;i<m;i++){int u,v;
            		scanf("%d %d",&u,&v);
            		c[u+n][v]=c[v+n][u]=dis;
        	}
        	S=S+n;n<<=1;cap[0]=n;flow=0;
       	 	while(hig[S]<n){
            		aug=inf;
            		check(S);
        	}
        	printf("%d\n",flow);
    	}
    	return 0;
}
