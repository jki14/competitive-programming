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

#define N 2100

typedef long long lld;

char s[N];int n;
int f[N][N];lld lef[N],rig[N],ans;

void work(){
	n=strlen(s);ans=0LL;
	memset(f,0,sizeof(f));
	memset(rig,0,sizeof(rig));
	memset(lef,0,sizeof(lef));
	
	for(int i=0;i<n;i++){ f[i][i]=1;lef[i]++;rig[i]++; }
	for(int i=1;i<n;i++)f[i][i-1]=1;

	for(int k=1;k<n;k++){
		for(int i=0;i+k<n;i++){int j=i+k;
			if(f[i+1][j-1] && s[i]==s[j]){
				f[i][j]=1;lef[j]++;rig[i]++;
			}
		}
	}

	for(int i=n-2;i>=0;i--)rig[i]=rig[i]+rig[i+1];
	for(int i=0;i<n;i++)ans+=lef[i]*rig[i+1];

	cout<<ans<<endl;
}

int main(){
	while(scanf("%s",s)!=EOF)
		work();
	return 0;
}

