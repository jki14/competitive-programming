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

class SubAnagrams {
public:
	int maximumParts(vector <string>);
};

const int intA=(int)'A';
const int maxk=30,maxn=1000;
int f[maxn][maxn],a[maxn][maxk];

bool enough(int s1,int t1,int s2,int t2)
{
	int tmp1,tmp2;
	for(int i=0;i<maxk;i++)
	{
		if(s1)tmp1=a[t1][i]-a[s1-1][i];else tmp1=a[t1][i];
		tmp2=a[t2][i]-a[s2-1][i];
		if(tmp1>tmp2)return false;
	}
	return true;
}

int SubAnagrams::maximumParts(vector <string> ss) {
	string s="";
	int n,ans=1;
	int i,j,t=2;
	bool ctn=true;
	for(i=0;i<ss.size();i++)
		s=s+ss[i];
	n=s.length();
	memset(f,-1,sizeof(f));
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		if(i)
			for(j=0;j<maxk;j++)
				a[i][j]=a[i-1][j];
		a[i][(int)s[i]-intA]++;
		f[i][1]=0;
	}
	while((ctn)&&(t<=n))
	{
		ctn=false;
		for(i=0;i<n;i++)
			for(j=i-1;j>=0;j--)
				if((f[j][t-1]>=0)&&(enough(f[j][t-1],j,j+1,i)))
				{
					f[i][t]=j+1;
					ans=t;
					ctn=true;
					break;
				}
		t++;
	}
	return ans;
}


double test0() {
	string t0[] = {"NNNPGNGPPNNGPNNNNNPGPPGPPNNNNNNNNPNGNNGNPNPGGGPNNN","NPPGNNNPNNNNGPNNPNNNNGNNGNNNNNPNGNNGNNPNGGNGPNNPNG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
	string t0[] = {"AAXAAAABX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
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
double test2() {
	string t0[] = {"ABCDEFGHIJKL"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"ABBAB","B","BBX","Z"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SubAnagrams * obj = new SubAnagrams();
	clock_t start = clock();
	int my_answer = obj->maximumParts(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
