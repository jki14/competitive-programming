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
#include<queue>
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

int n,a,b;

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){printf("Case #%d: ",_T);
		scanf("%d%d%d",&n,&a,&b);
		if(!n){ printf("0\n");continue; }
		int m=(n>>1)+1;
		/*if(afir>0){
			if(afir==bfir){
				if(n&1)
					printf("1\n");	
				else printf("0\n");
			}else if(afir>bfir)
				printf("1\n");
			else printf("-1\n");*/
		/*if(a>=m){
			int _a=a/m,_b=b/m;
			if(_a==_b){
				if(n&1)
					printf("1\n");
				else printf("0\n");
			}else if(_a>_b)
				printf("1\n");
			else printf("-1\n");
		}else{
			int re=n-a,ch=max((b-re)>>1,0);
			int _a=a-ch,_b=(b>re)?re+ch:b;
			if(_a==_b)
				printf("0\n");
			else if(_a>_b)
				printf("1\n");
			else printf("-1\n");
		}*/
		if(a>=m){
			int _a=a-m+1;
			if(b<(_a+1)*(n-m+1)){
				printf("1\n");
			}else{
				if(n&1){
					printf("-1\n");
				}else{
					int __a=a-m+2;
					if(b>=(__a+1)*(n-m+2))
						printf("-1\n");
					else printf("0\n");
				}
			}
		}else{
			if(a==b)
				printf("0\n");
			else if(a>b)
				printf("1\n");
			else printf("-1\n");
		}
	}	
	return 0;
}

