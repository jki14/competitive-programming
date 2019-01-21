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
	f[0]=k=beg=-1;i=1;
	if(s[0]=='*'){
		for(int j=0;s[j]=='*';){
			f[j]=k=beg=j;j++;
			f[j]=beg;i++;
		}
	}
	for(;s[i];i++){
		if(s[i]=='*'){
			/*f[i]=k=beg=i;i++;
			f[i]=beg;*/
			while(s[i]=='*'){
				f[i]=k=beg=i;i++;
				f[i]=beg;
			}
			if(!s[i])break;
		}else{	
			for(k=f[i-1];k>beg && s[i]!='?' && s[k+1]!='?' && s[i]!=s[k+1];)k=f[k];
			//printf("s[i]=%c s[k+1]=%c\n",s[i],s[k+1]);
			if(s[i]=='?' || s[k+1]=='?' || s[i]==s[k+1])
				f[i]=k+1;
			else f[i]=beg;
			//printf("f[%d]=%d\n",i,f[i]);
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
		//printf("s[i]=%c a[n-m+i]=%c\n",s[i],a[n-m+i]);
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
		//printf("match fail\n");
		printf("NO\n");
		return;
	}

	int i,j;
	for(i=j=0;i<n && j<m;){
		printf("i=%d j=%d a[i]=%c s[j]=%c\n",i,j,a[i],s[j]);
		if(s[j]=='*'){
			j++;
		}else{
			if(s[j]=='?' || a[i]==s[j]){ i++;j++; }
			else if(j==0 || s[j-1]=='*') i++;
			else{
			       	//printf("f[%d]=%d\n",j-1,f[j-1]);
				j=f[j-1]+1;
			}
		}
	}
	
	if(j<m){
		printf("NO\n");
		return;
	}

	printf("YES\n");
}

int main(){//int T=0;
	while(scanf("%s%s",a,s)!=EOF){
		//printf("Case #%d: ",++T);
		work();
	}
	return 0;
}

