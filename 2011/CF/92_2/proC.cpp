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

#define C 26
#define L 1100

char s[L],f[L];
int n,num[C];

void work(){
	n=strlen(s);memset(f,0,sizeof(f));
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)num[s[i]-'a']++;
	//for(int i=0;i<C;i++)printf("num[%d]=%d\n",i,num[i]);
	for(int i=2;i<=n;i++){
		if(f[i-1])continue;
		int p=-1;for(int j=i;j<=n;j+=i)if(f[j-1])p=f[j-1]-'a';
		if(p<0){ p=0;for(int j=1;j<C;j++)if(num[j]>num[p])p=j; }
		for(int j=i;j<=n;j+=i){
			//printf("p=%d\n",p);
			if(f[j-1])continue;
			num[p]--;if(num[p]<0){
				printf("NO\n");
				return;
			}
			f[j-1]='a'+p;
		}
	}
	for(int i=0;i<C;i++)if(num[i]){f[0]='a'+i;break;}
	//for(int i=0;i<n;i++)printf("f[%d]=%c\n",i,f[i]);
	printf("YES\n%s\n",f);
}

int main(){
	while(scanf("%s",s)!=EOF)
		work();
	return 0;
}

