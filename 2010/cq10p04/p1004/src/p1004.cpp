#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int maxn=1000005;

int timer;
int n,m,maxk;
vector<int> f;
vector<int> s;
long long ans,tmp;
bool mark[maxn];

void doit(){
	f.clear();int i,a=n;ans=1;bool cr;
	for(i=0;i<(int)s.size() && a>1 && s[i]<=a;i++){
		cr=true;
		while(a%s[i]==0){
			a/=s[i];
			if(cr){
				f.push_back(0);
				cr=false;
			}
			f[f.size()-1]++;
		}
	}
	for(i=0;i<(int)f.size();i++){
		tmp = (f[i]*m+1) % 10007;
		tmp = (tmp * (tmp + 1)) / 2;
		tmp %= 10007;
		ans = (ans * tmp * tmp) % 10007;
	}
	//cout<<tot;
	printf("Case %d: %lld\n",timer++,ans);
}

int main(){
	timer=1;maxk=0;
	int i,j;s.clear();
	memset(mark,1,sizeof(mark));
	for(i=2;i<maxn;i++){
		if(mark[i])s.push_back(i);
		for(j=0;j<(int)s.size() && i*s[j]<maxn;j++){
			mark[i*s[j]]=false;
			if (i % s[j] == 0) break;
		}
	}
	while(scanf("%d%d",&n,&m)!=EOF) doit();
	return 0;
}
