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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;


//TYPEDEF
typedef long long lld;
typedef double dou;
typedef pair<int,int> pii;

//COMPARE

inline int min(const int &x, const int &y){ return x<y?x:y; }
inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

inline int max(const int &x, const int &y){ return x>y?x:y; }
inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

template<class T> inline void _updmin(T &x,const T &y){ if(x>y)x=y; }
template<class T> inline void _updmax(T &x,const T &y){ if(x<y)x=y; }

#define L 29

int n;
lld num,ans;
char a[L], b[L], s[L];

const lld def=-1LL;

int core(const int &k){
	if(a[k]=='0')return 0;

	//printf("k=%d\n",k);

	int len=0;
	for(int i=0;i<k;i++){
		if(!len || s[len-1]!=a[i])s[len++]=a[i];
	}
	
	for(int _top=len;_top>=0;_top--){int top=_top;
		int flag=1;
		for(int i=top;i<len;i++){
			if(s[i]!=s[len+top-i-1]){
				flag=0;break;
			}
		}
		if(!flag)continue;
	
		/*
		printf("prx= ");
		for(int i=0;i<top;i++)printf("%c",s[i]);
		printf("\n");
		*/

		if(n-k<top)continue;
		if((n-k==top && s[top-1]>=a[k]) || ((top==0 || s[top-1]>=a[k]) && a[k-1]>=a[k]))continue;

		memcpy(b,a,sizeof(char)*L);int p=k;
		if(a[k-1]>=a[k]){
			b[p]=s[--top];
		}else if(top==0 || s[top-1]>=a[k]){
			b[p]=a[k-1];
		}else if(top && (n-p==top || s[top-1]>=a[k-1])){
			b[p]=s[--top];
		}else b[p]=a[k-1];

		for(p++;p<n;p++){
			if(top && (n-p==top || s[top-1]>=b[p-1])){
				b[p]=s[--top];
			}else b[p]=b[p-1];	
		}

		lld res;sscanf(b,"%lld",&res);
		_updmax(ans,res);
	}

	//printf("ans1=%lld\n",ans);

	a[k]--;

	if(!len || s[len-1]!=a[k])s[len++]=a[k];
	for(int _top=len;_top>=0;_top--){int top=_top;
		int flag=1;
		for(int i=top;i<len;i++){
			if(s[i]!=s[len+top-i-1]){
				flag=0;break;
			}
		}
		if(!flag)continue;
	
		/*		
		printf("prx= ");
		for(int i=0;i<top;i++)printf("%c",s[i]);
		printf("\n");
		*/

		if(n-k-1<top)continue;
		
		memcpy(b,a,sizeof(char)*L);int p=k+1;
		if(top==len && n-p>top)b[p++]='9';

		for(;p<n;p++){
			if(top && (n-p==top || s[top-1]>=b[p-1])){
				b[p]=s[--top];
			}else b[p]=b[p-1];	
		}
		
		lld res;sscanf(b,"%lld",&res);
		_updmax(ans,res);
	}

	//printf("ans2=%lld\n",ans);

	a[k]++;
	return ans>def;
}
void front(){
	memcpy(b,a,sizeof(char)*L);
	if(b[0]=='1'){
		for(int i=0;i<n-1;i++)b[i]='9';
		b[n-1]=0;
	}else{
		b[0]=b[0]-1;
		for(int i=1;i<n-1;i++)b[i]='9';
		b[n-1]=b[0];
	}
	sscanf(b,"%lld",&ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld",&num);sprintf(a,"%lld",num);n=strlen(a);
	
		if(n==1){printf("%lld\n",num-1LL);continue;}

		ans=def;
		for(int i=n-1;i;i--)if(core(i))break;

		if(ans==def)front();
		printf("%lld\n",ans);
	}
	return 0;
}

