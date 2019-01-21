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

#define N 110

typedef long long lld;

int n,m,p;
int sm[N],sa[N];
lld sum,res;

void extgcd(int a, int b, int & x, int & y){
	if (b == 0) { x=1; y=0; return; }
	extgcd(b, a % b, x, y);
	int t = x; x = y; y = t - a / b * y;
	return ;
}

void work(){
	int k=m,i;
	sum=res=1LL;p=0;
	
	for(i=2;i*i<=k;i++)
  		if(k%i==0){
       			sm[p++]=i;
			do{
				k/=i;
			}while(k%i==0);
      		}
      	if(k>1) sm[p++]=k;
        memset(sa,0,sizeof(sa));
     	for(int i=2;i<=n;i++){
        	int t=4*i-2;
        	for(int j=0;j<p;j++){
          		while(t%sm[j]==0){
             			sa[j]++;
             			t/=sm[j];
           		}
        	}
        	
	res=res*t%m;
        t=i+1;
        for(int j=0;j<p;j++){
         	while(t%sm[j]==0){
             		sa[j]--;
             		t/=sm[j];
           	}
        }
        if(t>1){
         	int x,y;
           	extgcd(t,m,x,y);
           	x=(x%m+m)%m;
           	res=(res*x)%m;
        }
        lld fin=res;
        for(int j=0;j<p;j++)
        	for(int k=0;k<sa[j];k++)
        		fin=(fin*sm[j])%m;
        sum=(sum+fin)%m;
      }
      printf("%lld\n",sum);
}

int main(int argc, char *argv[]){m=1000000000;
	while( scanf("%d",&n) && n )work();
    	return 0;
}
