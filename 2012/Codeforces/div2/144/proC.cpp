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

const int hig=1e+5;

#define S 110

int n,c[S],mat[S][S];

map<int, int, greater<int> > s;
map<int, int, greater<int> >::iterator it;

int main(){
	s.clear();for(int i=3;1;i++){
		int now=i*(i-1)*(i-2)/6;
		if(now>hig)break;
		s.insert(pair<int, int>(now,i));
	}
	for(int i=2;i<=100;i++)c[i]=i*(i-1)/2;
	while(scanf("%d",&n)!=EOF){
		it=s.lower_bound(n);
		memset(mat,0,sizeof(mat));
		int m=(*it).second;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)mat[i][j]=1;
		int now=(*it).first;
		while(now<n){
			int p=m;while(now+c[p]>n)p--;
			m++;now+=c[p];
			for(int i=1;i<=p;i++)mat[m][i]=mat[i][m]=1;
		}
		printf("%d\n",m);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				/*if(j!=1)
					printf(" %d",mat[i][j]);
				else*/ printf("%d",mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
