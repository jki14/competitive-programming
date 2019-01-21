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

#define lld long long
#define maxn 510000
#define p que[l]
#define q rem[k][i]

const int inf=1000000000;

class BunnyConverter {
public:
	int getMinimum(int, int, int, int);
};

int mk[maxn],que[maxn],l,r;
vector<int> rem[maxn];

int BunnyConverter::getMinimum(int n, int z, int start, int goal) {
	int i,k,zzz,res;lld tmp;
	for(i=0;i<=n;i++)rem[i].clear();
	for(i=1;i<=n;i++){
		tmp=(lld)i*(lld)i;tmp%=(lld)n;if(tmp<0LL)tmp+=(lld)n;
		rem[(int)tmp].push_back(i);
	}
	tmp=(lld)z*(lld)z*(lld)z;tmp%=(lld)n;if(tmp<0LL)tmp+=(lld)n;zzz=(int)tmp;
	memset(mk,0x7f,sizeof(mk));mk[start]=0;l=r=0;que[r++]=start;
	for(;l<r;l++){
		k=zzz+p;k%=n;if(k<0)k+=n;k=n-k;k%=n;if(k<0)k+=n;
		for(i=0;i<(int)rem[k].size();i++){
			if(mk[q]<inf)continue;
			mk[q]=mk[p]+1;que[r++]=q;
			if(mk[goal]<inf)break;
		}
		if(mk[goal]<inf)break;
	}
	res=(mk[goal]<inf)?mk[goal]:-1;
	return res;
}


double test0() {
	int p0 = 5;
	int p1 = 1;
	int p2 = 5;
	int p3 = 3;
	BunnyConverter * obj = new BunnyConverter();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 5;
	int p1 = 1;
	int p2 = 5;
	int p3 = 1;
	BunnyConverter * obj = new BunnyConverter();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 6;
	int p1 = 2;
	int p2 = 3;
	int p3 = 4;
	BunnyConverter * obj = new BunnyConverter();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 7;
	int p1 = 7;
	int p2 = 7;
	int p3 = 7;
	BunnyConverter * obj = new BunnyConverter();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 499979;
	int p1 = 499979;
	int p2 = 499976;
	int p3 = 3;
	BunnyConverter * obj = new BunnyConverter();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 249988;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
