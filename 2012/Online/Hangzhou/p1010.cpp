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

#define S 110000
#define C 8

#define L (i<<1)+1
#define R (i<<1)+2

typedef long long lld;

const int out[C]={ 0,1,2,4,3,5,6,7 };
const int inf=0x7fffffff;

int cov[S][C],len[S][C],n,m,num;
int a[S],u[S],v[S],col[S],d[S],id[S];
int du[S],dv[S],f[S],bit[C];

lld ans[C];

map<int, int> s;
map<int, int>::iterator it;

char chars[10];

int cmp(const int &i,const int &j){ return a[i]<a[j]; }

void build(const int &i,const int &l,const int &r){
	if(l==r)
		len[i][0]=f[r+1]-f[l];
	else{
		int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		len[i][0]=len[L][0]+len[R][0];
	}
}

void update(const int &i,const int &l,const int &r){
	
	if(l!=r)
		for(int j=0;j<C;j++)len[i][j]=len[L][j]+len[R][j];
	else{
		for(int j=1;j<C;j++) len[i][j]=0;
		len[i][0]=f[r+1]-f[l];
	}

	int path=0;for(int j=0;j<3;j++)if(cov[i][j])path|=bit[j];
	for(int j=0;j<C;j++)if((j&path)!=path){
		len[i][j|path]+=len[i][j];
		len[i][j]=0;
	}
}

void modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d,const int &col){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		cov[i][col]+=d;
	}else{
		int mid=(l+r)>>1;
		modify(L,l,  mid,u,v,d,col);
		modify(R,mid+1,r,u,v,d,col);
	}
	update(i,l,r);
}

int main(){
	int T;scanf("%d",&T);for(int i=0;i<C;i++)bit[i]=1<<i;
	for(int tim=1;tim<=T;tim++){printf("Case %d:\n",tim);
		scanf("%d",&n);s.clear();s.insert(pair<int,int>(0,0));s.insert(pair<int,int>(inf,0));
		for(int i=m=num=0;i<n;i++){
			scanf("%s",chars);int thecol=(chars[0]=='R')?0:((chars[0]=='G')?1:2);

			//printf("%s col=%d\n",chars,thecol);

			int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			a[m]=x1;du[m]=y1;dv[m]=y2;id[m]=m;d[m]= 1;col[m]=thecol;++m;
			a[m]=x2;du[m]=y1;dv[m]=y2;id[m]=m;d[m]=-1;col[m]=thecol;++m;
			s.insert(pair<int,int>(y1,0));s.insert(pair<int,int>(y2,0));
		}
		for(it=s.begin();it!=s.end();it++){ (*it).second=++num;f[num]=(*it).first; }
		memset(cov,0,sizeof(cov));
		memset(len,0,sizeof(len));
		memset(ans,0,sizeof(ans));
		build(0,1,num);sort(id,id+m,cmp);

		for(int k=0;k<m;k++){int i=id[k];
			if(k){ for(int j=1;j<C;j++)ans[j]+=(((lld)a[i])-((lld)a[id[k-1]]))*((lld)len[0][j]); }
			u[i]=s[du[i]];v[i]=s[dv[i]]-1;
			modify(0,1,num,u[i],v[i],d[i],col[i]);
		}

		for(int j=1;j<C;j++)printf("%I64d\n",ans[out[j]]);
	}

	printf("\n\n");

	return 0;
}

