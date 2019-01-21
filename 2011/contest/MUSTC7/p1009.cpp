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
#include<set>
#include<map>
using namespace std;

#define maxn 1100

int a[maxn],n,res;

int gcd(int x,int y){
	while(y){
		int k=x%y;
		x=y;y=k;
	}
	return x;
}

void work(){
	int i,j,x,y,d;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	
	res=1;
	for(i=n;i>=n-2;i--)res*=i;
	res/=6;

	for(d=i=0;i<n;i++){x=y=0;
		for(j=0;j<n;j++){
			if(i==j)continue;
			if(gcd(a[i],a[j])==1)
				x++;
			else
				y++;
		}
		d+=x*y;
	}
	res-=d/2;
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d",&n);
		work();
	}
	return 0;
}

