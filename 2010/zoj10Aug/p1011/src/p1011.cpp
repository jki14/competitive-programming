#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

const int maxn=310,maxl=4100;
const int eps=1e-6;

int n,m;
map<char,int> s;
int a[maxn][maxn];

char str[maxl];

int _told(const int &x,const int &y){
	int res=s[str[x]];
	res*=16;res+=s[str[y]];
	return res;
}

int getf(){
	int res=_told(1,2)*11+_told(3,4)*16+_told(5,6)*5;
	res/=32;
	return res;
}

void doit(){
	int i,j;
	int sum=0,ave,thr;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			scanf("%s",str);
			a[i][j]=getf();
			sum+=a[i][j];
		}
	//cout<<sum<<endl;
	ave=sum/((int)(n*m));
	thr=(192+2*ave)/3;
	//cout<<thr<<endl;
	//cout<<a[2][25]<<endl;
	//cout<<a[2][26]<<endl;
	//cout<<a[2][27]<<endl;
	//int tmp=(int)thr;thr=(int)tmp;
	printf("%dx%d\n",m,n);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]<thr)
				if(j==m-1)printf("9");else printf("9 ");
				//printf("9");
				//printf("9 ");
			else
				if(j==m-1)printf(" ");else printf("  ");
				//printf(" ");
				//printf("  ");
		}
		printf("\n");
	}
}

int main(){
	s.clear();
	for(int i=0;i<16;i++){
		if(i<10)
			s.insert(pair<char,int>(char((int)'0'+i),(int)i));
		else
			s.insert(pair<char,int>(char((int)'A'+i-10),(int)i));
	}
	while(scanf("%dx%d",&m,&n)!=EOF)doit();
	return 0;
}
