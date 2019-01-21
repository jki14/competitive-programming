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

#define S 11000
#define L 1100
#define M 10
#define E 8

map<string ,int> s;
map<string ,int>::iterator it;

const char x[E]={ 'o','i','e','a','s','t','b','g' };
const char y[E]={ '0','1','3','4','5','7','8','9' };

int n,k,num,ans,f[S],g[S];
char a[L],b[L];
char c[S][M];

string str;

void ext(){
	s.insert(pair<string ,int>(str,0));
	char lef=0,rig=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<E;j++){
			if(str[i]==x[j]){
				if(i==0)
					lef=y[j];
				else rig=y[j];
			}
		}
	}
	if(lef){ char ori=str[0];str[0]=lef;s.insert(pair<string ,int>(str,0));str[0]=ori; }
	if(rig){ char ori=str[1];str[1]=rig;s.insert(pair<string ,int>(str,0));str[1]=ori; }
	if(lef && rig){ str[0]=lef;str[1]=rig;s.insert(pair<string ,int>(str,0)); }
}

int find(const int &i){ if(f[i]!=i)f[i]=find(f[i]);return f[i]; }

int main(){
	int T;scanf("%d",&T);
	for(int ti=1;ti<=T;ti++){
		scanf("%d%s",&k,a);n=strlen(a);b[2]=ans=num=0;s.clear();
		for(int i=0;i+1<n;i++){
			b[0]=a[i];b[1]=a[i+1];
			str=b;ext();
		}
		for(it =s.begin();it!=s.end();it++){
			c[num][0]=(*it).first[0];
			c[num][1]=(*it).first[1];
			c[num][2]=0;

			printf("c:%s\n",c[num]);

			num++;ans+=2;
		}
		for(int i=0;i<num;i++)f[i]=g[i]=i;
		for(int go=1;go;){go=0;
			for(int i=0;i<num;i++){
				int j,bad=-1;
				for(j=0;j<num;j++){
					if(f[j]!=j)continue;
					if(find(i)==j)continue;
					if(c[find(i)][0]==c[j][1] && c[i][1]==c[j][0]){
						bad=j;continue;
					}
					if(c[i][1]==c[j][0]){
						//go=1;
						f[j]=i;ans--;

						printf("link %s -> %s\n",c[i],c[j]);

						break;

					}
				}
				if(j==num && bad>=0){ f[bad]=i;ans--;printf("link %s x> %s\n",c[i],c[bad]); }
			}
		}
		printf("Case #%d: %d\n",ti,ans);
	}
	return 0;
}
