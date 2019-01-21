#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define maxn 3100

#define k id[i]

const double eps=1e-8;

int T;
int X,S,R,it,n,tot;
int id[maxn];
double b[maxn],e[maxn],w[maxn];
double head,tail,dw;
double x,s,r,t,p,res;

int cmp(const int &i,const int &j){
	return w[i]<w[j];
}

void work(){
	int i;double tmp;
	scanf("%d%d%d%d%d",&X,&S,&R,&it,&n);
	x=(double)X;s=(double)S;r=(double)R;t=(double)it;res=p=0.0;
	for(i=tot=0;i<n;i++){
		scanf("%lf%lf%lf",&head,&tail,&dw);
		if(head>p+eps){
			id[tot]=tot;b[tot]=p;e[tot]=head;w[tot++]=0.0;
		}
		id[tot]=tot;b[tot]=head;e[tot]=tail;w[tot++]=dw;p=tail;
	}
	if(x>p+eps){
		id[tot]=tot;b[tot]=p;e[tot]=x;w[tot++]=0.0;
	}
	sort(id,id+tot,cmp);
	for(i=0;i<tot;i++){
		//printf("Count: %.2lf->%.2lf w=%.2lf\n",b[k],e[k],w[k]);
		if((e[k]-b[k])/(w[k]+r)>t+eps){
			tmp=e[k]-b[k]-(w[k]+r)*t;
			res+=t;t=0.0;res+=tmp/(w[k]+s);
		}else{
			tmp=(e[k]-b[k])/(w[k]+r);
			res+=tmp;t-=tmp;
		}
		//printf("    res=%.6lf t=%.6lf\n",res,t);
	}
	printf("Case #%d: %.10lf\n",T,res);
}

int main(){
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

