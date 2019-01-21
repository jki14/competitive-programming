#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 11000
#define maxc 110000
#define maxp 5

int n,res;
int h[maxc],r[maxn],mk[maxn];
int a[maxc][maxp];

map<int,int> v;
map<int,int>::iterator it;

void work(){
	int i,j,k,p;
	res=0;v.clear();
	memset(a,0,sizeof(a));
	memset(h,0,sizeof(h));
	memset(r,0,sizeof(r));
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&k);
			v.insert(pair<int,int>(k,1));
			if(r[k]==i)continue;
			r[k]=i;
			if(a[k][0]>2)continue;
			a[k][0]++;a[k][a[k][0]]=i;
		}
	}
	for(it=v.begin();it!=v.end();it++){k=(*it).first;
		if(a[k][0]!=1)continue;
		h[a[k][1]]+=2;
		res=max(res,h[a[k][1]]);
		//cout<<"T1P:"<<k<<endl;
	}
	for(it=v.begin();it!=v.end();it++){k=(*it).first;
		if(a[k][0]!=2)continue;
		if(h[a[k][1]]==h[a[k][2]]){
			p=((rand()%2)==0)?a[k][1]:a[k][2];
		}else{
			if(h[a[k][1]]<h[a[k][2]])
				p=a[k][1];
			else
				p=a[k][2];
		}
		h[p]++;
		res=max(res,h[p]);
		//cout<<"T2P:"<<k<<endl;
	}
	printf("%d\n",res);
}

int main(){
	srand(514);
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

