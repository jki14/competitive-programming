#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 10000

int a[maxn];
int n,k;

int select(int *a,int b,int e,int k){
	if(b==e)return a[b];
	int x=a[((b+e)>>1)],i=b,j=e;
	i--;j++;
	while(i<j){
		while(a[++i]<x);while(a[--j]>x);
		if(i<j) std::swap(a[i],a[j]);
	}
	if(j==e)j--;i=j-b+1;
	if(k<=i)return select(a,b,j,k);
		else return select(a,j+1,e,k-i);
}

void work(){
	scanf("%d",&n);k=(n>>1)+1;
	//cout<<":"<<n<<endl;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		//cout<<":"<<a[i]<<endl;
	}
	printf("%d\n",select(a,0,n-1,k));
}

int main(){
	work();
	return 0;
}
