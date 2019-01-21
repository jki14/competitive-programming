#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110

int T;
int n;
int c[maxn][maxn],w[maxn][maxn];
double wp[maxn],owp[maxn],oowp[maxn];
double op[maxn];
double res[maxn];
char str[maxn];

void work(){
	int i,j;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	memset(w,0,sizeof(w));
	memset(wp,0,sizeof(wp));
	memset(owp,0,sizeof(owp));
	memset(oowp,0,sizeof(oowp));
	memset(op,0,sizeof(op));
	for(i=0;i<n;i++){
		scanf("%s",str);
		for(j=0;j<n;j++){
			if(str[j]=='.')continue;
			c[i][j]=1;
			if(str[j]=='1'){
				w[i][j]=1;
				wp[i]+=1.0;
			}
			op[i]+=1.0;
		}
	}
	//for(i=0;i<n;i++)wp[i]/=op[i];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!c[i][j])continue;
			if(w[j][i])
				owp[i]+=(wp[j]-1.0)/(op[j]-1.0);
			else
				owp[i]+=wp[j]/(op[j]-1.0);
		}
		owp[i]/=op[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(!c[i][j])continue;
			oowp[i]+=owp[j];
		}
		oowp[i]/=op[i];
	}
	for(i=0;i<n;i++){
		wp[i]/=op[i];
		res[i]=0.25*wp[i]+0.5*owp[i]+0.25*oowp[i];
		//cout<<"Team "<<i<<" : "<<wp[i]<<" "<<owp[i]<<" "<<oowp[i]<<endl;
		//printf("Team %d : wp:%lf  owp:%lf  oowp:%lf\n",i,wp[i],owp[i],oowp[i]);
	}
	printf("Case #%d:\n",T);
	for(i=0;i<n;i++)printf("%.12lf\n",res[i]);
}

int main(){
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

