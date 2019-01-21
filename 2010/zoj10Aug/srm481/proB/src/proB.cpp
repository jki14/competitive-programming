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

using namespace std;

class ChickenOracle {
public:
	string theTruth(int, int, int, int);
};

int lied(const int &x,const int &u,const int &v){
	if(x<u || x>v)return 0;
	if(((x-u)&1)==0)return 1;
	return 0;
}

string ChickenOracle::theTruth(int n, int e, int l1, int l2) {
	int c,u,v;
	c=n-e;u=abs(l1-l2);v=l1+l2;
	if(v>n)v=2*n-v;
	int el=lied(e,u,v),cl=lied(c,u,v);
	cout<<"e="<<e<<" c="<<c<<" u="<<u<<" v="<<v<<endl;
	cout<<"el="<<el<<" cl="<<cl<<endl;
	if((el==0) && (cl==0))
		return "The oracle is a lie";
	if(cl==0)
		return "The chicken";
	if(el==0)
		return "The egg";
	return "Ambiguous";
}


double test0() {
	int p0 = 10;
	int p1 = 10;
	int p2 = 0;
	int p3 = 0;
	ChickenOracle * obj = new ChickenOracle();
	clock_t start = clock();
	string my_answer = obj->theTruth(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "The egg";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 762085;
	int p1 = 174382;
	int p2 = 591906;
	int p3 = 731022;
	ChickenOracle * obj = new ChickenOracle();
	clock_t start = clock();
	string my_answer = obj->theTruth(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "The chicken";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 60;
	int p1 = 20;
	int p2 = 5;
	int p3 = 25;
	ChickenOracle * obj = new ChickenOracle();
	clock_t start = clock();
	string my_answer = obj->theTruth(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "The chicken";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 1000;
	int p1 = 500;
	int p2 = 250;
	int p3 = 250;
	ChickenOracle * obj = new ChickenOracle();
	clock_t start = clock();
	string my_answer = obj->theTruth(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "Ambiguous";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
