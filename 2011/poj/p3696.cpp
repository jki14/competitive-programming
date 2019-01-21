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

#define K 1100

typedef unsigned long long lld;

const lld inf =1LL<<60;

int T;

int k,num[K];
lld sta[K],ans;
lld n,m,top,now;

lld stein(lld x,lld y){
	lld k=0LL;
	while(y>0LL){
		if((x&y&1)==1)x=(x-y)>>1;
		else if(((x^y)&1)==0){ x>>=1;y>>=1;k++; }
		else if((x&1)==0)x>>=1; else y>>=1;
		if(x<y)swap(x,y);
	}
	return x<<k;
}

lld phi(lld x){
	double res=(double)x;
	lld tail = (lld)sqrt((double)x)+1LL;
	for(lld i=2LL; i<tail; i++){
		if(!(x%i)){
			res=res*(1.0-1.0/((double)i));
			while(!(x%i))x/=i;
		}
	}
	if(x>1LL)res=res*(1.0-1.0/((double)x));
	return (lld)res;
}

lld mm(lld a,lld b,lld c){
	lld res=0LL,now=a % c;
	for(;b;b>>=1){
		if(b&1){
			res = (res + now) % c;
		}
		now = (now + now) % c;
	}
	return res % c;
}

lld tpm(){
	lld k=now,tmp=10LL % m,res=1LL;
	for(;k;k>>=1){
		if(k&1){
			//res= res * tmp % m;
			res=mm(res,tmp,m);
		}
		//tmp = tmp * tmp % m;
		tmp=mm(tmp,tmp,m);
	}
	return res % m;
}

void dfs(const int &x){
	if(x==k){

		//printf("	now=%lld\n",now);

		if(tpm()==1LL && now<ans)ans=now;
		return;
	}

	lld mov=1LL;
	for(int i=0;i<=num[x];i++){
		dfs(x+1);
		now*=sta[x];
		mov*=sta[x];
	}
	now/=mov;
}

void work(){T++;

	m=n*9LL / stein(n*9LL,8LL);
	if(stein(m,10LL)>1LL){
		printf("Case %d: 0\n",T);
		return;
	}

	top=phi(m);k=0;
	//printf("m=%lld top=%lld\n",m,top);
	lld tail = (lld)sqrt((double)top)+1LL;
	for(lld i=2LL; i<tail; i++){
		if(!(top%i)){
			sta[k]=i;num[k]=0;
			while(!(top%i)){
				top/=i;num[k]++;
			}
			k++;
		}
	}
	if(top>1LL){
		sta[k]=top;num[k]=1;
		k++;
	}
	
	ans=inf;
	now=1LL;dfs(0);
	//if(ans==inf)ans=0LL;
	printf("Case %d: %lld\n",T,ans);
}

int main(){T=0;
	while(scanf("%lld",&n)!=EOF && n!=0LL)
		work();
	return 0;
}

