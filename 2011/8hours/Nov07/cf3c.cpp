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

#define L 10

const int n=3;

int xopt,draw;
char a[L][L];

int win(const char &c){
	int ret=0;
	for(int i=0;i<n;i++){int j;
		for(j=0;j<n;j++)if(a[i][j]!=c)break;
		if(j==n)ret++;
		for(j=0;j<n;j++)if(a[j][i]!=c)break;
		if(j==n)ret++;
	}
	if(a[0][0]==c && a[1][1]==c && a[2][2]==c)ret++;
	if(a[0][2]==c && a[1][1]==c && a[2][0]==c)ret++;
	return ret;
}

int ill(){
	if(win('X') && win('0'))return 1;
	int cntx,cnto,cntd;cntx=cnto=cntd=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!='.'){
				if(a[i][j]=='X')
					cntx++;
				else cnto++;
			}else cntd++;
	
	//printf("cntx=%d cnto=%d cntd=%d\n",cntx,cnto,cntd);
	
	if(cntx!=cnto && cntx-1!=cnto)return 1;
	if(win('X') && cntx==cnto)return 1;
	if(win('0') && cntx-1==cnto)return 1;
	if(cntx>5 || cnto>5)return 1;
	xopt = (cntx==cnto);
	draw=cntd?0:1;
	return 0;	
}

int main(){
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	if(ill()){
		printf("illegal\n");
		return 0;
	}
	if(win('X'))
		printf("the first player won\n");
	else if(win('0'))
		printf("the second player won\n");
	else if(draw)
		printf("draw\n");
	else if(xopt)
		printf("first\n");
	else printf("second\n");
	return 0;
}


