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

#define N 510
#define K 260
#define S 2100
#define NUM 260

int n,m,q,num;
int a[NUM];
int f[K],g[K];

int min(const int &i,const int &j){ return (i<j)?i:j; }
int max(const int &i,const int &j){ return (i>j)?i:j; }

int Call(const int &i,const int &x1,const int &y1,const int &x2,const int &y2){
	int ret=0,k,tmp;
	// ---
	k=0;if(i>=x1 && i<=x2)k++;if(i!=n-i-1 && n-i-1 >= x1 && n-i-1<=x2)k++;
	if(k){
		tmp=min(m-i-1,y2)-max(i  ,y1)+1;
		if(tmp<0)tmp=0;
		ret+=tmp*k;
	}
	// |||
	k=0;if(i>=y1 && i<=y2)k++;if(i!=m-i-1 && m-i-1 >= y1 && m-i-1<=y2)k++;
	if(k){
		tmp=min(n-i-2,x2)-max(i+1,x1)+1;
		if(tmp<0)tmp=0;
		ret+=tmp*k;
	}

	return ret;
}

void work(){
	int i,k;
	
	num=(min(n,m)+1)>>1;
	
	for(i=0;i<num;i++)scanf("%d",&a[i]);
	memset(g,0x7f,sizeof(g));
	
	scanf("%d",&q);
	while(q--){
		int x1,y1,x2,y2;
		int kid,idx,val;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
		kid=idx=val=0;
		for(i=0;i<num;i++){
			k=Call(i,x1,y1,x2,y2);
			if(!k)continue;
			//printf("%d+=%d g[%d]=%d\n",a[i],k,a[i],g[a[i]]);
			if(g[a[i]]!=q){ g[a[i]]=q;f[a[i]]=0;kid++; }
			f[a[i]]+=k;
			if(f[a[i]]>val || (f[a[i]]==val && a[i]<idx)){
				val=f[a[i]];
				idx=a[i];
			}
		}
		printf("%d %d %d\n",kid,idx,val);
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

