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

#define maxn 20
#define maxlen 1100

int n;
char sa[maxlen],sb[maxlen];
char keya[maxlen],keyb[maxlen];
double x[maxn],p,ans;

double sqr(const double &x){ return x*x; }

void work(){
	int i,j,k;
	double ax,ay,bx,by;
	n=0;ans=0.0;
	/*gets(sa);*/gets(sb);
	for(i=j=0;sa[i];){

		while(sa[i]==' ' || sa[i]=='(')i++;
		for(k=0;sa[i]!=')';i++){
			keya[k++]=sa[i];
		}
		keya[k]=0;i++;
		sscanf(keya,"%lf,%lf",&ax,&ay);

		while(sb[j]==' ' || sb[j]=='(')j++;
		for(k=0;sb[j]!=')';j++){
			keyb[k++]=sb[j];
		}
		keyb[k]=0;j++;
		sscanf(keyb,"%lf,%lf",&bx,&by);

		//printf("ax=%.2f ay=%.2f\n",ax,ay);
		//printf("bx=%.2f by=%.2f\n",bx,by);

		x[n++]=sqrt(sqr(ax-bx)+sqr(ay-by));

		//printf("X=%.2f\n\n",x[n-1]);
	
	}
	gets(sa);sscanf(sa,"%lf",&p);
	for(i=0;i<n;i++){
		ans+=pow(x[i],p);
	}
	ans=pow(ans,1/p);
	printf("%.10f\n",ans);
}

int main(){
	while(gets(sa))work();
	return 0;
}

