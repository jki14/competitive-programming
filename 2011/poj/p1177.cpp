#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 5100
#define maxm 110000
#define maxq 110000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=LONG_MAX;
const int lmt=LONG_MIN;

int n,m,q;
int c[maxm],len[maxm],s[maxq];
int x[maxn],y[maxn],xx[maxn],yy[maxn];
int a[maxq],u[maxq],v[maxq],d[maxq],id[maxq];

int cmp(const int &i,const int &j){ return a[i]<a[j]; }

int find(const int &x){

	//printf("Try Find %d\n",x);

	int l=1,r=m,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(x==s[mid] && x<s[mid+1])return mid;
		if(x>=s[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return 0/0;
}

void Modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(u>v || v<l || u>r)return;
	if(u<=l && r<=v){
		c[i]+=d;
		if(c[i])
			len[i]=s[r+1]-s[l];
		else
			len[i]=len[L]+len[R];
	}else{
		int mid=(l+r)>>1;
		Modify(L,l,  mid,u,v,d);
		Modify(R,mid+1,r,u,v,d);
		if(!c[i])len[i]=len[L]+len[R];
	}
}

void work(){
	int i,j,k,pre,res=0;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x[i],&y[i],&xx[i],&yy[i]);
	}
	for(k=0;k<=1;k++){q=0;m=1;s[0]=lmt;
		for(i=0;i<n;i++){
			swap(x[i],y[i]);swap(xx[i],yy[i]);
			a[q]=x[i];u[q]=y[i];v[q]=yy[i];d[q]= 1;id[q]=q;q++;
			a[q]=xx[i];u[q]=y[i];v[q]=yy[i];d[q]=-1;id[q]=q;q++;
			s[m++]=y[i];s[m++]=yy[i];
		}
		sort(s,s+m);s[m]=inf;
		for(i=0;i<q;i++){ u[i]=find(u[i]);v[i]=find(v[i]); }
		sort(id,id+q,cmp);
		memset(c,0,sizeof(c));memset(len,0,sizeof(len));pre=0;
		for(j=0;j<q;j++){i=id[j];
			Modify(0,1,m,u[i],v[i]-1,d[i]);
			//if(j==q-1 || a[i]<a[id[j+1]]){
				res+=abs(len[0]-pre);
				pre=len[0];
			//}
			//printf("AddEdge %d->%d (%d) len=%d a=%d res=%d\n",s[u[i]],s[v[i]],d[i],len[0],a[i],res);

		}
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

