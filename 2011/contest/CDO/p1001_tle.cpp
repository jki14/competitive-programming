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

#define N 21000
#define S 110000
#define LEN 21

#define L (i<<1)+1
#define R (i<<1)+2

int T;

int n,m,t;
int sum[S],atk[S],tim[S],cdt[S],scd[S];

char opt[LEN];

void attack(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d);

void fresh(const int &i){
	scd[i]=max(scd[i],max(scd[L],scd[R]));
}

void down(const int &i){
	cdt[L]=max(cdt[L],cdt[i]);scd[L]=max(scd[L],cdt[L]);
	cdt[R]=max(cdt[R],cdt[i]);scd[R]=max(scd[R],cdt[R]);
}

void update(const int &i,const int &l,const int &r){
	if(l==r){
		if(atk[i]){
			if(cdt[i]<tim[i]){
				cdt[i]=tim[i]+t-1;
				scd[i]=cdt[i];
			}else sum[i]++;
		}
	}else{
		down(i);
		fresh(i);
		if(atk[i]){
			int mid=(l+r)>>1;
			attack(L,l,  mid,1,n,tim[i]);
			attack(R,mid+1,r,1,n,tim[i]);
			fresh(i);
		}
	}
	atk[i]=0;
}

void attack(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		if(atk[i])update(i,l,r);
		if(scd[i]<d){
			cdt[i]=d+t-1;
			scd[i]=d+t-1;
			return;
		}
		atk[i]=1;tim[i]=d;
	}else{int mid=(l+r)>>1;
		update(i,l,r);
		attack(L,l,  mid,u,v,d);
		attack(R,mid+1,r,u,v,d);
		fresh(i);
	}
}

int querry(const int &i,const int &l,const int &r,const int &u){
	if(u<l || u>r)return 0;
	if(l==r){
		update(i,l,r);
		return sum[i];
	}else{int mid=(l+r)>>1;
		update(i,l,r);
		int ret=querry(L,l,  mid,u)+querry(R,mid+1,r,u);
		fresh(i);
		return ret;
	}
}

void work(){
	int i,u,v,k;

	scanf("%d%d%d",&n,&m,&t);
	memset(sum,0,sizeof(sum));
	memset(atk,0,sizeof(atk));
	memset(tim,0,sizeof(tim));
	memset(cdt,0,sizeof(cdt));
	memset(scd,0,sizeof(scd));

	printf("Case %d:\n",T);
	for(i=k=0;i<m;i++){
		scanf("%s",opt);
		if(opt[0]=='A'){k++;
			scanf("%d%d",&u,&v);
			attack(0,1,n,u,v,k);
		}else{
			scanf("%d",&u);
			printf("%d\n",querry(0,1,n,u));
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	printf("\n");
	return 0;
}

