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

typedef long long lld;
typedef double dou;

inline int min(const int &x, const int &y){ return x<y?x:y; }
inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

inline int max(const int &x, const int &y){ return x>y?x:y; }
inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

//TAIL_OF_TEMPLATE_BY_JKI14

#define N 55
#define M 110

int n,k,d[N],c[N],h[N];
int f[N],l[N],r[N],s[N];
int ev[M],next[M],nbs[N],num;
int lis[N],lef,rig;
lld ans,g[N];

void AddEdge(const int &u,const int &v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	ev[++num]=u;next[num]=nbs[v];nbs[v]=num;
	d[u]++;d[v]++;
}

class HatRack {
public:
	long long countWays(vector <int>, vector <int>);
};

void debug(){
	for(int i=0,p=1;i<rig;i++){
		printf(" %d(%d)",lis[i],f[lis[i]]);
		if(i+2==(1<<p)){
			printf("\n");
			p++;
		}
	}
	printf("\n");
}

lld check(const int &root){
	memset(s,0,sizeof(s));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	lef=rig=0;lis[rig++]=root;
	h[root]=1;f[root]=0;s[root]=1;
	for(;lef<rig;lef++){
		int u=lis[lef];
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(s[v])continue;s[v]=1;
			if(r[u])return 0LL;
			if(l[u])r[u]=v;else l[u]=v;
			lis[rig++]=v;
			h[v]=h[u]+1;f[v]=u;c[u]++;
		}
		if(h[u]<k && !r[u])return 0LL;
	}
	debug();printf("-----\n");
	for(int i=rig-1;i>=0;i--){
		int u=lis[i];s[u]+=s[l[u]]+s[r[u]];
		if(s[l[u]]<s[r[u]])swap(l[u],r[u]);
	}
	debug();printf("-----\n");
	lef=rig=0;lis[rig++]=root;int sig=0;
	for(;lef<rig;lef++){int u=lis[lef];
		if(s[l[u]]<s[r[u]])return 0LL;
		if(l[u] && !r[u]){ sig++;if(sig>1)return 0LL; }
		if(l[u])lis[rig++]=l[u];
		if(r[u])lis[rig++]=r[u];
	}
	if(rig!=n)return 0LL;
	for(int i=rig-1;i>(1<<k)-2;i--)if(l[lis[i]])return 0LL;
	for(int i=1    ;i<(1<<k)-1;i++)if(c[lis[i]]>c[lis[i-1]])return 0LL;
	for(int i=rig-1;i>=0;i--){int u=lis[i];
		g[u]=g[l[u]]*g[r[u]];
		if(s[l[u]] && s[l[u]]==s[r[u]])g[u]*=2LL;
	}
	debug();printf("+++++\n");
	
	return g[root];
}

long long HatRack::countWays(vector <int> knob1, vector <int> knob2) {
	n=knob1.size();memset(d,0,sizeof(d));
	memset(nbs,0,sizeof(nbs));num=0;ans=0LL;
	g[0]=1LL;k=1;
	for(int i=0;i<n;i++)AddEdge(knob1[i],knob2[i]);n++;
	for(int tmp=1;tmp+(1<<k)<=n;k++)tmp+=(1<<k);
	for(int i=1;i<=n;i++)if(d[i]!=3)ans+=check(i);
	return ans;
}


double test0() {
	int t0[] = {8, 19, 14, 5, 22, 11, 24, 9, 23, 6, 4, 13, 2, 1, 16, 15, 20, 10, 12, 18, 3, 17, 21};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 7, 8, 8, 19, 19, 14, 14, 5, 5, 22, 22, 11, 11, 24, 24, 9, 9, 23, 6, 6, 4, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {6,6,6,4,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,4,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1,1,2,2,11,11,8,8,3,3,4,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,11,8,12,13,9,10,4,5,7,6,14};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 16LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {1,2,3,4,5,6,7,8,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,5,6,7,8,9,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	HatRack * obj = new HatRack();
	clock_t start = clock();
	long long my_answer = obj->countWays(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	/*time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;*/
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
