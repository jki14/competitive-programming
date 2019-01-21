#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

#define maxl 1000

int vis[maxl][maxl];
char str[maxl];
string s;

int nopair(const int &d){
	memset(vis,0,sizeof(vis));
	for(int k=0;k+d<(int)s.length();k++)
		if(vis[(int)s[k]][(int)s[k+d]])
			return 0;
		else
			vis[(int)s[k]][(int)s[k+d]]=1;
	return 1;
}

void work(){
	int dis;
	for(dis=1;dis<(int)s.length()-1 && nopair(dis);dis++);
	if(dis<(int)s.length()-1)
		printf("%s is NOT surprising.\n",s.c_str());
	else
		printf("%s is surprising.\n",s.c_str());
}

int main(){
	while(scanf("%s",str)!=EOF && str[0]!='*'){
		s=str;work();
	}
	return 0;
}
