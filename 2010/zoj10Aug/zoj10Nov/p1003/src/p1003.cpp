#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define slen 110
#define maxn 2100
#define lmt 2010

int x,y,z;
int idx[maxn],idy[maxn],idz[maxn];
int _idx[maxn],_idy[maxn],_idz[maxn];
char cstr[slen];

int opr(){
	if(cstr[0]=='F'){
		if(cstr[2]=='L')return 0;
		return 4;
	}
	if(cstr[0]=='S'){
		if(cstr[4]=='1')return 1;
		if(cstr[4]=='2')return 2;
		return 3;
	}
	return 5;
}

void find(int val){
	if(val>x*y*z)return;
	val--;int i,j,k;
	i=val/(y*z);while(val>=(y*z) || val<0)val%=(y*z);
	j=val/z;while(val>=z || val<0)val%=z;
	k=val;
	printf("%d %d %d\n",_idx[i],_idy[j],_idz[k]);
}

void query(int i,int j,int k){
	if(idx[i]>=x || idy[j]>=y || idz[k]>=z){
		printf("0\n");
		return;
	}
	int res=idx[i]*(y*z)+idy[j]*z+idz[k]+1;
	printf("%d\n",res);
}

void fill(){
	for(int i=0;i<lmt;i++)_idx[i]=_idy[i]=_idz[i]=idx[i]=idy[i]=idz[i]=i;
	puts("START");
}

void work(){
	int i,j,k;switch(opr()){
		case 0:
			scanf("%d%d%d",&x,&y,&z);fill();break;
		case 1:
			scanf("%d%d",&i,&j);
			swap(idx[i],idx[j]);
			_idx[idx[i]]=i;
			_idx[idx[j]]=j;
			break;
		case 2:
			scanf("%d%d",&i,&j);
			swap(idy[i],idy[j]);
			_idy[idy[i]]=i;
			_idy[idy[j]]=j;
			break;
		case 3:
			scanf("%d%d",&i,&j);
			swap(idz[i],idz[j]);
			_idz[idz[i]]=i;
			_idz[idz[j]]=j;
			break;
		case 4:
			scanf("%d",&i);find(i);break;
		case 5:
			scanf("%d%d%d",&i,&j,&k);query(i,j,k);break;
	}
}

int main(){
	while(scanf("%s",cstr)!=EOF)work();
	return 0;
}
