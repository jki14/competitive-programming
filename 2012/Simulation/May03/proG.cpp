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

#define N 110000
#define S 1100000
#define K 3

#define L (i<<1)+1
#define R (i<<1)+2

#define res (val[2][0]/((double)(cnt[0]-1)))

const double eps =1e-8;

struct myComp{
	bool operator () (const double &x,const double &y){
		return x>y+eps;
	}
};

int n;
double p[N],d[N];
int cnt[S];
double val[K][S];

map<double,int,myComp> s;
map<double,int,myComp>::iterator it;
vector<int> pnt[N];int num;

double ans1,ans2,tim[N];

void build(const int &i,const int &l,const int &r){
	if(l<r){
		int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		cnt[i]=cnt[L]+cnt[R];
		for(int k=0;k<K;k++){
			val[k][i]=val[k][L]+val[(k+cnt[L])%K][R];
		}
	}else{
		cnt[i]=1;
		for(int k=0;k<K;k++)val[k][i]=p[l]*(k+1);
	}
}

void del(const int &i,const int &l,const int &r,const int &x){
	if(x<l || x>r)return;
	if(l<r){
		int mid=(l+r)>>1;
		del(L,l,  mid,x);
		del(R,mid+1,r,x);
		cnt[i]=cnt[L]+cnt[R];
		for(int k=0;k<K;k++){
			val[k][i]=val[k][L]+val[(k+cnt[L])%K][R];
		}
	}else{
		cnt[i]=0;for(int k=0;k<K;k++)val[k][i]=0.0;
	}
}

void mysort(const int &l,const int &r){
	int i=l,j=r,mid=d[(l+r)>>1];
	do{
		while(d[i]<mid)i++;
		while(d[j]>mid)j--;
		if(i<=j){
			swap(d[i],d[j]);
			swap(p[i],p[j]);
			i++;j--;
		}
	}while(i<=j);
	if(i<r)mysort(i,r);
	if(l<j)mysort(l,j);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){

		scanf("%d",&n);p[0]=d[0]=0.0;s.clear();num=0;
		for(int i=1;i<=n;i++)scanf("%lf",&p[i]); 
		for(int i=1;i<=n;i++)scanf("%lf",&d[i]);
		
		mysort(1,n);for(int i=1;i<=n;i++)s.insert(pair<double,int>(d[i]-d[i-1],0));

		for(it=s.begin();it!=s.end();it++){ 
			pnt[num].clear();tim[num]=(*it).first;
			(*it).second=num++; 
		}
		for(int i=1;i<=n;i++){
			it=s.find(d[i]-d[i-1]);
			pnt[(*it).second].push_back(i);
		}

		build(0,0,n);
		ans1=tim[0];ans2=res;

		//printf("Full tim=%.6f result=%.6f\n",tim[0],res);

		for(int i=0;i+1<num;i++){
			for(int j=0;j<(int)pnt[i].size();j++)del(0,0,n,pnt[i][j]);

			//printf("for time=%.6f result=%.6f\n",tim[i+1],res);

			if(ans2<res+eps){
				ans1=tim[i+1];
				ans2=res;
			}
		}

		printf("%.6f %.6f\n",ans1,ans2);
	}
	return 0;
}

