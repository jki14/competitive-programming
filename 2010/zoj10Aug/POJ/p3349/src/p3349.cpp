#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define maxn 110000
#define m 6
#define q 23
#define p 87719

int n,a[maxn][m*3];
int res,x;

vector<int> s[p+3];

int rk(int s,int k){
	int i,j,res=0;
	for(i=s,j=1;j<=m;i+=k,j++){
		res+=(a[x][i]%p)*(((int)pow(q,m-j))%p);
		res%=p;
	}
	return res%p;
}

int cmp(int u,int v){
	int i,j,k,eq;
	for(i=m;i<m*2;i++)
		for(j=m;j<m*2;j++)
			if(a[u][i]==a[v][j]){
				eq=true;
				for(k=0;k<m;k++)
					if(a[u][i+k]!=a[v][j+k]){
						eq=false;break;
					}
				if(eq)return 1;
				eq=true;
				for(k=0;k<m;k++)
					if(a[u][i+k]!=a[v][j-k]){
						eq=false;break;
					}
				if(eq)return 1;
			}
	return 0;
}

void work(){
	res=0;for(x=0;x<p;x++)s[x].clear();
	for(x=0;x<n;x++){
		int hash=0;
		for(int j=0;j<m;j++){
			scanf("%d",&a[x][j]);a[x][j+m*2]=a[x][j+m]=a[x][j];
		}
		//for(int j=0;j<m;j++){ tmp=rk(j,1);if(hash<tmp)hash=tmp; }
		//for(int j=m;j<m*2;j++){ tmp=rk(j,-1);if(hash<tmp)hash=tmp; }
		for(int j=0;j<m;j++) hash+=a[x][j];
		hash%=p;
		s[hash].push_back(x);
	}
	for(x=0;x<p;x++)if(s[x].size()>1){
		for(int i=0;i<(int)s[x].size();i++)
			for(int j=i+1;j<(int)s[x].size();j++){
				if(cmp(s[x][i],s[x][j])){
					//cout<<">"<<s[x][i]<<" "<<s[x][j]<<"<"<<endl;
					printf("Twin snowflakes found.\n");
					return;
				}
			}
	}
	printf("No two snowflakes are alike.\n");
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
