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
#include<set>
#include<map>
using namespace std;

int main(){
	for(int i=0;i<=24;i++)
		printf("lowbit(%d)=%d\n",i,i&(-i));
}
