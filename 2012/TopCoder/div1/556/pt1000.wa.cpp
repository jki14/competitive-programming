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

#define N 110
#define M 110

const int inf = 0x3fffffff;

int n,a1,a2,an,b1,b2,bn,cost;
int c[N][N],f[N][N],eu[M],ev[M],ef[M],ew[M],be[M],next[M],nbs[N],num;
int inq[N],cnt[N],val[N],pat[N];

class OldBridges {
public:
	string isPossible(vector <string>, int, int, int, int, int, int);
};

void AddEdge(const int &u,const int &v,const int &c,const int &w){
	next[++num]=nbs[u];eu[num]=u;ev[num]=v;ef[num]=c;ew[num]= w;be[num]=num+1;nbs[u]=num;
	next[++num]=nbs[v];eu[num]=v;ev[num]=u;ef[num]=0;ew[num]=-w;be[num]=num-1;nbs[v]=num;
}

int findCir(){
	queue<int> que;for(int i=0;i<n;i++){ que.push(i);inq[i]=1;cnt[i]=0;val[i]=0; }
	for(;!que.empty();que.pop()){int u=que.front();cnt[u]++;
	
		//printf("cnt[%d]=%d\n",u,cnt[u]);
	
		for(int i=nbs[u];i;i=next[i]){
			//printf("	Bridge==%d\n",i);
			int v=ev[i];
			if(ef[i]>0 && val[v]>val[u]+ew[i]){

				//printf("	v=%d que.size=%d\n",v,que.size());

				val[v]=val[u]+ew[i];pat[v]=-i;
				if(!inq[v]){ inq[v]=1;que.push(v); }
			}
		}
		for(int v=0;v<n;v++){

			//printf("v==%d\n",v);
			if(c[u][v] && val[v]>val[u]){

				//printf("	val[%d]=%d val[%d]=%d que.size=%d\n",u,val[u],v,val[v],que.size());

				val[v]=val[u];pat[v]=u;
				if(!inq[v]){ inq[v]=1;que.push(v); }

				//printf("	OVER\n");
			}
		}

		//printf("u==%d cnt[u]==%d n==%d inq[u]=%d\n",u,cnt[u],n,inq[u]);

		if(cnt[u]>n){
			
			//printf("Find!\n");
		
			int p;for(int i=0;i<n;i++)cnt[i]=0;
			for(int i=u;;i=pat[i]){
				if(i<0)i=eu[-i];
				cnt[i]++;if(cnt[i]==2){ p=i;break; }
			}
			
			//printf("Cir head=%d :\n",p);
			printf("Flow Cir: p==%d\n",p);	
			for(int i=p;;){

				//printf("i=%d\n",i);
				//printf(" %d",i);

				if(pat[i]<0){

					printf("shoot %d+>%d\n",eu[-pat[i]],ev[-pat[i]]);

					ef[-pat[i]]--;ef[be[-pat[i]]]++;cost+=ew[-pat[i]];
					i=eu[-pat[i]];
				}else{
					//printf("pat[i]=%d\n",pat[i]);

					printf("shoot %d->%d\n",pat[i],i);

					c[i][pat[i]]--;c[pat[i]][i]--;
					i=pat[i];
				}	
				if(i==p)break;
			}
			printf("DONE\n");
			//printf("\n");
			return 1;
		}
		inq[u]=0;
	}
	return 0;
}

void BestFlow(){ cost=0;while(findCir()); }

string OldBridges::isPossible(vector <string> bridges, int _a1, int _a2, int _an, int _b1, int _b2, int _bn) {
	a1=_a1;a2=_a2;an=_an;b1=_b1;b2=_b2;bn=_bn;n=bridges.size();
	memset(c,0,sizeof(c));memset(f,0,sizeof(f));memset(nbs,0,sizeof(nbs));num=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			c[i][j]=c[j][i]=(bridges[i][j]=='X')?0:((bridges[i][j]=='N')?inf:1);
	AddEdge(a2,a1,an,-1);AddEdge(b2,b1,bn,-1);
	BestFlow();printf("cost=%d\n",cost);
	if(cost==-an-bn)
		return "Yes";
	else return "No";
}


double test0() {
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"XOXX","OXOX","XOXO","XXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "No";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"XOXO","OXOX","XOXO","OXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 1;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"XNXO","NXOX","XOXO","OXOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 1;
	int p4 = 1;
	int p5 = 3;
	int p6 = 2;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "No";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"XOXOO","OXOXO","XOXOO","OXOXO","OOOOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	int p3 = 2;
	int p4 = 1;
	int p5 = 3;
	int p6 = 2;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "Yes";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"XOXOOX","OXXXNO","XXXOOX","OXOXOO","ONOOXO","XOXOOX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	int p3 = 3;
	int p4 = 5;
	int p5 = 3;
	int p6 = 3;
	OldBridges * obj = new OldBridges();
	clock_t start = clock();
	string my_answer = obj->isPossible(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p7 = "No";	
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p7 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p7 != my_answer) {
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
	
	time = test1();
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
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
