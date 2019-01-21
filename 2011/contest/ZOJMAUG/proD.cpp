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
#include<set>
#include<map>
using namespace std;

#define maxn 2100
#define maxm 11000

#define L (i<<1)+1
#define R (i<<1)+2

int n,num,ANS;
int a[maxn],b[maxn],c[maxn],d[maxn],id[maxn];
int val[maxm],dlt[maxm],que[maxn],T;
int list[maxn],u[maxn],v[maxn],w[maxn],k[maxn];
int A,B,C,Low,Hig;

int cmpC(const int &i,const int &j){ return c[i]<c[j]; }
int cmpK(const int &i,const int &j){ return k[i]<k[j]; }

void update(const int &i,const int &l,const int &r,const int &u,const int &v,const int &w){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		val[i]+=w;
		dlt[i]+=w;
	}else{int mid=(l+r)>>1;
		if(dlt[i]){
			update(L,l,  mid,Low,Hig,dlt[i]);
			update(R,mid+1,r,Low,Hig,dlt[i]);
			dlt[i]=0;
		}
		update(L,l,  mid,u,v,w);
		update(R,mid+1,r,u,v,w);
		val[i]=min(val[L],val[R]);
	}
}

int Call(){num=0;

	//printf("Call\n");

	int i,j,ret;ret=0;
	for(;T;T--){i=que[T];
		
		//printf("	STD:%d %d %d %d\n",a[i],b[i],c[i],d[i]);
		
		list[num]=num;u[num]=a[i]-A;v[num]=a[i];w[num]= d[i];k[num++]=b[i];
		list[num]=num;u[num]=a[i]-A;v[num]=a[i];w[num]=-d[i];k[num++]=b[i]+B+1;
	}
	sort(list,list+num,cmpK);

	memset(val,0,sizeof(val));
	memset(dlt,0,sizeof(dlt));

	for(j=0;j<num;j++){i=list[j];

		//printf("	%d->%d %d\n",u[i],v[i],w[i]);

		update(0,Low,Hig,u[i],v[i],w[i]);
		if(j==num-1 || k[list[j+1]]!=k[i])ret=min(ret,val[0]);
	}
	return ret;
}

void work(){
	int i;
	int head,tail;ANS=Low=Hig=0;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		if(d[i]>=0){ n--;i--;continue; }
		Low=min(Low,a[i]);
		Hig=max(Hig,a[i]);
		id[i]=i;
	}
	scanf("%d %d %d",&A,&B,&C);
	sort(id,id+n,cmpC);
	for(head=tail=0;head<n;){
		while(tail+1 < n && c[id[tail+1]]-c[id[head]]<=C)tail++;

		//printf("head=%d tail=%d\n",head,tail);
		for(T=1;T<=tail-head+1;T++)que[T]=id[head+T-1];
		T--;ANS=min(ANS,Call());

		if(tail==n-1)break;
		while(head+1 < n && c[id[head]]==c[id[head+1]])head++;head++;
	}

	if(!ANS)
		printf("Error 404, mahou shoujo not found!\n");
	else
		printf("%d\n",ANS);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

