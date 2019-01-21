#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100000

int n,m;
int a[maxn],s[maxn];

void work(){
	int i,h,t;
	if(m>n)m=n;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	h=0;t=0;
	for(i=0;i<n;i++){
		while(h<t && a[s[t-1]]>a[i])t--;
		s[t++]=i;
		while(h<t && s[h]+m<=i)h++;
		if(i>m-2){
			printf("%d",a[s[h]]);
			if(i!=n-1)printf(" ");
		}
	}
	printf("\n");
	h=0;t=0;
	for(i=0;i<n;i++){
		while(h<t && a[s[t-1]]<a[i])t--;
		s[t++]=i;
		while(h<t && s[h]+m<=i)h++;
		if(i>m-2){
			printf("%d",a[s[h]]);
			if(i!=n-1)printf(" ");
		}
	}
	printf("\n");
}

int main(){
	scanf("%d%d",&n,&m);work();
	return 0;
}
