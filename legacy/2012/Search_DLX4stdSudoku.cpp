//============================================================================
// Name        : DLX4stdSudoku
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 舞蹈链 解9x9标准数独
//============================================================================

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

#define N 800
#define M 400
#define S 320000
#define L 110
#define NUM 10

const int n = 729;
const int m = 324;

const int zero = (int)'0';
const int numChar[NUM]={ '0','1','2','3','4','5','6','7','8','9' };

int head[S],l[S],r[S],u[S],d[S],idx[S],idy[S];
int root,res[L],num[N];

char c[L];

void clear(){
	res[0]=num[0]=0;
	for(int i=1;i<=m+1;i++){
		head[i]=i;
		r[i]=i+1;l[i]=i-1;
		u[i]=i;d[i]=i;
		num[i]=idx[i]=idy[i]=0;
	}
	l[0]=r[0]=u[0]=d[0]=m+1;
	l[1]=m+1;r[m+1]=1;root=m+1;
}

void remove(const int &x){
	l[r[x]]=l[x];r[l[x]]=r[x];
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=u[j];d[u[j]]=d[j];
			num[head[j]]--;
		}
	}
}

void resume(const int &x){
	for(int i=d[x];i!=x;i=d[i]){
		for(int j=r[i];j!=i;j=r[j]){
			u[d[j]]=j;d[u[j]]=j;
			num[head[j]]++;
		}
	}
	l[r[x]]=x;r[l[x]]=x;
}

int dfs(const int &x){
	if(r[root]==root)return 1;
	int k=r[root];
	for(int i=r[root];i!=root;i=r[i]){
		if(num[i]<num[k])k=i;
	}
	remove(k);
	for(int i=d[k];i!=k;i=d[i]){
		//res[0]++;res[res[0]]=idx[i];
		res[idx[i]]=idy[i];
		for(int j=r[i];j!=i;j=r[j])remove(head[j]);
		if(dfs(x+1))return 1;
		for(int j=l[i];j!=i;j=l[j])resume(head[j]);
		//res[0]--;
	}
	resume(k);
	return 0;
}

int pos(const int &i,const int &j,const int &k){
	int x=(i-1)/9+1,y=(i-1)%9+1;
	switch(k){
		case 1:
			return x*9-9+j;
		case 2:
			return y*9-9+j+81;
		case 3:
			return (((x-1)/3)*3+((y-1)/3+1))*9-9+j+162;
		case 4:
			return i+243;
	}
	return -1;
}

void core(){
	clear();

	for(int i=1;i<=81;i++){
		if(c[i]=='.'){
			for(int val=1;val<=9;val++){
				for(int j=r[0]+1;j<=r[0]+4;j++){
					idx[j]=i;idy[j]=val;
					r[j]=j+1;l[j]=j-1;
					head[j]=pos(i,val,j-r[0]);
					u[j]=u[head[j]];d[j]=head[j];
					u[d[j]]=d[u[j]]=j;
					num[head[j]]++;
				}
				l[r[0]+1]=r[0]+4;r[r[0]+4]=r[0]+1;
				l[0]+=4;r[0]+=4;u[0]+=4;d[0]+=4;
			}
		}else{
			int val=((int)c[i])-zero;
			for(int j=r[0]+1;j<=r[0]+4;j++){
				idx[j]=i;idy[j]=val;
				r[j]=j+1;l[j]=j-1;
				head[j]=pos(i,val,j-r[0]);
				u[j]=u[head[j]];d[j]=head[j];
				u[d[j]]=d[u[j]]=j;
				num[head[j]]++;
			}
			l[r[0]+1]=r[0]+4;r[r[0]+4]=r[0]+1;
			l[0]+=4;r[0]+=4;u[0]+=4;d[0]+=4;
		}
	}

	/* simple check */
	/*for(int i=1;i<=m;i++){
		if(num[head[i]]==0){
			printf("head[i]==%d\n",head[i]);
			return;
		}
	}*/

	dfs(0);
}

int main(){
	//input
	for(int i=1;i<=81;i++){
		c[i]=getchar();
		while(!(c[i]=='.' || (c[i]>='0' && c[i]<='9')))c[i]=getchar();
	}

	core();

	//output
	for(int i=1,j=0;i<=81;i++,j++){
		if(j==9){	putchar('\n');j=0; }
		putchar(numChar[res[i]]);
	}
	putchar('\n');
	return 0;
}



