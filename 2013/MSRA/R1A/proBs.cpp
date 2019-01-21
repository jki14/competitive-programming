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

#define L 1100000

const int inf=0x3f3f3f3f;

char a[L],b[L];
int ans,n,m;

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){printf("Case #%d: ",_T);
		scanf("%s",a);scanf("%s",b);
		n=strlen(a);m=strlen(b);ans=inf;
		for(int s=0;s+m<=n;s++){
			int tmp=0;for(int i=s;i<s+m;i++)if(a[i]!=b[i-s])tmp++;
			_updmin(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}

