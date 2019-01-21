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
#include<deque>
#include<set>
#include<map>
using namespace std;

#define L 1100
#define C 26

int n,num[C];
char s[L],a[L];

void work(){
	n=strlen(s);
	memset(num,0,sizeof(num));
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)num[s[i]-'a']++;
	for(int i=2;i<=n;i++){
		if(a[i-1])continue;int p=-1;
		for(int j=i;j<=n;j+=i){
			if(a[j-1]){
				if(p==-1)p=a[j-1]-'a';
				if(p!=((int)(a[j-1]-'a'))){
					printf("NO\n");
					return;
				}
			}
		}
		//find max
		if(p<0)for(int j=0;j<C;j++)if(p==-1 || num[p]<num[j])p=j;
		for(int j=i;j<=n;j+=i){
			if(a[j-1])continue;
			a[j-1]='a'+p;num[p]--;
			//printf("a[%d]=%c\n",j-1,'a'+p);
			if(num[p]<0){
				printf("NO\n");
				return;
			}
		}
	}a[n]=0;
	for(int i=0;i<C;i++)if(num[i]){a[0]='a'+i;break;}
	printf("YES\n");
	printf("%s\n",a);
}

int main(){
	while(scanf("%s",s)!=EOF)
		work();
	return 0;
}

