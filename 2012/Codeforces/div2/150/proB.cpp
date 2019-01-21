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

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpa(x,y) make_pair(x,y)

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)
	
	template<class T> inline T _lowbit(const int &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+bitsize(x&(x-1))); }

	//CONST VALUE
	
	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE
	
	template<class T> inline T _sqr(const T &x){ return x*x; }



//TAIL_OF_TEMPLATE_BY_JKI14

typedef long long lld;

#define L 110

int _n,len;
lld n,val;

char str[L];
set<lld> hash;

int main(){
	while(scanf("%d",&_n)!=EOF){n=_n;hash.clear();
		len=((int)(log(n*1.0)/log(10.0)+_eps))+1;
		//printf("len=%d\n",len);
		for(int x=0;x<10;x++){
			for(int y=x+1;y<10;y++){	
				for(int l=1;l<=len;l++){str[l]=0;
					for(int s=0;s<_ni(l);s++){
						for(int i=0;i<l;i++){
							str[i]='0'+(_has(s,i)?x:y);
						}							
						sscanf(str,"%I64d",&val);
						//printf("!%s\n",str);
						if(val>n || val==0)continue;
						hash.insert(val);
					}
				}
			}
		}

		/*for(set<lld>::iterator it=hash.begin();it!=hash.end();it++){
			cout<<"!"<<(*it)<<endl;
		}*/

		printf("%d\n",hash.size());
	}
	return 0;
}

