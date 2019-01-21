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

#define LEN 1100

const int chra=(int)'a';
const int chrA=(int)'A';
const int delt=chrA-chra;

char s[LEN];

void work(){
	int ret=0,i=0;
	while(s[i] && (s[i]<'A' || s[i]>'Z'))i++;
	while(s[i]){
		ret+=s[i]-'A'+1;
		i++;while(s[i] && (s[i]<'A' || s[i]>'Z'))i++;
	}
	if(ret>100)
		printf("INVALID\n");
	else
		printf("%d\n",ret);
}

int main(){
	while(gets(s))
		work();
	return 0;
}

