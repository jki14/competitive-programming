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

#define L 1100000

int f[L];
int n,m,ans;
char a[L],s[L];

void makefail(){
	int i,k;
	f[0]=k=-1;
	for(i=1;s[i];i++){
		for(k=f[i-1];k>-1 && s[i]!=s[k+1];)k=f[k];
		if(s[i]==s[k+1])
			f[i]=k+1;
		else f[i]=-1;
	}
}

void work(){
	scanf("%s",s);m=strlen(s);s[m++]='$';
	scanf("%s",a);n=strlen(a);a[n++]='#';
	
	makefail();ans=0;
	for(int i=0,j=0;i<n && j<m;){
		if(s[j]=='$')ans++;
		
		if(a[i]==s[j]){ i++;j++; }
		else if(j==0)i++;
		else j=f[j-1]+1;
	}

	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

