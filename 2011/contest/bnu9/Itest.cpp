#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

char s[10];

int check(){
	for(int i=0;i<(int)strlen(s);i++){
		if(s[i]=='4')return 0;
		if(s[i]=='1' && s[i+1] && s[i+1]=='3')return 0;
	}
	return 1;
}

int main(){
	int i,res;
	for(i=0;i<10000000;i++){
		sprintf(s,"%d",i);
		if(check())res++;
	}
	cout<<res<<endl;
}

