#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

multimap<string,int> a;
multimap<string,int>::iterator it;
string s;
int n,num,k;


string ones[10]={ "","I","II","III","IV","V","VI","VII","VIII","IX" };
string tens[10]={ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
string huns[10]={ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
string thos[10]={ "","M","MM","MMM","","","","","","" };

void work(){
	scanf("%d",&n);a.clear();
	while(n--){
		scanf("%d",&num);
		s.clear();
		k=num/1000;s=thos[k];
		k=num/100;k%=10;s=s+huns[k];
		k=num/10;k%=10;s=s+tens[k];
		k=num;k%=10;s=s+ones[k];
		//cout<<"Try Ins "<<num<<" = "<<s<<endl;
		a.insert(pair<string,int>(s,num));
	}
	for(it=a.begin();it!=a.end();it++){
		if(it!=a.begin())printf(" ");
		printf("%d",(*it).second);
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

