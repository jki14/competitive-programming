#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 310

int n,len,s,t,v;
char a[maxn],b[maxn];

int type(const char &x){
	if('0'<=x && x<='9')return 1;
	if('A'<=x && x<='Z')return 2;
	if('a'<=x && x<='z')return 3;
	return 0;
}

int getv(){
	for(int i=0;i<len;i++)if(type(a[i]))return i;
	return -1;
}

void nextb(const int &x,const int &k){
	if(x<s){
		s=x;
		b[x]=(k==1)?'1':((k==2)?'A':'a');
		return;
	}
	switch(type(b[x])){
		case 0:
			nextb(x-1,k);
			break;
		case 1:
			b[x]++;
			if(b[x]>'9'){
				b[x]='0';
				nextb(x-1,1);
			}
			break;
		case 2:
			b[x]++;
			if(b[x]>'Z'){
				b[x]='A';
				nextb(x-1,2);
			}
			break;
		case 3:
			b[x]++;
			if(b[x]>'z'){
				b[x]='a';
				nextb(x-1,3);
			}
			break;
	}
}

void doit(){
	int i,v;
	scanf("%s%d",a,&n);
	len=strlen(a);
	while(getv()==-1 && n){
		a[len-1]++;n--;
		printf("%s\n",a);
	}v=getv();
	//cout<<"v="<<v<<endl;
	if(n)for(s=t=100,i=v;i<len;i++,t++)b[t]=a[i];
	while(n--){
		nextb(t-1,0);
		for(i=0;i<v;i++)printf("%c",a[i]);
		//cout<<"!";
		for(i=s;i<t;i++)printf("%c",b[i]);
		printf("\n");
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
