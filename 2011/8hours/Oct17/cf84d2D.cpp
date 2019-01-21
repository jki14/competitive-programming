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

#define N 3100
#define L 9

const double eps=1e-12;

int a[N],n,m;
double inv[N];
int lef[N],rig[N],p[N],v[N];
int pl,pr,vl,vr,k;
int num;

const int inf=0x3fffffff;

void build(const int &x){

	//printf("num=%d\n",num);

	if(x)
		a[n++]=num;
	else
		n=num=0;

	if(x==L)return;

	num=num*10+4;
	build(x+1);
	num=num/10;

	num=num*10+7;
	build(x+1);
	num=num/10;
}

void init(){m=0;
	for(int i=0;i<=n;i++){
		inv[m]=((double)i)+0.51;
		if(i!=  0)lef[m]=a[i-1]+1;else lef[m]=0;
		rig[m]=a[i]-1;m++;
		if(i==n)break;
		//printf("a[i]=%d\n",a[i]);
		inv[m]=((double)i)+1.00;
		lef[m]=rig[m]=a[i];m++;
	}
}

void work(){
	/* For Unsimple Case
	if(k==1){
		int l=max(pl,vl),r=min(pr,vr);
		double ans=0.0;
		for(int i=0;i<n;i++)
			if(a[i]>=l && a[i]<=r)ans+=1.0;
		ans/=((double)(pr-pl+1))*((double)(vr-vl+1));
		printf("%.10f\n",ans);
		return;
	}*/
	
	/* Init */
	memset(p,0,sizeof(p));memset(v,0,sizeof(v));

	//printf("m=%d\n",m);
	for(int i=0;i<m;i++){
		//printf("%d->%d %.2f\n",lef[i],rig[i],inv[i]);
		if(!(lef[i]>pr || rig[i]<pl)){
			int l=max(lef[i],pl),r=min(rig[i],pr);
			p[i]=r-l+1;
		}
		if(!(lef[i]>vr || rig[i]<vl)){
			int l=max(lef[i],vl),r=min(rig[i],vr);
			v[i]=r-l+1;
		}
	}

	/* Core */
	double ans=0.0;
	for(int i=0;i<m;i++){
		if(!p[i])continue;
		for(int j=0;j<m;j++){
			if(!v[j])continue;
			//printf("inv[i]=%.2f p[i]=%d inv[j]=%.2f v[j]=%d\n",inv[i],p[i],inv[j],v[j]);
			//p->v
			if(((((int)(inv[j]))-round(inv[i])+1)==k) || ((((int)(inv[i]))-round(inv[j])+1)==k))
				ans+=((double)(p[i]))*((double)(v[j]));
		}
	}
	ans/=((double)(pr-pl+1))*((double)(vr-vl+1));
	printf("%.10f\n",ans);
}

int main(){
	build(0);sort(a,a+n);a[n]=inf;init();
	while(scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k)!=EOF)
		work();
	return 0;
}

