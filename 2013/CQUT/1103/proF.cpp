#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define B 2
#define N 2100

int n,f[B][N],g[N];

void core(int x){
	if(x<0){x=-x;
		if(x&1){
			f[0][1]++;f[1][x-1]++;
		}else{
			core(-(x>>1));core(x>>1);
		}
	}else{
		if(x&1){
			f[0][x-1]++;f[1][1]++;
		}else g[x]++;
	}
}

int main(){
	while(scanf("%d",&n)!=EOF && n){
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		if(n==1){ printf("x-1\n");continue; }
		core(-n);
		for(int i=1;i<n;i++){
			for(int b=0;b<B;b++){
				for(int t=0;t<f[b][i];t++){
					printf("(");
					for(int k=i;k>=0;k--){int d=i-k;
						if(d){
							if(!b && d&1)
								printf("-");
							else printf("+");
						}
						if(k>0){
							if(k>1){
								printf("x^%d",k);
							}else printf("x");
						}else printf("1");
					}
					printf(")");
				}
			}
			for(int t=0;t<g[i];t++){
				printf("(");
				if(i>1)
					printf("x^%d+1",i);
				else printf("x+1");
				printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}
