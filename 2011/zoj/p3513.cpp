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
#include<set>
#include<map>
using namespace std;

#define maxn 110000

int n,m,timer;
int x[maxn],y[maxn];
vector<char> s;
vector< vector<char> > a;

void work(){timer++;
	int i,j;
	a.clear();s.clear();
	for(j=0;j<=m;j++)s.push_back('H');
	for(i=0;i<=n;i++){
		a.push_back(s);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(i==j){
				a[i][j]='P';
				continue;
			}
			if(i>j && i<j*2 && a[i-j][j]=='H'){
				a[i][j]='P';
				continue;
			}
			if(j>i && j<i*2 && a[i][j-i]=='H'){
				a[i][j]='P';
				continue;
			}
		}
	printf("Case #%d:\n",timer);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
}

int main(){timer=0;
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

