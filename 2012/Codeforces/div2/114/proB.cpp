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

#define L 1100000

int fir=0;
char s[L];

int check(){
	for(int i=0;s[i];i++){
		if(s[i]==' ')continue;
		if(s[i]=='#')
			return 1;
		else return 0;
	}
	return 0;
}

int main(){
	while(gets(s)){
		if(check()){
			if(fir)putchar('\n');
			puts(s);fir=0;
		}else{
			for(int i=0;s[i];i++){
				if(s[i]==' ')continue;
				putchar(s[i]);
			}fir=1;
		}
	}
	if(fir)putchar('\n');
	return 0;
}
