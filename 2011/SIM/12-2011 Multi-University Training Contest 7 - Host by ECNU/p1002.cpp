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

#define N 110000

int f[N];
int n,m;
char a[N],s[N];

void makefail(){
	int i,k,beg;
	f[0]=k=beg=-1;
	for(i=1;s[i];i++){
		if(s[i]=='*'){
			f[i]=k=beg=i;i++;
			f[i]=beg;
		}else{	
			for(k=f[i-1];k>beg && s[i]!='?' && s[k+1]!='?' && s[i]!=s[k+1];)k=f[k];
			if(s[i]=='?' || s[k+1]=='?' || s[i]==s[k+1])
				f[i]=k+1;
			else f[i]=beg;
		}
	}	
}

int match(){
	for(int i=0;1;i++){
		if(s[i]=='*')break;
		if(s[i]!='?' && s[i]!=a[i])return 0;
		if(!s[i])break;
	}
	for(int i=m-1;i>=0;i--){
		if(s[i]=='*')break;
		if(s[i]!='?' && s[i]!=a[n-m+i])return 0;
	}
	return 1;
}

void work(){
	n=strlen(a);m=strlen(s);
	makefail();
	/*for(int i=0;s[i];i++)printf("  %c",s[i]);printf("\n");
	for(int i=0;s[i];i++)printf("%3d",f[i]);printf("\n");*/

	if(!match()){
		printf("NO\n");
		return;
	}

	int i,j;
	for(i=j=0;i<n && j<m;){
		if(s[j]=='*'){
			j++;
		}else{
			if(s[j]=='?' || a[i]==s[j]){ i++;j++; }
			else if(j==0 || s[j-1]=='*') i++;
			else j=f[j-1]+1;
		}
		//printf("i=%d j=%d s[j]=%c\n",i,j,s[j]);
	}
	
	if(j<m){
		printf("NO\n");
		return;
	}

	printf("YES\n");
}

int main(){
	while(scanf("%s%s",a,s)!=EOF)
		work();
	return 0;
}

