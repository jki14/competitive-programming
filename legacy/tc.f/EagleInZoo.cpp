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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define N 110

int n,m;
double f[N][N];

vector<int> sus[N];

double c(const int &x,const int &y){
	double ret=1.0;
	for(int i=1;i<=x;i++)
		ret=ret*((double)(y+1-i))/((double)i);
	return ret;
}

void core(const int &u){int kids=sus[u].size();
	for(int i=0;i<kids;i++){
		core(sus[u][i]);
	}
	f[u][1]=1.0;
	for(int i=1;i<m;i++){f[u][i+1]=0.0;
		for(int x=0;x<kids;x++){
			for(int j=1;j<=i;j++)
				f[u][i+1]+=c(j,i)*f[x][j]/pow((double)n,kids);
		}
	}
}

class EagleInZoo{
public:

	double calc(vector <int> _p, int _m) {
		n=_p.size();m=_m;
		for(int i=0;i<n;i++)sus[i].clear();
		
		for(int i=0;i<n;i++)sus[_p[i]].push_back(i+1);
		core(0);
		
		return f[0][m];
	}
	

