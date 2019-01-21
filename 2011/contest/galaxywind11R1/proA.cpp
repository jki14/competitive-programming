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
#include<set>
#include<map>
using namespace std;

#define C 26
#define L 110

int T;

const int c2i[C]={ 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7 };

char s[L];

void work(){
	scanf("%s",s);
	int ans=0;
	for(int i=1;s[i];i++)
		if(c2i[s[i]-'A']!=c2i[s[i-1]-'A'])ans++;
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

