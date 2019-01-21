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
#define maxx 500
#define maxy 5000
#define LEN 11

#define CI const int

#define L (i<<1)+1
#define R (i<<1)+2

#define LHIG 100
#define HHIG 200

const double eps=1e-4;

const double none=-1.0;

struct myComp{
	bool operator () (const double &a,const double &b){
		return a+eps<b;
	}
};

map<double,int,myComp> s;
map<double,int,myComp>::iterator it;

int n,m;

int opt[maxn],hig[maxn];
int higlow[maxn],highig[maxn];
double art[maxn],val[maxn];
double artlow[maxn],arthig[maxn];
double c[maxx][maxy];

char sopt[LEN];

void clr(){
	for(int i=0;i<maxx;i++)
		for(int j=0;j<maxy;j++)
			c[i][j]=none;
}

void YInsert(const int &k,const int &i,const int &lowy,const int &higy,const int &valy,const double &dval){
	if(valy<lowy || valy>higy)return;
	c[k][i]=max(c[k][i],dval);
	if(lowy<higy){
		int midy=(lowy+higy)>>1;
		YInsert(k,L,lowy,  midy,valy,dval);
		YInsert(k,R,midy+1,higy,valy,dval);
	}
}

void XInsert(const int &i,const int &lowx,const int &higx,const int &valx,const int &valy,const double &dval){
	if(valx<lowx || valx>higx)return;
	YInsert(i,0,1,m,valy,dval);
	if(lowx<higx){
		int midx=(lowx+higx)>>1;
		XInsert(L,lowx,  midx,valx,valy,dval);
		XInsert(R,midx+1,higx,valx,valy,dval);
	}
}

double YQuerry(CI &k,CI &i,CI &lowy,CI &higy,CI &lowart,CI &higart){
	if(lowart>higy || higart<lowy)return none;
	if(lowart<=lowy && higy<=higart)return c[k][i];
	int midy=(lowy+higy)>>1;
	return max(
			YQuerry(k,L,lowy,  midy,lowart,higart),
			YQuerry(k,R,midy+1,higy,lowart,higart)
			);
}

double XQuerry(CI &i,CI &lowx,CI &higx,CI &lowhig,CI &highig,CI &lowart,CI &higart){
	if(lowhig>higx || highig<lowx)return none;
	if(lowhig<=lowx && higx<=highig){
		return YQuerry(i,0,1,m,lowart,higart);
	}
	int midx=(lowx+higx)>>1;
	return max(
			XQuerry(L,lowx,  midx,lowhig,highig,lowart,higart),
			XQuerry(R,midx+1,higx,lowhig,highig,lowart,higart)
			);
}

void work(){
	int i;double ret;
	
	s.clear();clr();m=0;
	
	for(i=0;i<n;i++){
		scanf("%s",sopt);
		if(sopt[0]=='I'){
			opt[i]=1;
			scanf("%d%lf%lf",&hig[i],&art[i],&val[i]);
			s.insert(pair<double,int>(art[i],0));
		}else{
			opt[i]=0;
			scanf("%d%d%lf%lf",&higlow[i],&highig[i],&artlow[i],&arthig[i]);
			if(higlow[i]>highig[i])swap(higlow[i],highig[i]);
			if(artlow[i]>arthig[i])swap(artlow[i],arthig[i]);
			s.insert(pair<double,int>(artlow[i],0));
			s.insert(pair<double,int>(arthig[i],0));
		}
	}
	for(it=s.begin();it!=s.end();it++){
		//printf("%.6f\n",(*it).first);
		(*it).second=++m;
	}

	for(i=0;i<n;i++){
		if(opt[i]){
			XInsert(0,LHIG,HHIG,hig[i],s[art[i]],val[i]);
		}else{
			ret=XQuerry(0,LHIG,HHIG,higlow[i],highig[i],s[artlow[i]],s[arthig[i]]);
			if(ret<0-eps)
				printf("-1\n");
			else printf("%.1f\n",ret);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

