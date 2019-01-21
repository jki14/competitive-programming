#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

const int maxn=51000;

int a[maxn];
map<int,int> s;
map<int,int>::iterator it;
int n,ans;

void doit(){
	int i,k,h;
	ans=n;h=1;
	s.clear();
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		k=a[i]-i;
		it=s.find(k);
		if(it==s.end()){
			s.insert(pair<int,int>(k,1));
			if(ans>n-1){
				ans=n-1;
				h=a[i]-i;
			}
		}
		else{
			(*it).second++;
			if(ans>n-(*it).second){
				ans=n-(*it).second;
				h=a[i]-i;
			}
		}
	}
	printf("%d\n",ans);
	for(i=0;i<n-1;i++)
		printf("%d ",h+i);
	printf("%d\n",h+n-1);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		doit();
	return 0;
}
