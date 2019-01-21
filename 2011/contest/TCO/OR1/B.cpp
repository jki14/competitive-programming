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
using namespace std;

#define maxn 110

int n;
double p[maxn],q[maxn];
double f[maxn][maxn][2];

class MuddyRoad {
public:
	double getExpectedValue(vector <int>);
};

double MuddyRoad::getExpectedValue(vector <int> a) {n=a.size();
	int i,j;
	double res=0.0;
	for(i=0;i<n;i++){ p[i]=((double)a[i])/100.0;q[i]=1.0-p[i]; }
	memset(f,0,sizeof(f));f[0][0][0]=1.0;
	for(i=1;i<n;i++)
		for(j=0;j<=i+1;j++){
			f[i][j][0]=f[i-1][j][0]*q+f[i-1][j][1]*p;
			if(i>1)f[i][j][0]+=f[i-2][j-1]*p;
			f[i][j][1]=f[i-1][j][0]*p;
		}
	for(i=1;i<=n;i++){
		res+=(f[n-1][i][0]+f[n-1][i][1])*((double)i);
	}
	return res;
}


double test0() {
	int t0[] = {0, 60, 60, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MuddyRoad * obj = new MuddyRoad();
	clock_t start = clock();
	double my_answer = obj->getExpectedValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.36;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0, 50, 50, 50, 50, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MuddyRoad * obj = new MuddyRoad();
	clock_t start = clock();
	double my_answer = obj->getExpectedValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.5625;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MuddyRoad * obj = new MuddyRoad();
	clock_t start = clock();
	double my_answer = obj->getExpectedValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 3.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MuddyRoad * obj = new MuddyRoad();
	clock_t start = clock();
	double my_answer = obj->getExpectedValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 1.7352539420031923;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MuddyRoad * obj = new MuddyRoad();
	clock_t start = clock();
	double my_answer = obj->getExpectedValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.288125;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
