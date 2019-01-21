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

#define maxn 110
#define len 110
#define L 7

const double eps=1e-6;

void put(const double &x);
void put(const int &x);

struct Tdate{
	int y,m,d;
	bool operator < (const Tdate &a) const{
		if(y!=a.y)return y<a.y;
		if(m!=a.m)return m<a.m;
		return d<a.d;
	}
	bool operator != (const Tdate &a) const{
		if(y!=a.y)return 1;
		if(m!=a.m)return 1;
		if(d!=a.d)return 1;
		return 0;
	}
};

struct Ttime{
	int h,m;
	double s;
	Ttime(){ }
	Ttime(const int &hh,const int &mm,const double &ss){ h=hh;m=mm;s=ss; }
	bool operator < (const Ttime &a) const{
		if(h!=a.h)return h<a.h;
		if(m!=a.m)return m<a.m;
		return s<a.s;
	}
	bool operator != (const Ttime &a) const{
		if(h!=a.h)return 1;
		if(m!=a.m)return 1;
		if(fabs(s-a.s)>eps)return 1;
		return 0;
	}
};

struct Tdatetime{
	Tdate d;
	Ttime t;
	bool operator < (const Tdatetime &a) const {
		if(d!=a.d)return d<a.d;
		return t<a.t;
	}
	bool operator != (const Tdatetime &a) const {
		if(d!=a.d)return 1;
		if(t!=a.t)return 1;
		return 0;
	}
	void putout(){
		put(d.d);printf("/");
		put(d.m);printf("/");
		put(d.y);printf(" ");
		put(t.h);printf(":");
		put(t.m);printf(":");
		put(t.s);printf(" ");
	}
};

struct req{
	int id,opt;
	Tdatetime dt;
	Ttime cost;
	bool operator <(const req &a) const {
		if(dt!=a.dt)return a.dt<dt;
		if(opt!=a.opt)return a.opt<opt;
		if(cost!=a.cost)return a.cost<cost;
		return a.id<id;
	}
	void putout(const int &key){
		printf("%d ",id);
		dt.putout();
		switch(key){
			case 0:
				printf("LANDED\n");
				break;
			case 1:
				printf("ACCEPTED\n");
				break;
			case 2:
				printf("POSTPONED\n");
		}
	}
};

const Ttime re=Ttime(0,10,0.0);
const int leaprem[L]= { 1,5,9,13,17,22,30 };

int T,n,m;

req state;

priority_queue<req> q;

char cstr[len];

void put(const double &x){
	if(x+eps<10.0)printf("0");
	printf("%.3f",x);
}

void put(const int &x){
	if(x<10)printf("0");
	printf("%d",x);
}

int leap(const int &y){
	int i,rem=y%33;
	for(i=0;i<L;i++)if(rem==leaprem[i])return 1;
	return 0;
}

int mday(const int &y,const int &m){
	if(m<=6)return 31;
	if(m<12)return 30;
	return (leap(y))?30:29;
}

void nextday(Tdatetime &x){
	x.d.d++;
	if(x.d.d>mday(x.d.y,x.d.m)){
		x.d.d=1;
		x.d.m++;
	}
	if(x.d.m>12){
		x.d.m=1;
		x.d.y++;
	}
}

void update(Tdatetime &x,const Ttime &y){
	x.t.s+=y.s;x.t.m+=y.m;x.t.h+=y.h;
	while(x.t.s+eps>60.0){ x.t.s-=60.0;x.t.m++; }
	while(x.t.m>=     60){ x.t.m-=60;x.t.h++; }
	while(x.t.h>=     24){ x.t.h-=24;nextday(x); }
}

void work(){
	int i;
	state.opt=1;
	for(i=0;i<n;i++){
		scanf("%d",&state.id);

		scanf("%s",cstr);sscanf(cstr,"%d/%d/%d",&state.dt.d.d,&state.dt.d.m,&state.dt.d.y);

		scanf("%s",cstr);sscanf(cstr,"%d:%d:%lf",&state.dt.t.h,&state.dt.t.m,&state.dt.t.s);

		scanf("%s",cstr);sscanf(cstr,"%d:%d:%lf",&state.cost.h,&state.cost.m,&state.cost.s);

		q.push(state);
	}
	printf("Report for Test-Case #%d:\n",T);
	while(!q.empty()){state=q.top();q.pop();
		if(!state.opt){
			state.putout(0);
			m++;
		}else{
			if(m){
				state.putout(1);
				m--;state.opt--;
				update(state.dt,state.cost);
				q.push(state);
			}else{
				state.putout(2);
				update(state.dt,re);
				q.push(state);
			}
		}
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}
