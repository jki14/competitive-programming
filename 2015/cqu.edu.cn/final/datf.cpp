#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>
using namespace std;

const int T=10;

const int N=1000;
const int D=1000;

char buf[32];
set<string> s;

string name[100086];

int main(){
	srand(time(NULL));
	printf("%d\n", T);
	for(int _T=1; _T<=T; _T++){
		int n, m, d;
		s.clear();
		n=rand()%N+1;
		if(_T==1)n=1;
		m=rand()%max(1, (n>>1))+2;
		if(_T==2)m=100000;
		if(_T==3)m=2;
		if(_T==4)m=3;
		if(_T>7)m=7;
		d=rand()%10000+1;
		for(int i=0; i<m; i++){
			do{
				int len=rand()%10+11;
				buf[len]=0;
				for(int k=0; k<len; k++)buf[k]='a'+rand()%26;
				string str=buf;
				s.insert(str);
			}while(s.size()<=(unsigned long)i);
		}
		string *p=name;
		for(set<string>::iterator it=s.begin(); it!=s.end(); it++){
			*p++=*it;
		}
		printf("%d %d\n", n, d);
		int cur=0;
		for(int i=0; i<n; i++){
			int u=rand()%m, v;
			do{
				v=rand()%m;
			}while(u==v);
			cur+=rand()%10;
			if(_T==4)cur=14;
			if(_T==5 && i<=100)cur=0;
			printf("%s %s %d\n", name[u].c_str(), name[v].c_str(), cur);
		}
	}
	return 0;
}
