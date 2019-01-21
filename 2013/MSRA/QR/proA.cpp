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

//HEAD_OF_TEMPLATE_BY_JKI14

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpr(x,y) make_pair(x,y)

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 1100

int n,m,r,num,f[N],a[N];
string b[N];
char _u[N],_v[N],c[N],s[N];
map<string, int> mp;
map<string, int>::iterator it;

int getid(const string &s){

	//printf("getid(%s)\n",s.c_str());

	it=mp.find(s);
	if(it!=mp.end()){
		return (*it).second;
	}else{
	  	mp.insert(_mkpr(s,++num));
		f[num]=num;b[num]=s;
		return num;
	}
}
	
int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){printf("Case #%d: ",_T);
		scanf("%d%d",&n,&m);mp.clear();num=r=0;
		for(int i=0;i<m;i++){
			scanf("%s%s",_u,_v);
			string su=_u,sv=_v;
			int u=getid(su),v=getid(sv);
			f[u]=v;
		}
		gets(s);gets(s);
		for(int i=0,j=0;;i++){
			if(!s[i] || s[i]==' '){
				c[j++]=0;j=0;
				string sc=c;
				a[r++]=getid(sc);

				//printf("a[%d]=%d\n",r-1,a[r-1]);

				if(!s[i])
					break;
				else continue;
			}
			c[j++]=s[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<r;j++){
				a[j]=f[a[j]];
			}
		}
		for(int j=0;j<r;j++){
			if(j)printf(" ");
			printf("%s",b[a[j]].c_str());
		}
		printf("\n");
	}
	return 0;
}

