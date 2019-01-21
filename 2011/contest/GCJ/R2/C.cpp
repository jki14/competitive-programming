#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define maxn 1100

typedef long long lld;

int T;
int n;
int s[maxn];
int p[maxn],tot;
int maxval,minval;

/*lld gcd(lld a,lld b){
	if(a<b)swap(a,b);

	if(b==0LL)return a;
	if(a%2LL==0LL && b%2LL==0LL)
		return 2LL*gcd(a/2LL,b/2LL);
	if(a%2LL==0)
		return gcd(a/2LL,b);
	if(b%2LL==0)
		return gcd(a,b/2LL);

	return gcd((a+b)/2LL,(a-b)/2LL);
}*/

void work(){
	scanf("%d",&n);
	int i,j,k,t,pri,path;
	maxval=minval=tot=0;
	p[tot++]=2;
	for(i=3;i<=n;i++){pri=1;
		for(j=0;j<tot && p[j]*p[j]<=i;j++){
			if(i%p[j]==0){
				pri=0;
				break;
			}
		}
		if(pri)p[tot++]=i;
	}
	memset(s,0,sizeof(s));
	maxval=1;
	for(i=2;i<=n;i++){k=i;path=0;
		for(j=0;j<tot && p[j]<=k;j++){t=0;
			while(k%p[j]==0){
				k/=p[j];
				t++;
			}
			//printf("For %d   s[%d]=%d t=%d\n",i,p[j],s[p[j]],t);
			if(s[p[j]]<t){	
				path=1;
				s[p[j]]=t;
			}
		}
		if(path)maxval++;
	}
	if(n==1)
		minval=1;
	else{
		memset(s,0,sizeof(s));
		for(i=n;i>1;i--){k=i;path=0;
			for(j=0;j<tot && p[j]<=k;j++){t=0;
				while(k%p[j]==0){
					k/=p[j];
					t++;
				}
				if(s[p[j]]<t){
					path=1;
					s[p[j]]=t;
				}
			}
			if(path)minval++;
		}
	}
	//cout<<"n="<<n<<" maxval="<<maxval<<" minval="<<minval<<endl;
	printf("Case #%d: %d\n",T,maxval-minval);
}

int main(){
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

