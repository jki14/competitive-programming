#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 1000
#define le (*it).second.u
#define ri (*it).second.v

struct line{
	int u,v;
	line(){ u=0;v=0; }
	line(const int &v0,const int &v1){ u=v0;v=v1; }
};

int n;
int	l[maxn],ptn[maxn];
double x[maxn],y[maxn];
double g[maxn][maxn],ans;
bool del[maxn];

multimap<double,line> s;
multimap<double,line>::iterator it;

double dist(const int &u,const int &v){
	//cout<<"x["<<u<<"]="<<x[u]<<" y["<<u<<"]="<<y[u]<<endl;
	//cout<<"x["<<v<<"]="<<x[v]<<" y["<<v<<"]="<<y[v]<<endl;
	//cout<<sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]))<<endl;
	double res=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
	return res;
}

void doit(){
	int i,j;n*=2;ans=(double)-1;
	memset(del,0,sizeof(del));s.clear();
	for(i=0;i<n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(i=0;i<n;i++){
		if(!(i&1)){ptn[i]=i+1;ptn[i+1]=i;}
		for(j=i+1;j<n;j++){
			if(ptn[i]==j)continue;
			l[i]++;l[j]++;
			g[i][j]=dist(i,j);
			s.insert(pair<double,line>(g[i][j],line(i,j)));
		}
	}
	for(it=s.begin();it!=s.end();it++){
		//cout<<"x:"<<(*it).first<<endl;
		l[le]--;l[ri]--;
		if(l[le]==0 && del[ptn[le]]==false)del[le]=true;
		if(l[ri]==0 && del[ptn[ri]]==false)del[ri]=true;
	}
	for(i=0;i<n;i++)
		//cout<<" "<<del[i];
	//cout<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if((!del[i])&&(!del[j])){
				if(ans<g[i][j])ans=g[i][j];
			}
	//cout<<"g[1][3]="<<g[1][3]<<endl;
	//cout<<":"<<x[1]<<":"<<y[1]<<" "<<x[3]<<":"<<y[3]<<endl;
	//cout<<g[1][3]<<endl;
	printf("%.2lf\n",ans/2);
}

int main(){
	while(scanf("%d",&n)!=EOF)doit();
	return 0;
}
