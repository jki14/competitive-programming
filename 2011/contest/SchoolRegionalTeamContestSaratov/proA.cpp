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

#define L 31

char s[L];

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	while(scanf("%s",s)!=EOF){
		int x=(s[0]=='f')?0:1;
		int y;scanf("%d",&y);y--;
		int res=x^y;char c=res?'R':'L';
		printf("%c\n",c);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}


