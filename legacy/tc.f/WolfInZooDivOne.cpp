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
	#define _mkpr(x,y) make_pair(x,y) 

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 310
#define B 2

#define nxt (now^1)

const lld modulo=1000000007;

int n,m,now=0;
int r[B][N][N],c[N];
int u[N],v[N];
lld f[B][N][N],ans;

string us,vs;

void update(const int &i,const int &x,const int &y,const lld &d){
	if(r[nxt][x][y]!=i){ r[nxt][x][y]=i;f[nxt][x][y]=0LL; }
	f[nxt][x][y]=(f[nxt][x][y]+d)%modulo;
	
	//if(i<=5)printf("f[%d][%d][%d]=%lld\n",i,x,y,f[nxt][x][y]);
	
}

void str2ai(const string &s,int a[N]){m=0;
	for(int i=0;i<N;i++)a[i]=-1;
	int i=0;while(s[i]==' ')i++;
	for(a[m]=0;i<_size(s);i++){
		if(s[i]==' '){ while(i<_size(s) && s[i]==' ')i++;i--;
		//printf("a[%d]=%d\n",m,a[m]);
		a[++m]=0;continue; }
		a[m]*=10;a[m]+=s[i]-'0';
	}
}

class WolfInZooDivOne {
	public:
	int count(int _n, vector <string> L, vector <string> R) {
		n=_n;memset(c,0x3f,sizeof(c));
		us.clear();vs.clear();
		for(int i=0;i<_size(L);i++)us=us+L[i];us=us+" ";
		for(int i=0;i<_size(R);i++)vs=vs+R[i];vs=vs+" ";
		str2ai(us,u);str2ai(vs,v);
		for(int i=0;i<m;i++){
			//printf("u[%d]=%d v[%d]=%d\n",i,u[i],i,v[i]);
			for(int x=u[i]+1;x<=v[i]+1;x++){
				_updmin(c[x],u[i]+1);
			}
		}
		memset(r,0xff,sizeof(r));r[nxt][0][0]=0;
		f[nxt][0][0]=1LL;ans=0LL;
		for(int i=1;i<=n;i++){now=nxt;
			for(int x=0;x<=i;x++){
				for(int y=0;y<=x;y++){
					if(r[now][x][y]!=i-1)continue;
					
					//if(i<=5)printf("f[%d][%d][%d]=%lld c[%d]=%d\n",i,x,y,f[now][x][y],i,c[i]);
					
					
					update(i,x,y,f[now][x][y]);
					if(c[i]<=y)continue;
					update(i,i,x,f[now][x][y]);
				}
			}
		}
		for(int x=0;x<=n;x++)for(int y=0;y<=x;y++)if(r[nxt][x][y]==n)ans=(ans+f[nxt][x][y])%modulo;
		return (int)ans;
	}
};


// Powered by FileEdit


//Powered by [KawigiEdit] 2.0!
