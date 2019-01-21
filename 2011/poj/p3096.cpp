#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxlen 100
#define charnum 26

const int intA=(int)'A';

char str[maxlen];
int mk[charnum][charnum];

int work(){
	int k,i,len=strlen(str);
	for(k=1;k<len;k++){
		memset(mk,0,sizeof(mk));
		for(i=0;i+k<len;i++){
			if(mk[(int)str[i]-intA][(int)str[i+k]-intA]) return 0;
			mk[(int)str[i]-intA][(int)str[i+k]-intA]=1;
		}
	}
	return 1;
}

int main(){
	while(scanf("%s",str)!=EOF && str[0]!='*'){
		if(work())
			printf("%s is surprising.\n",str);
		else
			printf("%s is NOT surprising.\n",str);
	}
	return 0;
}

