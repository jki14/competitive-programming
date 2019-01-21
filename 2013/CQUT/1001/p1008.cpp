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

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)

	template<class T> inline T _lowbit(const T &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+_bitsize(x&(x-1))); }

	//CONST VALUE
	
	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE
	
	template<class T> inline T _sqr(const T &x){ return x*x; }
	
	//NUMBERIC
	
	template<class T> inline T _gcd(const T &x,const T &y){
		if(x<0)return _gcd(-x,y);
		if(y<0)return _gcd(x,-y);
		return (y==0)?x:_gcd(y,x%y);
	}
	template<class T> inline T _lcm(const T &x,const T &y){
		if(x<0)return _lcm(-x,y);
		if(y<0)return _lcm(x,-y);
		return x*(y/_gcd(x,y));
	}
	template<class T> inline T _euc(const T &a,const T &b,T &x,T &y){ 
		/* a*x+b*y == _euc(); */
		if(a<0){T d=_euc(-a,b,x,y);x=-x;return d;} 
	   	if(b<0){T d=_euc(a,-b,x,y);y=-y;return d;} 
	      	if(b==0){
			x=1;y=0;return a;
		}else{
			T d=_euc(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T,int> > _fac(T n){
		vector<pair<T,int> > ret;for (T i=2;n>1;){
			if (n%i==0){int cnt=0;for (;n%i==0;cnt++,n/=i);ret.push_back(_mkpr(i,cnt));} 
	   		i++;if (i>n/i) i=n;
		}
		if (n>1) ret.push_back(_mkpr(n,1));return ret;
	}
	template<class T> inline int _prm(const T &x){
		if(x<=1)return 0;
		for(T i=2;sqr(i)<=x;i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T _phi(T x){ 
		/* EularFunction:return the number of integers which are the relatively prime number of x and less than x. */
		vector<pair<T,int> > f=_fac(x);T ret=x;
		for(int i=0;i<_size(f);i++)ret=ret/f[i].first*(f[i].first-1);
		return ret;
	}
	template<class T> inline T _inv(T a,T b){
		/* if(k%a==0) (k/a)%b==((k%b)*(_inv()%b))%b */
		/*	original code begin
		T x0=1,y0=0,x1=0,y1=1;
		for(T r=a%b;r!=0;r=a%b){ T k=a/b,dx=x0-k*x1,dy=y0-k*y1;x0=x1;y0=y1;x1=dx;y1=dy;a=b;b=r; }
		if(x1==0)x1=1;return x1;
		original code end	*/
		T x,y;_euc(a,b,x,y);
		if(x==0)x=1;return x;
	}
	template<class T> inline T _cmod(T x,T m){ return (x%m+m)%m; }
	template<class T> inline T _amod(T x,T y,T m){ return x=((x+y)%m+m)%m; }
	template<class T> inline T _mmod(T x,T y,T m){ return (T)((((lld)x)*((lld)y)%((lld)m)+((lld)m))%((lld)m)); }
	template<class T> inline T _pmod(T x,T y,T m){
		if(y==0)return 1%m;else if((y&1)==0){ 
			T z=_pmod(x,y>>1,m);return _mmod(z,z,m); 
		}else return _mmod(_pmod(x,y^1,m),x,m);
	}
	#define _cmd(x) _cmod(x,mod)
	#define _amd(x,y) _amod(x,y,mod)
	#define _mmd(x,y) _mmod(x,y,mod)
	#define _pmd(x,y) _pmod(x,y,mod)

	//MATRIX OPERATIONS
	
	const int _MTRXSIZE = 40;
	template<class T> inline void _shwMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++){ for(int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl; }
	}
	template<class T> inline void _stdMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) A[i][j]=(i==j)?1:0;
	}
	template<class T> inline void _addMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];
	}
	template<class T> inline void _subMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];
	}
	template<class T> inline void _mulMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]+=A[i][k]*B[k][j];
	}
	template<class T> inline void _addModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]+B[i][j],m);
	}
	template<class T> inline void _subModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]-B[i][j],m);
	}
	template<class T> inline void _mulModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]=(C[i][j]+_mmod(A[i][k],B[k][j],m))%m;
	}
	template<class T> inline void _powModMTRX(int n,T y,T m,T C[_MTRXSIZE][_MTRXSIZE],T X[_MTRXSIZE][_MTRXSIZE]){
		T R[_MTRXSIZE][_MTRXSIZE];for(int i=0;i<n;i++)for(int j=0;j<n;j++)R[i][j]=X[i][j];_stdMTRX(n,C);
		if(y>0)for(T i=1;;i<<=1){
			if(y&i)_mulModMTRX(n,m,C,C,R);
			_mulModMTRX(n,m,R,R,R);
			if(i>(y>>1))break;
		}
	}

	//FRACTION
	template<class T> struct _frct{T a,b;_frct(T a=0,T b=1);string toString();};  
	template<class T> _frct<T>::_frct(T a,T b){T d=_gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
	template<class T> string _frct<T>::toString(){ostringstream tout;tout<<a<<"/"<<b;return tout.str();}
	template<class T> _frct<T> operator+(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b+q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator-(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b-q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator*(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.a,p.b*q.b);}  
	template<class T> _frct<T> operator/(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b,p.b*q.a);}  

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 24

const int kNReq[N][2][3]={ 
	 {{ 4,15,16},{24,24,24}}//0
	,{{ 5,16,17},{24,24,24}}//1
	,{{ 3, 6,17},{24,24,24}}//2
	,{{ 2, 6,17},{24,24,24}}//3
	,{{ 0,15,16},{ 8,18,19}}//4
	,{{ 1,16,17},{ 9,19,20}}//5
	,{{ 2, 3,17},{ 7,10,20}}//6
	,{{ 6,10,20},{24,24,24}}//7
	,{{ 4,18,19},{12,21,22}}//8
	,{{ 5,19,20},{13,22,23}}//9
	,{{ 6, 7,20},{11,14,23}}//10
	,{{10,14,23},{24,24,24}}//11
	,{{ 8,21,22},{24,24,24}}//12
	,{{ 9,22,23},{24,24,24}}//13
	,{{10,11,23},{24,24,24}}//14
	,{{ 0, 4,16},{24,24,24}}//15
	,{{ 0, 4,15},{ 1, 5,17}}//16
	,{{ 1, 5,16},{ 2, 3, 6}}//17
	,{{ 4, 8,19},{24,24,24}}//18
	,{{ 4, 8,18},{ 5, 9,20}}//19
	,{{ 5, 9,19},{ 6, 7,10}}//20
	,{{ 8,12,22},{24,24,24}}//21
	,{{ 8,12,21},{ 9,13,23}}//22
	,{{ 9,13,22},{10,11,14}}//23
};

const int kEdge[16][16]={
	// 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
	 {24, 0,24,24,15,24,24,24,24,24,24,24,24,24,24,24}//1
	,{ 0,24, 1,24,24,16,24,24,24,24,24,24,24,24,24,24}//2
	,{24, 1,24, 2,24,24,17,24,24,24,24,24,24,24,24,24}//3
	,{24,24, 2,24,24,24,24, 3,24,24,24,24,24,24,24,24}//4
	,{15,24,24,24,24, 4,24,24,18,24,24,24,24,24,24,24}//5
	,{24,16,24,24, 4,24, 5,24,24,19,24,24,24,24,24,24}//6
	,{24,24,17,24,24, 5,24, 6,24,24,20,24,24,24,24,24}//7
	,{24,24,24, 3,24,24, 6,24,24,24,24, 7,24,24,24,24}//8
	,{24,24,24,24,18,24,24,24,24, 8,24,24,21,24,24,24}//9
	,{24,24,24,24,24,19,24,24, 8,24, 9,24,24,22,24,24}//10
	,{24,24,24,24,24,24,20,24,24, 9,24,10,24,24,23,24}//11
	,{24,24,24,24,24,24,24, 7,24,24,10,24,24,24,24,11}//12
	,{24,24,24,24,24,24,24,24,21,24,24,24,24,12,24,24}//13
	,{24,24,24,24,24,24,24,24,24,22,24,24,12,24,13,24}//14
	,{24,24,24,24,24,24,24,24,24,24,23,24,24,13,24,14}//15
	,{24,24,24,24,24,24,24,24,24,24,24,11,24,24,14,24}//16
};
	
#define GETSCORE(x)((x&1)?-1:1)
#define TOMSTURN(x)(!(x&1))

int n,fin,base_state,base_score;
int bit[110],req[N][2];

/*map<int, int> f;
map<int, int>::iterator it;

queue<int> q;*/

void Init(){
	for(int i=0;i<=N;i++)bit[i]=1<<i;
	fin=bit[N]-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			req[i][j]=0;
			for(int k=0;k<3;k++)req[i][j]|=bit[kNReq[i][j][k]];
		}
	}
	/*int k=0;for(int i=0;i<16;i++)for(int j=0;j<16;j++)if(kEdge[i][j]!=24)k++;
	printf("k=%d\n",k);*/
	/*for(int i=0;i<16;i++)for(int j=0;j<16;j++)
		if(kEdge[i][j] != kEdge[j][i])printf("fvck(%d,%d)\n",i,j);*/
}

