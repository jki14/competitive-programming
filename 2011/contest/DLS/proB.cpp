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

#define N 510000
#define M 210000
#define S 1100000

#define L (i<<1)+1
#define R (i<<1)+2
#define K 2

typedef long long lld;

int w[K],b,n,m;
int c[S],f[S],lef[S],rig[S],len[S];

map<int,int> s[K];
map<int,int>::iterator it;
int ori[M][K];

int p0[N][K],p1[N][K];
int u[S],v[S],pos[S],id[S],d[S],num;

lld ans;

void update(const int &i){
	if(rig[L]!=len[L] && lef[R]!=len[R]){
		c[i]=c[L]+c[R]+max(0,rig[L]+lef[R]-m+1);
		lef[i]=lef[L];
		rig[i]=rig[R];
		return;
	}
	if(lef[L]==len[L]){
		lef[i]=lef[L]+lef[R];
	}else lef[i]=lef[L];
	if(rig[R]==len[R]){
		rig[i]=rig[R]+rig[L];
	}else rig[i]=rig[R];
	c[i]=c[L]+c[R];
}

void build(const int &i,const int &l,const int &r,const int &k){
	c[i]=f[i]=0;
	lef[i]=rig[i]=len[i]=ori[r+1][k]-ori[l][k];
	if(l<r){int mid=(l+r)>>1;
		build(L,l,  mid,k);
		build(R,mid+1,r,k);
	}
}

void modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		f[i]+=d;
		if(f[i]){
			lef[i]=rig[i]=c[i]=0;
		}else{
			if(l<r)
				update(i);
			else{
				c[i]=0;
				lef[i]=rig[i]=len[i];
			}
		}
	}else{int mid=(l+r)>>1;
		modify(L,l,  mid,u,v,d);
		modify(R,mid+1,r,u,v,d);
		/* Hint Begin*/
		if(!f[i])
		/* Hint End */
			update(i);
	}
}

int count(){
	if(lef[0]==len[0])return max(0,len[0]-m+1);
	return c[0]+max(0,lef[0]-m+1)+max(0,rig[0]-m+1);
}

int cmp(const int &i,const int &j){
	/*if(pos[i]!=pos[j]) return pos[i]<pos[j];
	return d[i]<d[j];*/
	return pos[i]<pos[j];
}

void work(){
	s[0].clear();s[1].clear();
	

	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&p0[i][0],&p0[i][1],&p1[i][0],&p1[i][1]);
		s[0].insert(pair<int,int>(p0[i][0],0));s[0].insert(pair<int,int>(p0[i][0]-1,0));
		s[0].insert(pair<int,int>(p1[i][0],0));s[0].insert(pair<int,int>(p1[i][0]+1,0));
		s[1].insert(pair<int,int>(p0[i][1],0));s[1].insert(pair<int,int>(p0[i][1]-1,0));
		s[1].insert(pair<int,int>(p1[i][1],0));s[1].insert(pair<int,int>(p1[i][1]+1,0));
	}

	ans=0LL;
	for(int k=0;k<2;k++){
		b=num=0;
		s[k].insert(pair<int,int>(1,0));s[k].insert(pair<int,int>(w[k],0));
		for(it=s[k].begin();it!=s[k].end();it++){
			if((*it).first<1 || (*it).first>w[k])continue;
			(*it).second=++b;
			ori[b][k]=(*it).first;
			//printf("%d:%d\n",(*it).first,(*it).second);
		}ori[b+1][k]=ori[b][k]+1;
		
		build(0,1,b,k);
		
		for(int i=0;i<n;i++){
			u[num]=s[k][p0[i][k]];v[num]=s[k][p1[i][k]];pos[num]=p0[i][k^1]  ;d[num]= 1;id[num]=num;num++;
			u[num]=s[k][p0[i][k]];v[num]=s[k][p1[i][k]];pos[num]=p1[i][k^1]+1;d[num]=-1;id[num]=num;num++;
		}
		u[num]=v[num]=d[num]=0;pos[num]=       1;id[num]=num;num++;
		u[num]=v[num]=d[num]=0;pos[num]=w[k^1]+1;id[num]=num;num++;
		sort(id,id+num,cmp);

		for(int I=0;I<num;I++){int i=id[I];
			if(pos[i]>w[k^1])break;

			//printf("OPT: %d-%d modify %d at pos=%d\n",u[i],v[i],d[i],pos[i]);

			modify(0,1,b,u[i],v[i],d[i]);
			if(pos[id[I+1]]>pos[i]){
				
				//printf("Add ANS: count()=%d dpos=%d\n",count(),pos[id[I+1]]-pos[i]);

				ans+=((lld)count())*((lld)(pos[id[I+1]]-pos[i]));
			}
		}
	}

	if(m==1)ans>>=1;
	printf("%lld\n",ans);	
}

int main(){
	while(scanf("%d%d%d%d",&w[0],&w[1],&n,&m)!=EOF)
		work();
	return 0;
}

