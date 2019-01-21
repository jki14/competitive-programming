#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

#define maxn 310

int timer;

int n,m;
char str[maxn],*ans;
string f[maxn][maxn],g[maxn][maxn];

string rev(string s)
{
	string ret = "";
	for(int i=s.length()-1; i>=0; --i)
		ret += s[i];
	return ret;
}

void work()
{
	string s;
	scanf("%d%d",&n,&m);
	scanf("%s",str);s=str;
	f[0][0] = "";
	for(int i=1;i<=n;i++){
		f[i][0]=s.substr(0,i);
		g[i][0]=rev(s.substr(0,i));
		for(int j=1;j<=m&&j<=n;++j){
			f[i][j]=f[i-1][j]+s[i-1];
			g[i][j]=s[i-1]+g[i-1][j];
			string tmp;
			tmp=s[i-1]+g[i-1][j-1];
			if(f[i][j]>tmp)
				f[i][j]=tmp;
			tmp=f[i-1][j-1]+s[i-1];
			if(g[i][j]>tmp)
				g[i][j]=tmp;
		}
	}
	printf("Case %d: %s\n",timer,f[n][m].c_str());
}

int main(){
	int t;scanf("%d",&t);
	for(timer=1;timer<=t;timer++)
		work();
	return 0;
}

