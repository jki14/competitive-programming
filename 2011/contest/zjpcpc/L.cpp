#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long lld;

int main(){
	int t,k,N;scanf("%d",&t);
	lld n,p;
	//double d;
	while(t--){
		scanf("%d",&N);n=(lld)N;
		/*//debug
		d=log((double)n)/log(2);
		//cout<<"log2="<<d<<endl;
		k=(int)d;
		//cout<<"k="<<k<<endl;
		k++;
		printf("%d\n",k);*/
		for(p=1L,k=1;!(n>=p && n<p*2);p*=2,k++);
		printf("%d\n",k);
	}
	return 0;
}
