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

#define L 11000

char s[L];

void work(){
	int h=0,dec;s[strlen(s)+1]=0;
	for(int pos=1;s[pos];pos++){
		if(s[pos]!='/'){ h++;dec=0; }else dec=1;
		for(int k=1;k<h;k++)printf("  ");printf("<");
		for(;s[pos] && s[pos]!='<';pos++)printf("%c",s[pos]);
		printf("\n");
		if(dec)h--;
	}
}

int main(){
	while(scanf("%s",s)!=EOF)
		work();
	return 0;
}

