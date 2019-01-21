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

#define N 210

int a[N][N],n,tar,T;
int r[N],c[N],dia0,dia1;
map<int,int> s,g;
map<int,int>::iterator it;

void Add(const int &x,map<int,int> &s){
	it=s.find(x);
	if(it==s.end())
		s.insert(pair<int,int>(x,1));
	else
		(*it).second++;
}

void Del(const int &x,map<int,int> &s){
	it=s.find(x);
	if(it!=s.end()){
		(*it).second--;
		if(!(*it).second)s.erase(it);
	}
}

void work(){
	scanf("%d",&n);s.clear();
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=i*n+j+1;
	for(int i=0;i<n;i++){
		r[i]=c[i]=0;
		for(int j=0;j<n;j++){
			r[i]+=a[i][j];
			c[i]+=a[j][i];
		}
		Add(r[i],s);Add(c[i],s);
	}
	dia0=dia1=0;for(int i=0;i<n;i++){ dia0+=a[i][i];dia1+=a[i][n-i-1]; }Add(dia0,s);Add(dia1,s);
	tar=(n<<1)+2;//printf("s.size=%d\n",(int)s.size());
	while((int)s.size()<tar){
		int x0,y0,x1,y1;
		x0=rand()%n;y0=rand()%n;
		x1=rand()%n;y1=rand()%n;
		if(x0==x1 && y0==y1)continue;
		
		g=s;
		Del(r[x0],g);Add(r[x0]-a[x0][y0]+a[x1][y1],g);
		Del(c[y0],g);Add(c[y0]-a[x0][y0]+a[x1][y1],g);
		if(x0==y0    ){ Del(dia0,g);Add(dia0-a[x0][y0]+a[x1][y1],g); }
		if(x0+y0==n-1){ Del(dia1,g);Add(dia1-a[x0][y0]+a[x1][y1],g); }
		
		Del(r[x1],g);Add(r[x1]+a[x0][y0]-a[x1][y1],g);
		Del(c[y1],g);Add(c[y1]+a[x0][y0]-a[x1][y1],g);
		if(x1==y1    ){ Del(dia0,g);Add(dia0+a[x0][y0]-a[x1][y1],g); }
		if(x1+y1==n-1){ Del(dia1,g);Add(dia1+a[x0][y0]-a[x1][y1],g); }

		if(g.size()>s.size()){	
			Del(r[x0],s);Add(r[x0]-a[x0][y0]+a[x1][y1],s);r[x0]+=a[x1][y1]-a[x0][y0];
			Del(c[y0],s);Add(c[y0]-a[x0][y0]+a[x1][y1],s);c[y0]+=a[x1][y1]-a[x0][y0];
			if(x0==y0    ){ Del(dia0,s);Add(dia0-a[x0][y0]+a[x1][y1],s);dia0+=a[x1][y1]-a[x0][y0]; }
			if(x0+y0==n-1){ Del(dia1,s);Add(dia1-a[x0][y0]+a[x1][y1],s);dia1+=a[x1][y1]-a[x0][y0]; }
			
			Del(r[x1],s);Add(r[x1]+a[x0][y0]-a[x1][y1],s);r[x1]+=a[x0][y0]-a[x1][y1];
			Del(c[y1],s);Add(c[y1]+a[x0][y0]-a[x1][y1],s);c[y1]+=a[x0][y0]-a[x1][y1];
			if(x1==y1    ){ Del(dia0,s);Add(dia0+a[x0][y0]-a[x1][y1],s);dia0+=a[x0][y0]-a[x1][y1]; }
			if(x1+y1==n-1){ Del(dia1,s);Add(dia1+a[x0][y0]-a[x1][y1],s);dia1+=a[x0][y0]-a[x1][y1]; }

			swap(a[x0][y0],a[x1][y1]);
		}
	}
	printf("Case #%d:\n",T);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

