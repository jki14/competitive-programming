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

#define N 10
#define k 2

map<char,int> s;
map<char,int>::iterator it;

int T;

int n,m;
int a[k][N],f[N][N];
char c[k][N];

int cost(const int &i,const int &j){
	int ret=(a[0][i]>0)+(a[1][i]>0)+(a[0][j]>0)+(a[1][j]>0);
	if(a[0][i] && a[0][i]==a[0][j])ret--;
	if(a[1][i] && a[1][i]==a[1][j])ret--;
	if((a[0][i] && a[0][i]==a[1][j])
		||(a[1][i] && a[1][i]==a[0][j]))ret--;
	return ret;
}

void work(){
	int i,j,l;

	memset(f,0x3f,sizeof(f));s.clear();m=0;
	scanf("%d",&n);scanf("%s",c[0]);scanf("%s",c[1]);
	for(i=0;i<n;i++){
		s.insert(pair<char,int>(c[0][i],0));
		s.insert(pair<char,int>(c[1][i],0));
	}
	for(it=s.begin();it!=s.end();it++)(*it).second=++m;
	for(i=0;i<k;i++)
		for(j=0;j<n;j++)a[i][j]=s[c[i][j]];
	for(i=k-1;i>=0;i--)
		for(j=n-1;j>=0;j--){
			if(i && a[i][j]==a[i-1][j])a[i][j]=0;
			if(j && a[i][j]==a[i][j-1])a[i][j]=0;
		}

	for(i=1;i<n;i++)f[i][i-1]=0;
	for(i=0;i<n;i++)f[i][i]=(a[0][i]>0)+(a[1][i]>0);
	for(l=1;l<n;l++){
		for(i=0;i+l<n;i++){
			f[i][i+l]=cost(i,i+l)+f[i+1][i+l-1];
			for(j=i;j<i+l;j++)f[i][i+l]=min(f[i][i+l],f[i][j]+f[j+1][i+l]);

			//printf("f[%d][%d]=%d\n",i,i+l,f[i][i+l]);

		}
	}
	printf("Case #%d: %d\n",T,f[0][n-1]);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

