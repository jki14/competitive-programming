#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

map<string,int>mk;
map<string,int>::iterator it;
char ints[11];
int res,p;
string a,s;
int k,c,n;

const int inf=3000;

class KindAndCruel {
public:
	int crossTheField(string, int, int);
};
int allow(int x,const int &y){
	x--;
	if(a[x]=='C' && y%c!=0)return 0;
	if(a[x]=='K' && y%k==0)return 0;
	return 1;
}

int dfs(string t,int r){
	//cout<<"T:"<<t<<"  <r>"<<r<<endl;
	it=mk.find(t);
	if(it!=mk.end() && (*it).second>=r-1)return inf;
	if(r>res)return inf;
	mk[t]=r;
	int tmp1,tmp2,p,tmpr=inf;
	sscanf(t.c_str(),"%d%d%d",&tmp1,&tmp2,&p);
	if(p==n)return r;
	r++;
	//Move Right
	if(allow(p+1,r)){
		s.clear();
		sprintf(ints,"%10d",r%k);s=ints;
		sprintf(ints,"%10d",r%c);s=s+ints;
		sprintf(ints,"%3d",p+1);s=s+ints;
		tmpr=min(tmpr,dfs(s,r));
	}
	//Stay
	if(allow(p,r)){
		s.clear();
		sprintf(ints,"%10d",r%k);s=ints;
		sprintf(ints,"%10d",r%c);s=s+ints;
		sprintf(ints,"%3d",p);s=s+ints;
		tmpr=min(tmpr,dfs(s,r));
	}
	//MoveLeft
	if(allow(p-1,r)){
		s.clear();
		sprintf(ints,"%10d",r%k);s=ints;
		sprintf(ints,"%10d",r%c);s=s+ints;
		sprintf(ints,"%3d",p-1);s=s+ints;
		tmpr=min(tmpr,dfs(s,r));
	}
	res=min(res,tmpr);
	return tmpr;
}

int KindAndCruel::crossTheField(string A, int K, int C) {a=A;k=K;c=C;n=a.size();
	res=inf;
	mk.clear();
	string t;
	sprintf(ints,"%10d",1%k);t=ints;
	sprintf(ints,"%10d",1%c);t=t+ints;
	sprintf(ints,"%3d",1);t=t+ints;
	//mk.insert(pair<string,int>(t,1));
	dfs(t,0);
	//cout<<"res="<<res<<endl;
	if(res>=inf)res=-1;
	return res;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
