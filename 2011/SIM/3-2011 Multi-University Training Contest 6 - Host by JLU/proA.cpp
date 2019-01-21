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

#define maxn 110000
#define maxm 1100000

map<int,int> s;
map<int,int>::iterator it;

int n,m,q,num;
int x[maxn],y[maxn],z[maxn],t[maxn],r[maxn],id[maxn];
int a[maxm],lowbit[maxm],ret[maxn];
double c[maxm],w[maxn],res[maxn];

void add(int x,const double &d){
	for(;x<=m;x+=lowbit[x]){ c[x]+=d;a[x]++; }
}

double sum(int x,int &num){
	double ret=0.0;num=0;
	for(;x>0;x-=lowbit[x]){
       		ret+=c[x];
		num+=a[x];
	}
	return ret;
}

double que(const int &x,const int &y,int &num){
	double ret;
	int top,low;
	ret=sum(y,top)-sum(x-1,low);
	num=top-low;
	return ret;
}

int cmp(const int &i,const int &j){
	if(x[i]!=x[j])return x[i]<x[j];
	return t[i]<t[j];
}

void work(){
	int i,j,tot;
	int sx,sy,tx,ty;
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	memset(res,0,sizeof(res));
	memset(ret,0,sizeof(ret));
	s.clear();m=num=0;
	
	for(i=0;i<n;i++){

		scanf("%d%d%lf",&x[num],&y[num],&w[num]);
		s.insert(pair<int,int>(y[num],0));

		t[num]=0;z[num]=y[num];
		id[num]=num;num++;

	}

	for(i=0;i<q;i++){
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		s.insert(pair<int,int>(sy,0));
		s.insert(pair<int,int>(ty,0));

		y[num]=sy;z[num]=ty;r[num]=i;
		x[num]=sx-1;t[num]=1;id[num]=num;num++;

		y[num]=sy;z[num]=ty;r[num]=i;
		x[num]=tx;t[num]=2;id[num]=num;num++;
	}

	for(it=s.begin();it!=s.end();it++)(*it).second=++m;
	for(i=0;i<num;i++){ y[i]=s[y[i]]; z[i]=s[z[i]]; }

	sort(id,id+num,cmp);
	for(j=0;j<num;j++){i=id[j];
		switch(t[i]){
			case 0:
				add(y[i],w[i]);

				//printf("Add %d %.2f\n",y[i],w[i]);

				break;
			case 1:
				res[r[i]]-=que(y[i],z[i],tot);
				ret[r[i]]-=tot;

				//printf("que --- %d->%d\n",y[i],z[i]);

				break;
			case 2:
				res[r[i]]+=que(y[i],z[i],tot);
				ret[r[i]]+=tot;
				
				//printf("que +++ %d->%d\n",y[i],z[i]);

		}
	}

	for(i=0;i<q;i++)printf("%.2f/%d\n",res[i],ret[i]);
}

void init(){
	for(int i=0;i<maxm;i++)lowbit[i]=i&(-i);
}

int main(){
	init();
	while(scanf("%d%d",&n,&q)!=EOF)
		work();
	return 0;
}

