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

#define N 3100
#define L 30

int n,d,mem,ans;

int c[N][N],res[N][N];
char cstr0[L],cstr1[L];
string s0,s1;

map<string,int> s;
map<string,int>::iterator it;

string a[N],b[N];int t[N];
string nam[N];

void work(){
	
	s.clear();mem=ans=0;
	memset(c,0x80,sizeof(c));

	//printf("c[0][0]=%d\n",c[0][0]);

	memset(res,0,sizeof(res));
	
	for(int i=0;i<n;i++){
		scanf("%s%s%d",cstr0,cstr1,&t[i]);
		s0=cstr0;s1=cstr1;a[i]=s0;b[i]=s1;
		s.insert(pair<string,int>(s0,0));
		s.insert(pair<string,int>(s1,0));
	}
	for(it=s.begin();it!=s.end();it++){
		(*it).second=mem;
		nam[mem++]=(*it).first;
	}
	
	for(int i=0;i<n;i++){
		
		if(i && t[i]!=t[i-1]){
			for(int j=i-1,val=t[i-1];j>=0 && t[j]==val;j--)
				c[s[a[j]]][s[b[j]]]=val;
		}

		int key=t[i]-c[s[b[i]]][s[a[i]]];
		if(key>0 && key<=d){
			if(res[s[a[i]]][s[b[i]]])continue;
			res[s[a[i]]][s[b[i]]]=res[s[b[i]]][s[a[i]]]=1;
			ans++;
		}

	}

	printf("%d\n",ans);
	for(int i=0;i<mem;i++)
		for(int j=i+1;j<mem;j++){
			if(res[i][j])printf("%s %s\n",nam[i].c_str(),nam[j].c_str());
		}

}

int main(){

	while(scanf("%d%d",&n,&d)!=EOF)
		work();
	return 0;

}
