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

#define N 1100
#define L 11000

map<string, string> s2g;
map<string, string> g2s;
map<string, string>::iterator it;

int n;
char cstr[L],temp[10];

string s[N];

int main(){

	s2g.clear();g2s.clear();

	s2g.insert(pair<string, string>("A" ,"---*------*---*--*"));
	s2g.insert(pair<string, string>("G" ,"--*----------*---*"));
	s2g.insert(pair<string, string>("Am","---*---*--*-------"));
	s2g.insert(pair<string, string>("F" ,"*--*--**-*-**-**--"));
	s2g.insert(pair<string, string>("Dm","*----*-*----------"));
	s2g.insert(pair<string, string>("A5","-----------20-----"));
	s2g.insert(pair<string, string>("B5","-----------53-----"));
	s2g.insert(pair<string, string>("D5","-----------75-----"));
	s2g.insert(pair<string, string>("E5","-------------2----"));

	g2s.insert(pair<string, string>("---*------*---*--*" ,"A" ));
	g2s.insert(pair<string, string>("--*----------*---*" ,"G" ));
	g2s.insert(pair<string, string>("---*---*--*-------" ,"Am"));
	g2s.insert(pair<string, string>("*--*--**-*-**-**--" ,"F" ));
	g2s.insert(pair<string, string>("*----*-*----------" ,"Dm"));
	g2s.insert(pair<string, string>("-----------20-----" ,"A5"));
	g2s.insert(pair<string, string>("-----------53-----" ,"B5"));
	g2s.insert(pair<string, string>("-----------75-----" ,"D5"));
	g2s.insert(pair<string, string>("-------------2----" ,"E5"));

	int kind;while(scanf("%d",&kind)!=EOF && kind){scanf("%d",&n);
		switch(kind){
			case 1:
				scanf("%s",cstr);
				for(int i=0,k=0;cstr[i];i++){
					if('A'<=cstr[i] && cstr[i]<='Z'){
						k++;s[k].clear();
					}
					s[k].push_back(cstr[i]);
				}
				for(int i=0;i<6;i++){printf("|");
					for(int j=1;j<=n;j++){
						it=s2g.find(s[j]);
						for(int x=i*3;x<(i+1)*3;x++)printf("%c",(*it).second[x]);
						printf("|");
					}
					printf("\n");
				}
				break;
			case 2:
				for(int i=1;i<=n;i++)s[i].clear();
				for(int i=0;i<6;i++){
					scanf("%s",cstr);
					for(int j=1;j<=n;j++)
						for(int x=(j-1)*4+1;x<j*4;x++)s[j].push_back(cstr[x]);
				}
				for(int i=1;i<=n;i++){
					it=g2s.find(s[i]);
					printf("%s",(*it).second.c_str());
				}
				printf("\n");	
		}
	}
	
	return 0;

}
