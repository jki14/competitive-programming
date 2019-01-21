#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 31000
#define maxm 110000

#define k id[i]

typedef long long lld;

int n,m;
int num[maxn];
int a[maxm],b[maxm],id[maxm];
lld bit[maxn],res[maxm];

map<int,int> s;
map<int,int>::iterator it;

int cmpb(const int &x,const int &y){ return b[x]<b[y]; }

/*void insSt(int i,int s,int t,int p,int x){
	if(p<s || p>t)return;
	//cout<<"    ins "<<s<<"->"<<t<<" at "<<p<<" = "<<x<<endl;
	st[i]+=x;if(s!=t){
		int mid=(s+t)>>1;
		insSt(i*2,s,mid,p,x);
		insSt(i*2+1,mid+1,t,p,x);
	}
}

int getSt(int i,int s,int t,int l,int r){
	if(r<s || l>t)return 0;
	if(l<=s && t<=r)return st[i];
	int mid=(s+t)>>1;
	return getSt(i*2,s,mid,l,r)+getSt(i*2+1,mid+1,t,l,r);
}

void setSt(int l,int r){
	//cout<<" Set "<<l<<"->"<<r<<endl;
	for(int i=l;i<=r;i++){
		it=s.find(num[i]);
		if(it==s.end()){
			insSt(1,1,n,i,num[i]);s.insert(pair<int,int>(num[i],i));
		}else{
			insSt(1,1,n,(*it).second,-num[i]);
			insSt(1,1,n,i,num[i]);(*it).second=i;
		}
	}
}*/
int lowbit(const int &x){ return x&(x^(x-1)); }

void updateBit(int x,int d){
	for(;x<=n;x+=lowbit(x))bit[x]+=(lld)d;
}

void setBit(int l,int r){
	for(int i=l;i<=r;i++){
		it=s.find(num[i]);
		if(it==s.end()){
			updateBit(i,num[i]);s.insert(pair<int,int>(num[i],i));
		}else{
			updateBit((*it).second,-num[i]);
			updateBit(i,num[i]);(*it).second=i;
		}
	}
}

lld sumBit(int x){
	lld sum;for(sum=0;x>0;x-=lowbit(x))sum+=bit[x];
	return sum;
}

void work(){
	int i,pre=0;s.clear();
	memset(bit,0,sizeof(bit));
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i],&b[i]);
		id[i]=i;
	}
	sort(id,id+m,cmpb);
	for(i=0;i<m;i++){
		if(pre<b[k]){ setBit(pre+1,b[k]);pre=b[k]; }
		res[k]=sumBit(b[k])-sumBit(a[k]-1);
	}
	for(i=0;i<m;i++)printf("%I64d\n",res[i]);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