bool Core(const int &state,const int &score,const int &k){
	if(k==N)return score>0;
	for(int i=0;i<N;i++){
		if(state&bit[i])continue;
		int nxt_state=state|bit[i];
		int nxt_score=score;
		//printf("k=%d nxt_state=%d nxt_score=%d\n",k,nxt_state,nxt_score);
		for(int j=0;j<2;j++)
			if((state&req[i][j])==req[i][j])nxt_score+=GETSCORE(k);
		if(!Core(nxt_state,nxt_score,k+1))return true;
	}
	return false;
}

int main(){
	Init();
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d: ",_T);
		scanf("%d",&n);base_state=base_score=0;
		for(int i=0;i<n;i++){
			int x,y;scanf("%d%d",&x,&y);
			int eid=kEdge[x-1][y-1];
			for(int j=0;j<2;j++)
				if((base_state&req[eid][j])==req[eid][j])base_score+=GETSCORE(i);
			base_state|=bit[eid];
		}
		//printf("base_state=%d base_score=%d\n",base_state,base_score);
		//f.clear();f.insert(_mkpr(base_state,base_score));
		/*while(!q.empty())q.pop();q.push(base_state);
		for(;!q.empty();q.pop()){
			int state=q.front();
			int score=f[state];
			int k=0;for(int i=0;i<N;i++)if(state&bit[i])k++;
			for(int i=0;i<N;i++){
				if(state&bit[i])continue;
				int nxt_state=state|bit[i];
				int nxt_score=score;
				//printf("k=%d nxt_state=%d nxt_score=%d\n",k,nxt_state,nxt_score);
				for(int j=0;j<2;j++)
					if((state&req[i][j])==req[i][j])nxt_score+=GETSCORE(k);
				it=f.find(nxt_state);
				if(it!=f.end()){
					if(k&1){
						_updmin((*it).second,nxt_score);
					}else{
						_updmax((*it).second,nxt_score);
					}
				}else{
				       	f.insert(_mkpr(nxt_state,nxt_score));
					q.push(nxt_state);
				}
			}
		}
		int ret=f[fin];//printf("ret=%d\n",ret);*/
		bool ret=TOMSTURN(n)?Core(base_state,base_score,n):!Core(base_state,base_score,n);
		if(ret)
			printf("Tom200\n");
		else printf("Jerry404\n");
	}
	return 0;
}

