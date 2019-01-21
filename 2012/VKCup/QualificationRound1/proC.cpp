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

#define S 11000
#define L 210

int n,k;
char f[S][L],opt[L];

void cd(char *s){
	if(*s=='/'){ k=0;s++; }
	for(;*s;s++){

		//printf("  *s == %c\n",*s);

		int pnt=0;
		while(*s && *s!='/'){ f[k][pnt++]=*s;s++; }
		f[k][pnt]=0;
		if(pnt==2 && f[k][0]=='.' && f[k][1]=='.'){
			if(k)k--;
		}else k++;

		if(! *s)break;

	}
}

void work(){k=0;
	for(int i=0;i<n;i++){
		scanf("%s",opt);
		if(opt[0]=='p'){printf("/");
			for(int j=0;j<k;j++)printf("%s/",f[j]);
			printf("\n");
		}else{
			scanf("%s",opt);
			//printf("opt=%s\n",opt);
			cd(opt);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
