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

#define N 60
#define K 4
#define L 4010

struct TPoint{
	int x,y;	
	bool operator < (const TPoint &a) const{
		return (x!=a.x)?(x<a.x):(y<a.y);
	}
};

const int inf=0x3fffffff;

const int dy[K]={ 1,0,-1,0 };
const int dx[K]={ 0,1,0,-1 };


int dis[N],dir[N],ans;
int que[N],tail;

map<TPoint,int> s;
map<TPoint,int>::iterator it;

TPoint TP(const int &xx,const int &yy){
	TPoint ret;ret.x=xx;ret.y=yy;
	return ret;
}

class AntsMeet {
public:
	int countAnts(vector <int>, vector <int>, string);
};

int AntsMeet::countAnts(vector <int> x, vector <int> y, string direction) {
	int n=x.size();ans=n;s.clear();memset(dis,0,sizeof(dis));tail=0;
	
	for(int i=0;i<n;i++){
		x[i]<<=1;y[i]<<=1;it=s.find(x[i],y[i]);
		if(it==s.end()){
			s.insert(pair<TPoint,int>(TP(x[i],y[i]),i));
		}else{
			dis[i]=1;ans--;que[++tail]=(*it).second;
		}
		dir[i]=(direction[i]=='N')?0:((direction[i]=='E')?1:((direction[i]=='S')?2:3));
	}

	for(;tail;tail--){ dis[que[tail]]=1;ans--;
		it=s.find(TP(x[que[tail]],y[que[tail]]));s.erase(it);
	}

	for(int k=0;k<L && ans>1;k++){tail=0;
		for(int i=0;i<n;i++){
			if(dis[i])continue;
			it=s.find(TP(x[i],y[i]));s.erase(it);
			x[i]+=dx[dir[i]];y[i]+=dy[dir[i]];
			it=s.find(TP(x[i],y[i]));
			if(it!=s.end() && (*it).second<i){ans--;dis[i]=1;
				que[++tail]=(*it).second;
			}else s.insert(pair<TPoint,int>(TP(x[i],y[i]),i));
		}	
		for(;tail;tail--){
			if(dis[que[tail]])continue;
			dis[que[tail]]=1;ans--;
			it=s.find(TP(x[que[tail]],y[que[tail]]));s.erase(it);
		}
	}
	return ans;
}


double test0() {
	int t0[] = {0,10,20,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,10,20,30};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NWNE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {-10,0,0,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,-10,10,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "NEWS";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {-1,-1,-1,0,0,0,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,0,1,-1,0,1,-1,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "ESEWNNEWW";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ;
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 25;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string p2 = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE";
	AntsMeet * obj = new AntsMeet();
	clock_t start = clock();
	int my_answer = obj->countAnts(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 44;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
