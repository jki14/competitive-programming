#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 13
#define maxk 10000

#define now f[p]
#define prev f[p^1]

typedef long long lld;

lld a[maxn],b[maxn];
lld ans,k,path,point;
int n,m,timer;
map<lld,int> f[2];
map<lld,int>::iterator it;

void work(){
	int i,p;
	timer=0;
	a[0]=b[0]=0LL;
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]);
	p=0;now.clear();prev.clear();
	now.insert(pair<lld,int>(0LL,1));
	for(k=1LL;timer<100000;k+=1LL){p=p^1;
		for(it=prev.begin();it!=prev.end();it++){path=(*it).first;
			for(i=0;i<=n;i++){
				point=path+a[i]+b[i]*k;
				now.insert(pair<lld,int>(point,1));
				timer++;
			}
		}
	}
	//printf("Debug Info:\n");dt=0;
	for(it=now.begin();m;m--){
		//printf("%lld ",(*it).first);
		it++;
		/*dt++;if(dt==5){
			printf("\n");dt=0;		
		}*/
	}
	//printf("\n");
	//cout<<"now.size="<<now.size()<<endl;
	ans=(*it).first;
	printf("%lld\n",ans);
}


int main(){
	/*clock_t start,finish;
   	double totaltime;
   	start=clock();*/
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	/*finish=clock();
   	totaltime=(double)(finish-start);
	printf("\nTotalTime=%.10lf\n",totaltime);  
	printf("PS:%.10lf per sec\n",(double)CLOCKS_PER_SEC);*/
	return 0;
}
