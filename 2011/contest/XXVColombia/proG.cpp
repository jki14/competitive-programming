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

#define M 110000
#define S 210000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=0x3fffffff;

int n,m,num,head,tail;
int pos[M],des[M],u[M],v[M],id[M];
int c[S],f[S];

map<int, int> s;
map<int, int>::iterator it;

inline int max(const int &x,const int &y){
	return (x>y)?x:y;
}

inline int min(const int &x,const int &y){
	return (x<y)?x:y;
}

int cmp(const int &i,const int &j){
	return v[i]<v[j];
	/*if(v[i]!=v[j])return v[i]<v[j];
	return u[i]<u[j];*/
}

void update(const int &i){
	c[i]=min(c[L],c[R]);
}

void modify(const int &i,const int &l,const int &r,const int &pos,const int &val){
	if(pos<l || pos>r)return;
	if(l==r){
		c[i]=min(c[i],val);
	}else{ int mid=(l+r)>>1;
		modify(L,l,  mid,pos,val);
		modify(R,mid+1,r,pos,val);
		update(i);
	}
}

int querry(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r)return inf;
	if(u<=l && r<=v){
		return c[i];
	}else{ int mid=(l+r)>>1;
		return min(
			querry(L,l,  mid,u,v),
			querry(R,mid+1,r,u,v));
	}
}

void work(){
	memset(c,0x3f,sizeof(c));
	memset(f,0x3f,sizeof(f));
	s.clear();num=0;
	s.insert(pair<int,int>(0,0));
	s.insert(pair<int,int>(n,0));

	for(int i=0;i<m;i++){id[i]=i;
		scanf("%d%d",&pos[i],&des[i]);
		u[i]=max(0,pos[i]-des[i]);
		v[i]=min(n,pos[i]+des[i]);
		s.insert(pair<int,int>(u[i],0));if(u[i]>0)s.insert(pair<int,int>(u[i]-1,0));
		s.insert(pair<int,int>(v[i],0));if(v[i]<n)s.insert(pair<int,int>(v[i]+1,0));
	}
	
	for(it=s.begin();it!=s.end();it++){
		(*it).second=++num;
	}
	if(num>41000)while(1);
	for(int i=0;i<m;i++){
		u[i]=s[u[i]];
		v[i]=s[v[i]];
		//printf("%d->%d\n",u[i],v[i]);
	}
	head=s[0];tail=s[n];
	sort(id,id+m,cmp);

	f[head]=0;modify(0,head,tail,head,0);
	for(int I=0;I<m;I++){int i=id[I];
		f[v[i]]=min(f[v[i]],querry(0,head,tail,u[i],v[i])+1);
		modify(0,head,tail,v[i],f[v[i]]);
	}

	if(f[tail]>m)
		printf("%d\n",-1);
	else
		printf("%d\n",m-f[tail]);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && (n || m))
		work();
	return 0;
}

