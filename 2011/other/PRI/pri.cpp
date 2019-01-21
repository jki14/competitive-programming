#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxnum 1000000

int pri[maxnum],k;

long long sqr(const long long &x){ return x*x; }

int boolPri(const int &x){
	for(int i=0;i<k && sqr((long long)pri[i])<=(long long)x;i++)
		if(x%pri[i]==0)return 0;
	return 1;
}

int main() {
	k=0;for(int i=2;i<50000;i++){
		if(boolPri(i)){ pri[k++]=i;cout<<"pri["<<k<<"]="<<i<<endl; }
	}
	cout<<k<<endl;
	return 0;
}
