#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define lld long long

#define maxv 31000
#define maxw 3100000

#define ll 1
#define rr 31000

#define v id[i]
#define v2 id[i+1]

#define sv sid[i]
#define sv2 sid[i+1]

#define max(x,y) ((x>y)?x:y)

const lld inf=1LL<<60;

//map<lld,int> s;
//map<lld,int>::iterator it;

int n,m,w,h,res;
lld x[maxv],y[maxv];
lld l[maxv],r[maxv];
int c[maxv],id[maxv];

lld s[maxv*2];
int p[maxv*2],lr[maxv*2],sid[maxv*2];

int st[maxw];

int cmpy(const int &i,const int &j){
	if(y[i]==y[j])return c[i]<c[j];
	return y[i]<y[j];
}
int cmps(const int &i,const int &j){ return s[i]<s[j]; }

void update(int ii,int s,int t,int ss,int tt,int k){
	//if(ii==1)cout<<"  Update "<<ss<<"<->"<<tt<<"  "<<k<<endl;
	if(s>tt || t<ss)return;
	if(st[ii]!=-1 && ss<=s && t<=tt){
		//cout<<"   SegTree Point "<<ii<<" +="<<k<<endl;
		st[ii]+=k;
		if(st[ii]>res)res=st[ii];
		return;
	}
	int mid=(s+t)>>1;
	//new Sons
	if(st[ii]!=-1){
		update(ii*2,s,mid,ll,rr,st[ii]);
		update(ii*2+1,mid+1,t,ll,rr,st[ii]);
		st[ii]=-1;
	}
	//update Sons
	update(ii*2,s,mid,ss,tt,k);
	update(ii*2+1,mid+1,t,ss,tt,k);
}

/*int getMax(int ii,int s,int t,int ss,int tt){
	if(s>tt || t<ss)return 0;
	if(st[ii]!=-1) return st[ii];
	int mid=(s+t)>>1;
	int l=getMax(ii*2,s,mid,ss,tt),r=getMax(ii*2+1,mid+1,t,ss,tt);
	return max(l,r);
}*/

void work(){
	int i,k;res=0;
	memset(st,0,sizeof(st));
	for(i=0;i<n;i++){
		scanf("%lld%lld%d",&x[i],&y[i],&c[i]);
		l[n+i]=l[i]=x[n+i]=x[i];
		r[n+i]=r[i]=l[i]+w-1;
		y[i+n]=y[i]+h;c[i+n]=-c[i];
	}n*=2;l[n]=r[n]=x[n]=y[n]=inf;c[n]=0;
	/*s.clear();for(i=0;i<=n;i++){
		s.insert(pair<lld,int>(l[i],0));
		s.insert(pair<lld,int>(r[i],0));
	}
	for(it=s.begin(),i=0;it!=s.end();it++,i++)(*it).second=i;
	for(i=0;i<=n;i++){
		l[i]=(lld)s[l[i]];r[i]=(lld)s[r[i]];id[i]=i;
		//cout<<" At:"<<y[i]<<" "<<l[i]<<"<->"<<r[i]<<" "<<c[i]<<endl;
	}*/
	m=0;k=1;for(i=0;i<=n;i++){ id[i]=i;
		s[m]=l[i];p[m]=i;lr[m]=0;sid[m]=m;m++;
		s[m]=r[i];p[m]=i;lr[m]=1;sid[m]=m;m++;
	}
	sort(sid,sid+m,cmps);
	for(i=0;i<m;i++){
		//cout<<" s["<<sv<<"]="<<s[sv]<<endl;
		if(lr[sv]){
			r[p[sv]]=k;
			//cout<<" Set r["<<p[sv]<<"]="<<r[p[sv]]<<endl;
		}
		else{
			l[p[sv]]=k;
			//cout<<" Set l["<<p[sv]<<"]="<<l[p[sv]]<<endl;
		}
		if(i<m-1 && s[sv]!=s[sv2])k++;
	}
	sort(id,id+n+1,cmpy);
	for(i=0;i<n;i++){
		//cout<<" v["<<i<<"]="<<v<<endl;
		update(1,ll,rr,(int)l[v],(int)r[v],c[v]);
		//cout<<"  Update "<<l[v]<<"<->"<<r[v]<<"  "<<c[v]<<endl;
		while(i+1<n && y[v2]==y[v]){
			i++;
			//cout<<" v["<<i<<"]="<<v<<endl;
			update(1,ll,rr,(int)l[v],(int)r[v],c[v]);
			//cout<<"  Update "<<l[v]<<"<->"<<r[v]<<"  "<<c[v]<<endl;
		}
		//now=getMax(1,ll,rr,ll,rr);if(now>best)best=now;
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&n,&w,&h)!=EOF)work();
	return 0;
}
