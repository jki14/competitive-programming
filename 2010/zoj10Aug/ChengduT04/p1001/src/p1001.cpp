#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define N 110
#define M 15
#define Q 1000

#define xx vecx[x]
#define yy vecy[y]

#define ll l+xx
#define rr r+yy

map<char,int> s;

const int vecx[3]={ -1,0,1 };
const int vecy[3]={ -1,0,1 };

const int inf = 10000;

int f[N][M][M],n,res;
int sl[Q],sr[Q];
char a[N];

int min(int x,int y){ return (x<y)?x:y; }

void work(){
	n=strlen(a);
	memset(f,0x3f,sizeof(f));
	int i,l,r,x,y,h,t;
	f[0][5][6]=0;
	for(i=0;i<=n;i++){
		h=t=0;
		for(l=1;l<10;l++)
			for(r=1;r<=10;r++)
				if(f[i][l][r]<inf){sl[t]=l;sr[t++]=r;}
		for(;h<t;h++){
				l=sl[h];r=sr[h];
				for(x=0;x<3;x++)
					for(y=0;y<3;y++){
						if(ll<1 || ll>10 || rr<1 || rr>10)continue;
						if(ll>=rr)continue;
						if(f[i][ll][rr]>f[i][l][r]+1){
							f[i][ll][rr]=f[i][l][r]+1;
							sl[t]=ll;sr[t++]=rr;
						}
						if((i<n)&&((!xx && s[a[i]]==ll)||(!yy && s[a[i]]==rr))){
							//cout<<"Try Updata "<<i+1<<" "<<l+xx<<" "<<r+yy<<endl;
							f[i+1][ll][rr]=min(f[i+1][ll][rr],f[i][l][r]+1);
							//if(f[i+1][l][r]<inf)cout<<" f["<<i+1<<"]["<<l<<"]["<<r<<"]="<<f[i][l][r]<<endl;
						}
					}
		}
	}
	res=INT_MAX;
	for(l=1;l<10;l++)
		for(r=l+1;r<=10;r++)
			res=min(res,f[n][l][r]);
	printf("%d\n",res);
}

void init(){
	s.clear();
	s['0']=10;
	s['1']=1;
	s['2']=2;
	s['3']=3;
	s['4']=4;
	s['5']=5;
	s['6']=6;
	s['7']=7;
	s['8']=8;
	s['9']=9;
}

int main(){
	init();
	while(scanf("%s",a)!=EOF)work();
	return 0;
}
