#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define maxl 110

string a,s;
char stmp[maxl];
map<string,int> v;
int n;


void work(){
	int i,fir;
	v.clear();a=stmp;a=a+'!';
	n=a.length();s.clear();
	for(i=0;i<n;i++){
		if((a[i]>='a' && a[i]<='z')||(a[i]>='A' && a[i]<='Z')){
			s=s+a[i];fir=0;
		}
		else{
			if(s.size()!=0){
				if(!v[s]){
					//printf("%s\n",s.c_str());
					cout<<s<<endl;
					v[s]=1;
				}
				s.clear();
			}
		}
	}
}

int main(){
	while(scanf("%s",stmp)!=EOF)work();
	//scanf("%s",stmp);work();
	return 0;
}

