#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 20
#define maxk 10000
#define maxl 100

int n;
char a[maxn][maxl],b[maxn][maxl];
char s[maxl],tmp[maxl];

int cmp(int x,int y){
	int k=0;
	while(a[y][k]){
		if(!s[x] || s[x]!=a[y][k])return 0;
		k++;x++;
	}
	return 1;
}

void work(){
	scanf("%s",tmp);
	printf("%s\n",tmp);
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%s%s",a[i],b[i]);
	scanf("%s",s);
	for(i=0;i<(int)strlen(s);i++){
		for(j=0;j<n;j++)
			if(s[i]==a[j][0] && cmp(i,j)){
				printf("%s\n\n",b[j]);
				return;
			}
	}
	printf("Nothing Happened\n\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)
		work();
	return 0;
}
