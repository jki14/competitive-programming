#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100

#define L (i<<1)+1
#define R (i<<1)+2

const double eps=1e-6;
const double inf=1000000000.0;

const int zero=0;

int timer;

double s[maxn],len[maxn],res;
double a[maxn],du[maxn],dv[maxn];
int c[maxn],n,m,num;
int u[maxn],v[maxn],id[maxn],d[maxn];

int cmp(const int &i,const int &j){
	return a[i]+eps<a[j];
}

int find(const double &x){
	int l=1,r=num,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(s[mid]-eps<x && x+eps<s[mid+1])return mid;
		if(s[mid]-eps<x)
			l=mid+1;
		else
			r=mid-1;
	}
	return zero/zero;
}

double modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(v<l || u>r)return len[i];
	if(u<=l && r<=v){
		c[i]+=d;
		if(c[i]){
			len[i]=s[r+1]-s[l];
			//printf("Cover %d->%d = %.2f\n",l,r,len[i]);
		}
		else
			len[i]=len[L]+len[R];
	}else{int mid=(l+r)>>1;
		double tmp=modify(L,l,  mid,u,v,d)+modify(R,mid+1,r,u,v,d);
		if(!c[i])len[i]=tmp;
	}
	return len[i];
}

void work(){
	int i,k;
	double x1,y1,x2,y2;
	for(i=m=num=0;i<n;i++){
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a[m]=x1;du[m]=y1;dv[m]=y2;id[m]=m;d[m]=1;m++;
		a[m]=x2;du[m]=y1;dv[m]=y2;id[m]=m;d[m]=-1;m++;
		s[++num]=y1;s[++num]=y2;
	}
	s[num+1]=inf;
	s[0]=-inf;
	sort(s,s+num+1);
	//for(i=1;i<=num;i++)printf("%.2f ",s[i]);printf("\n");
	sort(id,id+m,cmp);
	memset(c,0,sizeof(c));
	memset(len,0,sizeof(len));
	res=0.0;
	for(k=0;k<m;k++){i=id[k];
		
		//printf("a[%d]=%.2f\n",i,a[i]);
		//printf("len[0]=%.2f\n",len[0]);
		
		if(k){
			res+=(a[i]-a[id[k-1]])*len[0];
		}
		u[i]=find(du[i]);v[i]=find(dv[i])-1;
		//printf("modify %d->%d %d\n",u[i],v[i],d[i]);
		modify(0,1,num,u[i],v[i],d[i]);
	}
	printf("Test case #%d\nTotal explored area: %.2f\n\n",timer++,res);
}

int main(){
	timer=1;
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

