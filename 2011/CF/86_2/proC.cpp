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

#define N 1100000
#define K 6
#define T 3

const string sf[K]={    "lios","liala",
			"etr","etra",
			"initis","inites" };

char a[N],s[N];
int n,sd,p,num[T];
int gender;

int suffix(int x){
	int len=strlen(s);
	if(len<(int)sf[x].length())return 0;
	for(int i=len-sf[x].length();i<len;i++)
		if(s[i]!=sf[x][i-len+sf[x].length()])return 0;
	return 1;
}

int kind(){
	for(int k=0;k<K;k++)
		if(suffix(k)){
			if(gender!=-1){
				if(gender!=(k&1))return -1;
			}else gender=(k&1);
			return k>>1;
		}
	return -1;
}

void work(){
	memset(num,0,sizeof(num));
	n=strlen(a);s[0]=0;sd=p=0;
	gender=-1;
	/*for(int i=0;i<=n;i++){*/
		//if(i==n || a[i]==' '){s[p++]=0;p=0;
		while(scanf("%s",s)!=EOF){
			if(!strlen(s))continue;
			if(sd){
				printf("NO\n");
				return;
			}
			int k=kind();
			//printf("%s(%d) ",s,k);
			if(k< 0){
				printf("NO\n");
				return;
			}
			if(k==0){
				if(num[k+1] || num[k+2]){
					printf("NO\n");
					return;
				}else num[k]++;
			}
			if(k==1){
				if(num[k] || num[k+1]){
					printf("NO\n");
					return;
				}else num[k]++;
			}
			if(k==2){
				if(!num[k-1]){
					if(!num[k-2] && !num[k]){
						sd=1;num[k]++;
					}else{
						printf("NO\n");
						return;
					}
				}else num[k]++;
			}
		}/*else{
			s[p++]=a[i];
		}
	}*/
	if(num[0]+num[1]+num[2]>1 && num[1]==0){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(){
	//while(gets(a))
		work();
	return 0;
}


