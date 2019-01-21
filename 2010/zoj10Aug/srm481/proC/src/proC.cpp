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
#include <cstring>
#include <map>

using namespace std;

#define lld long long
#define maxm 100
#define k (*it).second

map<string,int> s;
map<string,int>::iterator it;
vector<int> a[maxm];
vector<int> tmp;
lld g[maxm],t;
int n,m;

class BatchSystem {
public:
	vector <int> schedule(vector <int>, vector <string>);
};

vector <int> BatchSystem::schedule(vector <int> d, vector <string> u) {
	n=d.size();m=0;
	vector<int> res(n);s.clear();
	memset(g,0,sizeof(g));
	int i,j,p;p=0;
	for(i=0;i<n;i++){
		it=s.find(u[i]);
		if(it==s.end()){
			s.insert(pair<string,int>(u[i],m));
			a[m].clear();
			g[m]+=(lld)d[i];
			a[m].push_back(i);
			m++;
		}else{
			g[k]+=(lld)d[i];
			a[k].push_back(i);
		}
	}
	for(i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
			if(g[i]>g[j] ||(g[i]==g[j] && a[i][0]>a[j][0])){
				tmp=a[i];a[i]=a[j];a[j]=tmp;
				t=g[i];g[i]=g[j];g[j]=t;
			}
	for(i=0;i<m;i++)
		for(j=0;j<a[i].size();j++)
			res[p++]=a[i][j];
	return res;
}


double test0() {
	int t0[] = {400, 100, 100, 100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Danny Messer", "Stella Bonasera", "Stella Bonasera", "Mac Taylor"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {3, 1, 2, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1000000000, 1000000000, 1000000000, 1000000000,1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Gil", "Gil", "Gil", "Gil","Sarah"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {0, 1, 2 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {100, 200, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Horatio Caine", "horatio caine", "YEAAAAAAH"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystem * obj = new BatchSystem();
	clock_t start = clock();
	vector <int> my_answer = obj->schedule(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {2, 0, 1 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
