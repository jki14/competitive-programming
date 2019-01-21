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

#define L 110

const double eps=1e-4;

int n,m;
double k;

map<string, int> a;
map<string, int>::iterator it;

string s;

char str[L];

void work(){
	a.clear();
	for(int i=0;i<n;i++){
		int val;scanf("%s%d",str,&val);
		val=floor(((double)val)*k+eps);
		if(val<100)continue;
		s=str;a.insert(pair<string, int>(s,val));
	}
	for(int i=0;i<m;i++){
		scanf("%s",str);s=str;
		it=a.find(s);
		if(it==a.end()){
			a.insert(pair<string ,int>(s,0));
		}
	}
	printf("%d\n",a.size());
	for(it=a.begin();it!=a.end();it++)
		printf("%s %d\n",(*it).first.c_str(),(*it).second);
}

int main(){
	while(scanf("%d%d%lf",&n,&m,&k)!=EOF)
		work();
	return 0;
}

