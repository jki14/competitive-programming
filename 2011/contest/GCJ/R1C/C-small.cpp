#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 110

int T;
int n,s,t;
int a[maxn];

int correct(const int &x){
	for(int i=0;i<n;i++)
		if(x%a[i]!=0 && a[i]%x!=0)return 0;
	return 1;
}

void work(){
	int i;
	scanf("%d%d%d",&n,&s,&t);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("Case #%d: ",T);
	for(i=s;i<=t;i++)
		if(correct(i)){
			printf("%d\n",i);
			return;
		}
	printf("NO\n");
}

int main(){
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

