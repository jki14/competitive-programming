#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

int T;
int res,n;

void work(){T++;
	scanf("%d",&n);
	int i,k;res=0;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(i!=k)res++;
	}
	printf("Case #%d: %d.000000\n",T,res);
}

int main(){
	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int t;scanf("%d",&t);T=0;
	while(t--)work();
	fclose(stdin);fclose(stdout);
	return 0;
}

