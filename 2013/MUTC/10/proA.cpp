#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define N 110000

int n,m,t[N],c[N],k;

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){k=0;
		for(int i=0;i<n;i++)
			scanf("%d",&t[i]);
		for(int i=0;i<n;i++){
			scanf("%d",&c[i]);
			if(c[i]&1)k=1;
		}
		for(int i=0;i<m;i++){
			int q;scanf("%d",&q);
			if(q<=0){ printf("NO\n");continue; }
			if(q&1){
				if(k)
					printf("YES\n");
				else printf("NO\n");
			}else printf("YES\n");
		}
	}
	return 0;
}
