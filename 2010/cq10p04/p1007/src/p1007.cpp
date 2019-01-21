#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn=30,maxl=1000;

struct hp { int len,s[maxl]; };

int timer;
int k,n,m;
hp num[maxn],ans,tmp;
char s[maxn][maxl],chr[maxn];

int check(char *s){
	if(s[0]=='+' || s[0]=='*')
		return 1;
	return 0;
}

void Str2Hp(const char *s,hp &x){
	x.len=strlen(s);
	for(int i=1;i<=x.len;i++)x.s[i]=s[x.len-i]-'0';
}

void Multi(const hp a,const hp b,hp &c){
	int i,j; c.len=a.len+b.len;
	for(i=1;i<=c.len;i++)c.s[i]=0;
	for(i=1;i<=a.len;i++)
		for(j=1;j<=b.len;j++)
			c.s[i+j-1]+=a.s[i]*b.s[j];
	for(i=1;i<c.len;i++){
		c.s[i+1]+=c.s[i]/10;c.s[i]%=10;
	}
	while(c.s[i]){ c.s[i+1]=c.s[i]/10;c.s[i]%=10;i++; }
	while(i>1 && !c.s[i]) i--;c.len=i;
}

void Plus(const hp a,const hp b,hp &c){
	int i;c.s[1]=0;
	for(i=1;i<=a.len || i<=b.len;i++){
		if(i<=a.len)c.s[i]+=a.s[i];
		if(i<=b.len)c.s[i]+=b.s[i];
		c.s[i+1]=c.s[i]/10;c.s[i]%=10;
	}
	if(!c.s[i])i--;c.len=i;if(c.len==0)c.len=1;
}

void printHp(hp x){
	for(int i=x.len;i>=1;i--)printf("%d",x.s[i]);
}

void doit(){
	int i;
	for(i=0;i<k;i++)
		scanf("%s",s[i]);
	if((k&1)==0){
		printf("Case %d: Invalid Expression!\n",timer++);
		return;
	}
	n=0;m=0;
	for(i=0;i<k;i++){
		if((i&1)!=check(s[i])){
			printf("Case %d: Invalid Expression!\n",timer++);
					return;
		}
		if(i&1){
			while(true){
				if(m==0 || (chr[m]=='+' && s[i][0]=='*')){
					m++;chr[m]=s[i][0];
					break;
				}
				else{
					if(chr[m]=='+')
						Plus(num[n],num[n-1],tmp);
					else
						Multi(num[n],num[n-1],tmp);
					n--;m--;num[n]=tmp;
				}
			}
		}
		else{
			n++;Str2Hp(s[i],num[n]);
		}
	}
	//cout<<"Now n="<<n<<" m="<<m<<endl;
	while(m){
		if(chr[m]=='+')
			Plus(num[n],num[n-1],tmp);
		else
			Multi(num[n],num[n-1],tmp);
		n--;m--;num[n]=tmp;
	}
	ans=num[1];
	printf("Case %d: ",timer++);
	printHp(ans);
	printf("\n");
}

int main(){
	timer=1;
	while(scanf("%d",&k)!=EOF)doit();
	return 0;
}
