#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 1100

struct star{
	int x,y;
	star(){}
	star(const int &a,const int &b){
		x=a;y=b;
	}
	bool operator < (const star &a) const{
		if(a.x<x)return true;
		if(a.x>x)return false;
		if(a.y<y)return true;
		return false;
	}
};

int n,res;
map<star,bool> s;
map<star,bool>::iterator it,jt,kt;
star tmp;

void doit(){
	int x,y;
	s.clear();res=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		tmp.x=x;tmp.y=y;
		s.insert(pair<star,int>(tmp,1));
	}
	for(it=s.begin();it!=s.end();it++){
		for(jt=it,jt++;jt!=s.end() && (*jt).first.x==(*it).first.x;jt++){
			tmp.x=(*it).first.x+(*jt).first.y-(*it).first.y;tmp.y=(*it).first.y;
			kt=s.find(tmp);if(kt!=s.end()){
				tmp.y=(*jt).first.y;
				kt=s.find(tmp);if(kt!=s.end())res++;
			}
		}
	}
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
