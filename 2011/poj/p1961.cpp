#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<ctime>
#include<algorithm>
using namespace std;

#define maxn 1100000

char s[maxn];
int n,f[maxn];

void makefail(){
	int i,j;
	for(i=1,f[0]=j=-1;s[i];i++){	
		while(j!=-1 && s[i]!=s[j+1])j=f[j];
		if(s[i]==s[j+1])j++;
		f[i]=j;
	}
}

void work(){
	scanf("%s",s);
	makefail();
	for(int i=0;i<n;i++){
		//cout<<"f["<<i<<"]="<<f[i]<<endl;
		if(f[i]>-1 && (i+1)%(i-f[i])==0){
			printf("%d %d\n",i+1,(i+1)/(i-f[i]));
		}
	}
	printf("\n");
}

int main(){
	for(int i=1;scanf("%d",&n)!=EOF && n;i++){
		printf("Test case #%d\n",i);
		work();
	}
	return 0;
}

