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

int n,s,p;
int low,hig,scr,ans;

void core(){
	scanf("%d%d%d",&n,&s,&p);ans=0;
	if(p>=2){
		low=p*3-4;hig=p*3-2;
	}else low=hig=(p==0)?0:1;
	for(int i=0;i<n;i++){
		scanf("%d",&scr);
		if(scr>=hig){ ans++;continue; }
		if(s && scr>=low){ ans++;s--; }
	}
	printf("%d",ans);
}

int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		core();
		printf("\n");
	}
	return 0;
}
