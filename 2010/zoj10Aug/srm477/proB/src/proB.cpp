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

class Islands {
public:
	int beachLength(vector <string>);
};

int n,m;

bool get1(int &x,int &y)
{
	y=((x&1)==0)?y:y+1;
	x=x-1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

bool get2(int &x,int &y)
{
	y=y+1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

bool get3(int &x,int &y)
{
	y=((x&1)==0)?y:y+1;
	x=x+1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

bool get4(int &x,int &y)
{
	y=((x&1)==0)?y-1:y;
	x=x+1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

bool get5(int &x,int &y)
{
	y=y-1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

bool get6(int &x,int &y)
{
	y=((x&1)==0)?y-1:y;
	x=x-1;
	if((x<0)||(y<0))return false;
	if((x>=n)||(y>=m))return false;
	return true;
}

int Islands::beachLength(vector <string> a) {
	n=a.size();m=a[0].length();
	int i,j,x,y,ans=0;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(a[i][j]=='#')
			{
				x=i;y=j;if((get1(x,y))&&(a[x][y]=='.'))ans++;
				x=i;y=j;if((get2(x,y))&&(a[x][y]=='.'))ans++;
				x=i;y=j;if((get3(x,y))&&(a[x][y]=='.'))ans++;
				x=i;y=j;if((get4(x,y))&&(a[x][y]=='.'))ans++;
				x=i;y=j;if((get5(x,y))&&(a[x][y]=='.'))ans++;
				x=i;y=j;if((get6(x,y))&&(a[x][y]=='.'))ans++;
			}
	return ans;
}


double test0() {
	string t0[] = {".#...#.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"..#.##",
 ".##.#.",
 "#.#..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 19;
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
	string t0[] = {"#...#.....",
 "##..#...#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 15;
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
	string t0[] = {"....#.",
 ".#....",
 "..#..#",
 "####.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Islands * obj = new Islands();
	clock_t start = clock();
	int my_answer = obj->beachLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
