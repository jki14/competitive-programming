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
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define MAXL 110

const int e10[3] = { 1000,100,10 };

const int wei=10000;

class HP{
	public :
		int len,s[MAXL];
		HP(){ (*this)=0; };
		HP(int inte){ (*this)=inte; };
		HP operator = (int inte);
		HP operator + (const HP &b); HP operator += (const HP &b);
		int comp(const HP &b);
		bool operator <(const HP &b); bool operator >(const HP &b);

		void pribit(const int &x){
			if(x!=len-1)
				for(int i=0;i<3 && s[x]<e10[i];i++)printf("0");
			printf("%d",s[x]);
		}

		void print(){
			for(int i=len-1;i>=0;i--)pribit(i);
		}
};

HP HP::operator = (int inte){
	if(inte == 0){
		len=1;
		s[0]=0;
	}else{
		len=0;
		while(inte){
			s[len++]=inte%wei;
			inte/=wei;
		}
	}
	return (*this);
}

HP HP::operator + (const HP &b){
	HP c;
	c.s[0]=0;
	for(int i=0;i<len || i<b.len;i++){
		if(i<len)c.s[i]+=s[i];
		if(i<b.len)c.s[i]+=b.s[i];
		c.s[i+1]=c.s[i]/wei;
		c.s[i]%=wei;
	}
	c.len=max(len,b.len)+1;
	while(c.len > 1 && !c.s[c.len-1])c.len--;
	return c;
}

HP HP::operator += (const HP &b){
	(*this) = (*this) + b;
	return (*this);
}

int HP::comp(const HP &b){
	if(len>b.len)return 1;
	if(len<b.len)return -1;
	int i=len-1;
	while((i>0)&&(s[i]==b.s[i]))--i;
	return s[i]-b.s[i];
}

bool HP::operator < (const HP &b) { return this->comp(b)<0; }
bool HP::operator > (const HP &b) { return this->comp(b)>0; }

const HP ZERO=0;
const HP ONE=1;

//end of Class HP--------------


#define maxnum 110
#define maxchr 110
#define maxlen 110

int n,m,p,c,num;
int route[maxnum][maxchr],fail[maxnum],flag[maxnum];
int que[maxnum];

map<char,int> s;
map<char,int>::iterator it;

void init(char *key,const int &d){
	int p,k;
	for(p=0;*key;key++){
		it=s.find(*key);
		if(it==s.end()){
			k=c++;
			s.insert(pair<char,int>((*key),k));
		}else k=(*it).second;

		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]=d;
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<n;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q && !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];
				}
			}
		}
	}
}

//end of DFA function--------------

#define maxn 110

char str[maxlen];
HP f[maxn][maxnum],ans;

int danger(int x){
	if(!x)return 0;
	if(flag[x])return flag[x];
	flag[x]=danger(fail[x]);
	return flag[x];
}

void work(){	
	int i,j,k,x;
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	s.clear();c=0;
	scanf("%s",str);
	for(i=1;i<=p;i++){
		scanf("%s",str);
		init(str,i);
	}
	build();
	
	for(i=0;i<=m;i++)
		for(j=0;j<=num;j++)f[i][j]=ZERO;
	f[0][0]=ONE;
	
	for(i=0;i<m;i++)
		for(j=0;j<=num;j++)
			for(k=0;k<n;k++){x=j;
				while(x && !route[x][k])x=fail[x];
				x=route[x][k];
				if(danger(x))continue;
				f[i+1][x]+=f[i][j];
				//printf("f[%d][%d]+f[%d][%d]=",i+1,x,i,j);
				//f[i+1][x].print();
				//printf("\n");
			}

	ans=ZERO;
	for(i=0;i<=num;i++)ans+=f[m][i];
	ans.print();printf("\n");
}

int main(){
	while(scanf("%d%d%d",&n,&m,&p)!=EOF)work();
	return 0;
}

