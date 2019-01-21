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

#define maxn 110000

int n,c[maxn],tot;
char cstr[10];

map<int,int> name2id;
map<int,int> id2name;
map<int,int> bear2id;
map<int,int> id2bear;
map<int,int> poplist;
map<int,int>::iterator it;
map<int,int>::iterator jt;

int lowbit(const int &x){
	return x&(x^(x-1));
}

int sum(int x){
	//cout<<"S: "<<x<<endl;
	int res=0;
	while(x>0){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}

void modify(int x,int d){
	//cout<<"M: "<<x<<" "<<d<<endl;
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
	//cout<<"C.List\n    ";
	//for(int i=0;i<10;i++)printf("%4d",c[i]);cout<<endl;
}

void work(){
	int x,y,res;
	memset(c,0,sizeof(c));tot=0;
	name2id.clear();
	id2name.clear();
	bear2id.clear();
	id2bear.clear();
	poplist.clear();
	for(int i=0;i<n;i++){
		scanf("%s",cstr);
		switch(cstr[0]){
			case 'a':
				tot++;
				scanf("%d%d",&x,&y);
				name2id.insert(pair<int,int>(x,tot));
				id2name.insert(pair<int,int>(tot,x));
				bear2id.insert(pair<int,int>(y,tot));
				id2bear.insert(pair<int,int>(tot,y));
				poplist.insert(pair<int,int>(tot,1));
				modify(tot,1);
				break;
			case 'l':
				it=bear2id.begin();
				if(it!=bear2id.end()){
					x=(*it).second;
					modify(x,-1);
					jt=poplist.find(x);
					poplist.erase(jt);
					bear2id.erase(it);
				}
				break;
			case 'c':
				scanf("%d%d",&x,&y);
				it=name2id.find(x);
				if(it!=name2id.end()){
					x=(*it).second;
					jt=poplist.find(x);
					if(jt!=poplist.end()){
						res=sum(x-1);
						printf("%d\n",res);
						if(res>y){
							modify(x,-1);
							it=poplist.find(x);
							poplist.erase(it);
							y=id2bear[x];
							it=bear2id.find(y);
							bear2id.erase(it);
						}
					}
				}
				break;
			case 'p':
				it=poplist.begin();
				if(it!=poplist.end()){
					x=(*it).first;
					modify(x,-1);
					y=id2bear[x];
					jt=bear2id.find(y);
					bear2id.erase(jt);
					poplist.erase(it);
				}
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)work();
	return 0;
}

