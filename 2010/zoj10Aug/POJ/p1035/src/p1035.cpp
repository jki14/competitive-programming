#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

#define maxm 11000
#define maxn 51
#define maxl 20

char s[maxm][maxl];
char str[maxl];
map<string,int> c;
map<string,int>::iterator it;
string tmp;
int m;

int slength(char *s){
	int l=0;
	while(s[l])l++;
	return l;
}

int more1(char *x,char *y){
	int i,l=slength(x),d=0;
	for(i=0;i<l;i++){
		if(x[i]!=y[i+d]){
			if(!d){
				d=1;i--;
			}
			else
				return 0;
		}
	}
	return 1;
}

int diff1(char *x,char *y){
	int i,l=slength(x),d=0;
	for(i=0;i<l;i++){
		if(x[i]!=y[i])d++;
		if(d>1)return 0;
	}
	return 1;
}

int re(int x){
	if(slength(s[x])+1==slength(str)){
		return more1(s[x],str);
	}
	if(slength(s[x])==slength(str)){
		return diff1(s[x],str);
	}
	if(slength(s[x])==slength(str)+1){
		return more1(str,s[x]);
	}
	return 0;
}

void makes(){
	m=0;
	while(scanf("%s",s[m])!=EOF && s[m][0]!='#'){
		tmp=s[m];c.insert(pair<string,int>(tmp,0));
		m++;
	}
}

void work(){
	int i;
	while(scanf("%s",str)!=EOF && str[0]!='#'){
		tmp=str;it=c.find(tmp);
		if(it!=c.end()){ printf("%s is correct\n",str);continue; }
		printf("%s:",str);
		for(i=0;i<m;i++)
			if(re(i))
				printf(" %s",s[i]);
		printf("\n");
	}
}

int main(){
	makes();
	work();
	return 0;
}
