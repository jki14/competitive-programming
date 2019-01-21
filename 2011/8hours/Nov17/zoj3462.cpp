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

typedef long long lld;

#define N 3100
#define L 1100000

int n,m;
lld w[N],ans;
set<int> s[N];
set<int>::iterator it;

map<int,int> d;
map<int,int>::iterator jt;

char a[L],b[L];
int que[N],num;

int hash(char *s){
	int hash = 5381;
	for(;*s;s++){
		hash += (hash<<5) + (*s);
	}
	return hash & 0x7FFFFFFF;
}

int cmp(const int &x,const int &y){ return d[x]<d[y]; }

void work(){d.clear();
	for(int i=0;i<n;i++){s[i].clear();
		scanf("%s%lld",a,&w[i]);
		for(int j=0,k;a[j];j++){
			if(a[j]=='['){
				k=0;
			}else if(a[j]==']'){b[k++]=0;
				int val=hash(b);
				//printf("%s=%d\n",b,val);
				s[i].insert(val);
				jt=d.find(val);
				if(jt==d.end()){
					d.insert(pair<int,int>(val,1));
				}else (*jt).second++;
			}else b[k++]=a[j];
		}
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s",a);num=0;ans=0LL;
		for(int j=0,k;a[j];j++){
			if(a[j]=='['){
				k=0;
			}else if(a[j]==']'){
				b[k++]=0;que[num++]=hash(b);
			}else b[k++]=a[j];
		}
		sort(que,que+num,cmp);
		//printf("que[0]=%d\n",que[0]);
		if(d[que[0]]){
			for(int j=0;j<n;j++){
				for(int k=0;k<num;k++){
					it=s[j].find(que[k]);
					if(it==s[j].end())break;
					if(k==num-1)ans+=w[j];
				}
			}
		}
		printf("%lld\n",ans);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

