#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

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

template<class T> inline T _inv(T a,T b){
			/* if(k%a==0) (k/a)%b==((k%b)*(_inv()%b))%b */
			/*	original code begin
			 *			T x0=1,y0=0,x1=0,y1=1;
			 *					for(T r=a%b;r!=0;r=a%b){ T k=a/b,dx=x0-k*x1,dy=y0-k*y1;x0=x1;y0=y1;x1=dx;y1=dy;a=b;b=r; }
			 *							if(x1==0)x1=1;return x1;
			 *									original code end	*/
			T x,y;_euc(a,b,x,y);
					if(x==0)x=1;return x;
						}

const int N=100000;

typedef long long lld;
const lld modulo=1000000007LL;

lld f[N];
int n;

int main(){
	f[0]=f[1]=f[2]=0LL;f[3]=1LL;
	for(int i=4;i<=N;i++){lld li=i;
		f[i]=((li*li%modulo-2LL*li%modulo)%modulo*f[i-1]%modulo+li*f[i-2]%modulo-4LL*((i&1)?-1LL:1LL))%modulo;
		/*printf("ans[%d]=",i);
		printf("%lld/%d=",f[i],i-2);*/
		//f[i]/=(li-2LL);
		f[i]=f[i]*_inv(li-2LL,modulo)%modulo;
		f[i]=(f[i]%modulo+modulo)%modulo;
		//printf("%lld\n",f[i]);
	}
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",f[n]);
	}
	return 0;
}
