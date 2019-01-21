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

#define K 12

//const string s[K]={ "Rat","Ox","Tiger","Rabbit","Dragon","Snake","Horse","Ram","Monkey","Rooster","Dog","Pig" };

const string s[K]={ "Rabbit","Tiger","Ox","Rat","Pig","Dog","Rooster","Monkey","Ram","Horse","Snake","Dragon" };

void work(){
	int d;
	scanf("%d",&d);d-=1;
	d=( d % K + K) % K;
	printf("%s\n",s[d].c_str());
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

