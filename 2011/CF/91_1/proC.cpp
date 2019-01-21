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

#define S 11000
#define K 9
#define M 15

typedef long long lld;


int num=0;;

lld s[S],val=0LL;
lld n,k;

lld tot[M];
int id[M],pla[M],ans;

void build(const int &k){
	if(k)
		s[num++]=val;
	else{
		tot[0]=tot[1]=1;
		for(int i=2;i<M;i++)tot[i]=tot[i-1]*((lld)i);
	}
	if(k>K)return;
	val*=10LL;val+=4LL;
	build(k+1);val/=10LL;
	val*=10LL;val+=7LL;
	build(k+1);val/=10LL;
}

int lucky(lld x){
	if(!x)return 0;
	for(;x;x/=10LL){
		lld r=x%10LL;
		if(r!=4LL && r!=7LL)return 0;
	}
	return 1;
}

void work(){
	/* init */
	if(n<M && k>tot[n]){
		printf("-1\n");
		return;
	}
	for(int i=0;i<M;i++)id[i]=i;
	/* Core */k--;
	for(int p=M-1;p>1;p--){
		int pos=M-p,d=0;
		//printf("tot=%lld\n",tot[p-1]);
		while(tot[p-1]<=k){
			k-=tot[p-1];
			d++;
		}
		//swap(id[pos],id[pos+d]);
		int tmp=id[pos+d];
		
		//printf("pos=%d d=%d\n",pos,d);
		
		for(int i=pos+d;i>pos;i--)id[i]=id[i-1];
		id[pos]=tmp;
	}
	//printf("id:");
	for(int i=0;i<M;i++){
		pla[id[i]]=i;
		//printf(" %d",id[i]);
	}
	//printf("\n");
	ans=0;
	for(int i=0;i<num;i++){
		if(s[i]>n)break;
		if(s[i]+((lld)M)-1LL<=n){
			ans++;
		}else{
			int j=((lld)(s[i]-n+((lld)M)-1LL));	
			lld pos=n-(((lld)M)-1LL)+((lld)pla[j]);

			/*printf("pla[%d]=%d\n",j,pla[j]);
			printf("pos[%lld]=%lld\n",s[i],pos);*/

			if(lucky(pos))ans++;
		}
	}
	/* putout Result */
	cout<<ans<<endl;
}

int main(){
	build(0);sort(s,s+num);
	while(cin>>n>>k)
		work();
	return 0;
}

