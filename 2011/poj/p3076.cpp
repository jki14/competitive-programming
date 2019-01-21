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

#define N 5000
#define M 1100
#define S 1100000
#define L 300
#define C 20

const int n = 4096;
const int m = 1024;

const int int0 = ((int)'A')-1;

int head[S],l[S],r[S],u[S],d[S],idx[S],idy[S];
int root,res[L],num[M];

char c[C][C];

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
	int x=(i-1)/16+1,y=(i-1)%16+1;
	switch(k){
		case 1:
			return x*16-16+j;
		case 2:
			return y*16-16+j+256;
		case 3:
			return (((x-1)/4)*4+((y-1)/4+1))*16-16+j+512;
		case 4:
			return i+768;
	}
	return -1;
}

void work(){
	clear();

	for(int x=0;x<16;x++)for(int y=0;y<16;y++){int i=x*16+y+1;
		if(c[x][y]=='-'){
			for(int val=1;val<=16;val++){
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
			int val=((int)c[x][y])-int0;
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
	for(int i=1;i<=m;i++){
		if(num[head[i]]==0){
			//printf("head[i]==%d\n",head[i]);	
			return;
		}
	}

	dfs(0);
	for(int i=1;i<=256;i++){
		printf("%c",'A'+res[i]-1);
		if(!(i%16))printf("\n");
	}
	printf("\n");
;
}

int main(){
	while(scanf("%s",c[0])!=EOF){
		for(int i=1;i<16;i++)scanf("%s",c[i]);
		work();
	}
	return 0;
}

