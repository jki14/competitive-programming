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

#define N 1100

#define X x[apos]
#define Y y[bpos]

int n,ans,apos,bpos,now;
int a[N],b[N];
int x[N],y[N];
int fir[N],sec[N];

multimap<int,int,greater<int> > s;
multimap<int,int,greater<int> >::iterator it;

int cmpa(const int &x,const int &y){ return a[x]<a[y]; }
int cmpb(const int &x,const int &y){ return b[x]<b[y]; }

void core(){
	scanf("%d",&n);for(int i=0;i<n;i++){ scanf("%d%d",&a[i],&b[i]);x[i]=y[i]=i; }
	memset(fir,0,sizeof(fir));memset(sec,0,sizeof(sec));s.clear();
	ans=now=apos=bpos=0;sort(x,x+n,cmpa);sort(y,y+n,cmpb);
	while(bpos<n){
		if(b[Y]<=now){
			now+=2-fir[Y];
			fir[Y]=sec[Y]=1;
			bpos++;ans++;
			continue;
		}
		for(;apos<n && a[X]<=now;apos++){
			if(fir[X])continue;
			s.insert(pair<int,int>(b[X],X));
		}
		for(it=s.begin();it!=s.end() && fir[(*it).second];it=s.begin())s.erase(it);
		if(!s.empty()){
			it=s.begin();fir[(*it).second]=1;s.erase(it);
			now+=1;ans++;
		}else{
			printf("Too Bad");
			return;
		}
	}
	printf("%d",ans);
}

int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		core();
		printf("\n");
	}
	return 0;
}
