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

#define K 9
#define M 12
#define L 11
#define H 23

const string s[H] = {
 /* 0*/"         _",
 /* 1*/"       _/ \\_",
 /* 2*/"     _/ \\_/ \\_",
 /* 3*/"   _/ \\_/ \\_/ \\_",
 /* 4*/" _/ \\_/ \\_/ \\_/ \\_",
 /* 5*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /* 6*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /* 7*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /* 8*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /* 9*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /*10*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /*11*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /*12*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /*13*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /*14*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /*15*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /*16*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /*17*/"/ \\_/ \\_/ \\_/ \\_/ \\",
 /*18*/"\\_/ \\_/ \\_/ \\_/ \\_/",
 /*19*/"  \\_/ \\_/ \\_/ \\_/",
 /*20*/"    \\_/ \\_/ \\_/",
 /*21*/"      \\_/ \\_/",
 /*22*/"        \\_/"
};

const int size[K]={ 7,8,9,10,11,10,9,8,7 };
const int open[K]={ 17,18,19,20,21,20,19,18,17 };
int n,ans,hig[K];
char c[K][M],opt[L];

string r[H];

void work(){
	memset(hig,0,sizeof(hig));ans=0;
	for(int i=0;i<n;i++){
		scanf("%s",opt);int k=opt[0]-'A';
		if(hig[k]==size[k])continue;
		if(hig[k] && c[k][hig[k]-1]==opt[1]){
			ans++;hig[k]--;
		}else c[k][hig[k]++]=opt[1];
	}
	printf("The number of candy is %d.\n",ans);
	for(int i=0;i<H;i++)r[i]=s[i];
	for(int k=0;k<K;k++){int posy=(k<<1)+1;
		for(int i=0,posx=open[k];i<hig[k];i++,posx-=2){
			r[posx][posy]=c[k][i];
		}
	}
	for(int i=0;i<H;i++)printf("%s\n",r[i].c_str());
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

