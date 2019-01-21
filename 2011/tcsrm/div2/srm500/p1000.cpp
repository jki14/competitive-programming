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

#define maxsize 100000

class GeometricProgressions {
public:
	int count(int, int, int, int, int, int);
};

int pri[maxsize],k;
map<int,int> f,num1,num2;
map<int,int>::iterator it;

int sqr(const int &x){ return x*x; }

int boolPri(const int &x){
	if(x<2)return 0;
	for(int i=0;i<k && sqr(pri[i])<=x;i++)
		if(x%pri[i]==0)return 0;
	return 1;
}

int checkf(){
	for(it=f.begin();it!=f.end();it++)
		if((*it).second!=0)return ((*it).second>0)?1:-1;
	return 0;
}
//{1, 0, 1, 2, 0, 1}
int GeometricProgressions::count(int b1, int q1, int n1, int b2, int q2, int n2) {
	int maxnum=b1;
	maxnum=(maxnum>q1)?maxnum:q1;
	maxnum=(maxnum>b2)?maxnum:b2;
	maxnum=(maxnum>q2)?maxnum:q2;
	int i,j,res;
	k=0;for(i=2;i*i<=maxnum;i++){
		if(boolPri(i))pri[k++]=i;
	}
	if(b1==0){ if(b2==0)return 1;else return (q2==0)?2:(q2==1)?2:n2+1; }
	if(b2==0){ if(b1==0)return 1;else return (q1==0)?2:(q1==1)?2:n1+1; }
	if(boolPri(b1))pri[k++]=b1;
	if(boolPri(b2))pri[k++]=b2;
	if(boolPri(q1))pri[k++]=q1;
	if(boolPri(q2))pri[k++]=q2;
	//cout<<"GetPri[] Success! maxnum="<<maxnum<<endl;
	f.clear();num1.clear();num2.clear();res=n1+n2;
	if(q1==1){	res-=n1-1;n1=1; }
	if(q1==0){	res-=n1-((n1>1)?2:1);n1=1; }
	if(q2==1){	res-=n2-1;n2=1; }
	if(q2==0){	res-=n2-((n2>1)?2:1);n2=1; }
	if(q1==0 && q2==0){	res-=(n1==0 && n2==0)?0:1;n1=n2=1; }
	for(i=0;b1>1;i++){
		//cout<<"Try pri["<<i<<"]="<<pri[i]<<endl;
		if(b1%pri[i]==0)f[i]=0;
		while(b1%pri[i]==0){ f[i]++;b1/=pri[i]; }
		if(boolPri(b1))pri[k++]=b1;
		//cout<<"		b1="<<b1<<endl;
	}
	//cout<<"init b1 Success!"<<endl;
	for(i=0;b2>1;i++){
		if(b2%pri[i]==0 && f.find(i)==f.end())f[i]=0;
		while(b2%pri[i]==0){ f[i]--;b2/=pri[i]; }
		if(boolPri(b2))pri[k++]=b2;
	}
	//cout<<"init b2 Success!"<<endl;
	for(i=0;q1>1;i++){
		if(q1%pri[i]==0)num1[i]=0;else continue;
		if(f.find(i)==f.end())f[i]=0;
		while(q1%pri[i]==0){ num1[i]++;q1/=pri[i]; }
		if(boolPri(q1))pri[k++]=q1;
	}
	//cout<<"init q1 Success!"<<endl;
	for(i=0;q2>1;i++){
		if(q2%pri[i]==0)num2[i]=0;else continue;
		if(f.find(i)==f.end())f[i]=0;
		while(q2%pri[i]==0){ num2[i]++;q2/=pri[i]; }
		if(boolPri(q2))pri[k++]=q2;
	}
	//cout<<"Stand by ready!"<<endl;
	for(i=j=0;i<n1 && j<n2;){
		switch(checkf()){
			case 0:
				res--;i++;
				for(it=num1.begin();it!=num1.end();it++)
					f[(*it).first]+=(*it).second;
				break;
			case 1:
				j++;
				for(it=num2.begin();it!=num2.end();it++)
					f[(*it).first]-=(*it).second;
				break;
			case -1:
				i++;
				for(it=num1.begin();it!=num1.end();it++)
					f[(*it).first]+=(*it).second;
				break;
		}
	}
	return res;
}


double test0() {
	int p0 = 15724;
	int p1 = 19169;
	int p2 = 26501;
	int p3 = 6334;
	int p4 = 18467;
	int p5 = 42;
	GeometricProgressions * obj = new GeometricProgressions();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 26543;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 8;
	int p1 = 1;
	int p2 = 7377;
	int p3 = 6;
	int p4 = 0;
	int p5 = 18757;
	GeometricProgressions * obj = new GeometricProgressions();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 499999999;
	int p1 = 0;
	int p2 = 100500;
	int p3 = 500000000;
	int p4 = 0;
	int p5 = 100500;
	GeometricProgressions * obj = new GeometricProgressions();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 3;
	int p1 = 4;
	int p2 = 100500;
	int p3 = 48;
	int p4 = 1024;
	int p5 = 1000;
	GeometricProgressions * obj = new GeometricProgressions();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 100500;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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

