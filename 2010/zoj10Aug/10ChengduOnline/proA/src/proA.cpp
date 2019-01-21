#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 110
#define lmt 1000000000
#define ll l+x[j]
#define rr r+y[j]

const int zero=(int)'0';
const int x[9]={-1,-1,-1,0,0,0,1,1,1};
const int y[9]={-1,0,1,-1,0,1,-1,0,1};

int n,res;
char s[maxn];
int a[maxn];
int f[maxn][maxn][maxn];

int slength(char s[]){
	int i=0;while(s[i])i++;
	return i;
}

void doit(){
	int i,l,r,k,j;
	res=LONG_MAX;
	memset(f,0x7f,sizeof(f));
	f[0][5][6]=0;
	n=slength(s);
	for(i=0;i<n;i++){
		if(i<n)
			k=(int)s[i]-zero;
		else
			k=-1;
		for(l=0;l<9;l++)
			for(r=l+1;r<10;r++){
				for(j=0;j<9;j++)if(ll<rr && ll>=0 && rr<10){
					if(f[i][l][r]>f[i][ll][rr]+1)f[i][l][r]=f[i][ll][rr]+1;
					if(x[j]==0 && ll==k && f[i+1][ll][rr]>f[i][l][r]+1)f[i+1][ll][rr]=f[i][l][r]+1;
					if(y[j]==0 && rr==k && f[i+1][ll][rr]>f[i][l][r]+1)f[i+1][ll][rr]=f[i][l][r]+1;
				}
			}
	}
	for(l=0;l<9;l++)
		for(r=l+1;r<10;r++)
			if(res>f[n][l][r])res=f[n][l][r];
	printf("%d\n",res);
}

int main(){
	while(scanf("%s",s)!=EOF)doit();
	return 0;
}
