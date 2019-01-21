#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct arr{
	int key[L],hig;
	arr(const int &k){
		memset(key,0,sizeof(key));
		hig=k;key[k]=1;key[0]=-1;
	}
	void clear(){
		memset(key,0,sizeof(key));hig=0;
	}
	void update(){
		while(hig && !key[hig])hig--;
		return hig;
	}
} ans[L],tmp;

void div(arr &x,const arr &y){
	tmp.clear();for(;x.hig;x.update()){
		int d=x.high-y.high;
		for(int i=y.high;i>=0;i--)
			x.key[i+d]-=y.key[i];
	}x=tmp;
}

int main(){
	
}

