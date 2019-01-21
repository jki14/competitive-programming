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

#define p id[i]

#define M 1100
#define S 11000

const int inf = 0x3fffffff;

int n,m,k,ans;
int lef[M],rig[M],hig[M],id[M];
int u[S],v[S],w[S],num,now,pla;

int cmp(const int &i,const int &j){ return hig[i]<hig[j]; }

int check(const int &s,const int &t,const int &k){
	for(int i=0;i<num;i++){
		if(u[i]==v[i])continue;
		if((k+1) != w[i] && (k-1) != w[i])continue;
		if(u[i]>t || v[i]<s)continue;
		return 1;
	}
	return 0;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);ans=0;
		for(int i=0;i<m;i++){ scanf("%d%d%d",&lef[i],&rig[i],&hig[i]);id[i]=i; }
		sort(id,id+m,cmp);num=pla=0;now=1;
		for(int i=0;i<m;i++){
			while(i<m && lef[p]!=now && rig[p]!=now)i++;
			if(i<m){
				u[num]=pla;v[num]=pla=hig[p];w[num]=now;now=(lef[p]==now)?rig[p]:lef[p];
				
				//printf("[%d->%d] at %d\n",u[num],v[num],w[num]);

				num++;
			}
		}
		u[num]=pla;v[num]=inf;w[num]=now;
		
		//printf("[%d->%d] at %d\n",u[num],v[num],w[num]);
		
		num++;
		pla=inf;now=k;
		for(int i=m-1;i>=0;i--){
			while(i>=0 && lef[p]!=now && rig[p]!=now)i--;
			if(i>=0){
				int beg=pla,end=hig[p];

				//printf("(%d->%d) at %d\n",end,beg,now);

				if(check(end,beg,now)){ ans=1;break; }
				pla=end;now=(lef[p]==now)?rig[p]:lef[p];
			}
		}if(check(0,pla,now))ans=1;
		if(ans)
			printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
