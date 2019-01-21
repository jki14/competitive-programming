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

//HEAD_OF_TEMPLATE_BY_JKI14

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

//TAIL_OF_TEMPLATE_BY_JKI14

int n,a,b;

int res(const int &x,const int &y){ return (x==y)?0:(x>y?1:-1); }

int dfs(const int &i,const int &a,const int &b,const int &x,const int &y){
	if(!i){
		return res(x,y);
	}
	if(!a){
		return res(x,y+min(b,i));
	}
	int ret=-1;
	for(int p=1;p<=a;p++){
		int tmp=dfs(i-1,a-p,b,x+1,y);
		if(b>p)_updmin(tmp,dfs(i-1,a,b-p-1,x,y+1));
		_updmax(ret,tmp);
	}

	//printf("%d %d %d %d %d == %d",i,a,b,x,y,ret);

	return ret;
}

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){printf("Case #%d: ",_T);
		scanf("%d%d%d",&n,&a,&b);
		printf("%d\n",dfs(n,a,b,0,0));
	}	
	return 0;
}

