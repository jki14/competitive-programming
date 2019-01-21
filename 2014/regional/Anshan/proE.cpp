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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

struct statues{
	int d, p;
	statues();
	statues(const int _d, const int _p){
		d=_d;p=_p;
	}
};

int n,m,s;
int nbor[66][66], num[66];
double f[10086][66];
int mark[10086][66];

void Core(){
	scanf("%d%d%d",&n,&m,&s);
	memset(num,0,sizeof(num));
	for(int u,v,i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		--u;--v;
		nbor[u][num[u]++]=v;
		nbor[v][num[v]++]=u;
	}
	memset(mark,0xff,sizeof(mark));
	queue<statues> que;
	for(int i=0;i<n;i++){
		double _p=1.0/(n*1.0);
		for(int j=0;j<n;j++){
			if(i==j)continue;
			f[0][j]=_p;
			mark[0][j]=i;
			que.push(statues(0, j));
		}
		while(!que.empty()){
			int d=que.front().d, p=que.front().p;
			if(!num[p])continue;
			int _d=d+1;_p=1.0/(num[p]*1.0);
			for(int j=0;j<num[p];j++){int v=nbor[p][j];
				if(i==v)continue;
				if(mark[_d][v]!=i){
					f[_d][v]=0.0;
					mark[_d][v]=i;
					if(_d+1<=s)
						que.push(statues(_d, v));
				}
				f[_d][v]+=f[d][p]*_p;
			}
			que.pop();
		}
		double sum=0.0;
		for(int j=0;j<n;j++)
			if(mark[s][j]==i)sum+=f[s][j];
		printf("%.9f\n",sum);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--)Core();
	return 0;
}

