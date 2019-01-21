
//"XOOXOOOOOOXOXXNOXXOOOXXOOOXOXOO", "OXOXXXOOOXXXXOOXXOXOOOOXXXOXNOO", "OOXXOXXXNOXXXXOXXXXOOXOXXXOXXXX", "XXXXOOOOXXXXXXOXXXXXOOOOXOOOXOO", "OXOOXOOOXXOXXOXXXOXOXNXXXXXOXOX", "OXXOOXOXOOXOXXOXOOOOOOXXOXXOOOO", "OOXOOOXOXOOXOOOXNXOOXXOOXXXOOXX", "OOXOOXOXOXOOXOOXXOXOXXOXXOOXXXX", "OONXXOXOXXOOXXXOXXXOXXXOXXXXXXO", "OXOXXOOXXXXOXXXOOOXXOOXXXOXXXOX", "XXXXOXOOOXXXXOXXXOXOXOXOXXXOXOO", "OXXXXOXOOOXXXOXXXXXXXOXOXOXOXXX", "XXXXXXOXXXXXXXXXXOXOXOXXXXXOXXO", "XOXXOXOOXXOOXXXOXOXOOXXXXXXOOOX", "NOOOXOOOXXXXXXXOOXXOXOXOOXXXOOO", "OXXXXXXXOOXXXOOXXXXXOXOXXXXOXOX", "XXXXXONXXOXXXXOXXXOOXXXXXOXXOXX", "XOXXOOXOXOOXOOXXXXXOOXXOXXOOXXX", "OXXXXOOXXXXXXXXXOXXXXXOXOXOXXXX", "OOOXOOOOOXOXOOOXOOXXONXNXOXXOOO", "OOOOXOXXXOXXXOXOXOXOXXOOXOXOOOX", "XOXONOXXXOOOOXOXXXXNXXXOXOOXOOX", "XOOOXXOOXXXXXXXOXXOXOXXXXOOXXOX", "OXXOXXOXOXOOXXOXXOXNOOXXXOXXXOX", "OXXXXOXXXXXXXXOXXXOXXXXXXXXXXOX", "OXXOXXXOXOXOXXXXOXXOOOOOXXOXXXX", "XOOOXXXOXXXXXXXXXOOXXOOXXOXOXOX", "OXXOOOOXXXOOOOXOXOXXOXXXXXOXOOO", "XNXXXOOXXXXXXOOXOXXOOOXXXXXOXOX", "OOXOOOXXXOOXXOOOXXXOOOOOOXOOOXX", "OOXOXOXXOXOXOXOXXXXOXXXXXXXOXXX"

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

#define N 60 
#define s n-1
#define t n-2

const int inf = 220;

int n,c[N][N],C[N][N],f[N];
queue<int> que;int inq[N];

class OldBridges {
public:
	string isPossible(vector <string>, int, int, int, int, int, int);
};

int find(){
	while(!que.empty())que.pop();memset(inq,0,sizeof(inq));
	inq[s]=1;que.push(s);f[s]=s;
	for(;!que.empty();que.pop()){int u=que.front();
		for(int v=0;v<n;v++){
			if(c[u][v]){
				if(!inq[v]){
					f[v]=u;inq[v]=1;que.push(v);
					if(v==t)return 1;
				}
			}
		}
	}
	return 0;
}

int update(){int ret=inf;
	for(int v=t,u;v!=s;v=u){u=f[v];
		ret=min(ret,c[u][v]);
	}
	for(int v=t,u;v!=s;v=u){u=f[v];
		c[u][v]-=ret;c[v][u]+=ret;
	}
	return ret;
}

int flow(){
	int ret=0;
	while(find())ret+=update();
	//printf("flow=%d\n",ret);
	return ret;
}


void fresh(){ for(int i=0;i<n;i++)for(int j=0;j<n;j++)c[i][j]=C[i][j]; }

string OldBridges::isPossible(vector <string> bridges, int a1, int a2, int an, int b1, int b2, int bn) {n=bridges.size();
	for(int u=0;u<n;u++)for(int v=0;v<n;v++)C[u][v]=(bridges[u][v]=='X')?0:((bridges[u][v]=='O')?2:inf);
	n+=2;

	//printf("s=%d t=%d\n",s,t);

	fresh();c[s][a1]=c[a2][t]=an*2;c[s][b1]=c[b2][t]=bn*2;if(flow()<((an+bn)*2))return "No";
	fresh();c[s][a2]=c[a1][t]=an*2;c[s][b1]=c[b2][t]=bn*2;if(flow()<((an+bn)*2))return "No";
	return "Yes";
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
	string t0[] = {"XOOXOOOOOOXOXXNOXXOOOXXOOOXOXOO", "OXOXXXOOOXXXXOOXXOXOOOOXXXOXNOO", "OOXXOXXXNOXXXXOXXXXOOXOXXXOXXXX", "XXXXOOOOXXXXXXOXXXXXOOOOXOOOXOO", "OXOOXOOOXXOXXOXXXOXOXNXXXXXOXOX", "OXXOOXOXOOXOXXOXOOOOOOXXOXXOOOO", "OOXOOOXOXOOXOOOXNXOOXXOOXXXOOXX", "OOXOOXOXOXOOXOOXXOXOXXOXXOOXXXX", "OONXXOXOXXOOXXXOXXXOXXXOXXXXXXO", "OXOXXOOXXXXOXXXOOOXXOOXXXOXXXOX", "XXXXOXOOOXXXXOXXXOXOXOXOXXXOXOO", "OXXXXOXOOOXXXOXXXXXXXOXOXOXOXXX", "XXXXXXOXXXXXXXXXXOXOXOXXXXXOXXO", "XOXXOXOOXXOOXXXOXOXOOXXXXXXOOOX", "NOOOXOOOXXXXXXXOOXXOXOXOOXXXOOO", "OXXXXXXXOOXXXOOXXXXXOXOXXXXOXOX", "XXXXXONXXOXXXXOXXXOOXXXXXOXXOXX", "XOXXOOXOXOOXOOXXXXXOOXXOXXOOXXX", "OXXXXOOXXXXXXXXXOXXXXXOXOXOXXXX", "OOOXOOOOOXOXOOOXOOXXONXNXOXXOOO", "OOOOXOXXXOXXXOXOXOXOXXOOXOXOOOX", "XOXONOXXXOOOOXOXXXXNXXXOXOOXOOX", "XOOOXXOOXXXXXXXOXXOXOXXXXOOXXOX", "OXXOXXOXOXOOXXOXXOXNOOXXXOXXXOX", "OXXXXOXXXXXXXXOXXXOXXXXXXXXXXOX", "OXXOXXXOXOXOXXXXOXXOOOOOXXOXXXX", "XOOOXXXOXXXXXXXXXOOXXOOXXOXOXOX", "OXXOOOOXXXOOOOXOXOXXOXXXXXOXOOO", "XNXXXOOXXXXXXOOXOXXOOOXXXXXOXOX", "OOXOOOXXXOOXXOOOXXXOOOOOOXOOOXX", "OOXOXOXXOXOXOXOXXXXOXXXXXXXOXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	int p2 = 26;
	int p3 = 11;
	int p4 = 28;
	int p5 = 16;
	int p6 = 23;
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
