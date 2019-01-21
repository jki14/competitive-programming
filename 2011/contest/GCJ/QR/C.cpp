#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

int T,n;
int res,d,k,mind;

void work(){
	T++;mind=LONG_MAX;
	scanf("%d",&n);res=d=0;
	while(n--){
		scanf("%d",&k);
		d^=k;res+=k;mind=min(mind,k);
	}
	if(d){
		printf("Case #%d: NO\n",T);
	}else{
		printf("Case #%d: %d\n",T,res-mind);
	}
}

int main(){
	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
	int t;scanf("%d",&t);T=0;
	while(t--)work();
	fclose(stdin);fclose(stdout);
	return 0;
}

