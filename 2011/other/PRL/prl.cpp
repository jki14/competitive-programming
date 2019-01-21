#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

char x;
char str[100];
int a[1000],rk[1000],id[1000],k;

int cmp(const int &x,const int &y){ return rk[x]<rk[y]; }

int main(){
	srand(time(NULL));k=0;while(scanf("%c",&x)!=EOF){
		if(x!='p')continue;
		if(scanf("%c",&x)!=EOF && x=='o' && scanf("%c",&x)!=EOF && x=='j'){
			scanf("%c%c%c%c",&str[0],&str[1],&str[2],&str[3]);str[4]=NULL;
			sscanf(str,"%d",&a[k]);
			id[k]=k;rk[k++]=rand();
		}
	}
	sort(id,id+k,cmp);
	for(int i=0;i<k;i++){
		printf("%3d->poj%d\n",i+1,a[id[i]]);
	}
	return 0;
}
