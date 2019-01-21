#include<algorithm>
#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
using namespace std;

#define g 200
#define lim 15

int gra[g][g];
int lar[g][g][lim][lim],tot[g][g],n,m,l[g][g],u[g][g],r[g][g];

int max(int i,int j){
	return (i>j)?i:j;
}

int main(){
	int t,timer=0;
	scanf("%d",&t);
	do{
		if (timer) printf("\n");
		printf("Case %d:\n",++timer);
		t--;
		memset(gra,0,sizeof(gra));
		memset(lar,0,sizeof(lar));
		memset(tot,0,sizeof(tot));
		memset(l,0,sizeof(l));
		memset(u,0,sizeof(u));
		memset(r,0,sizeof(r));
		int i,j,x,y,q,s,x1,y1,x2,y2,res=0;
		scanf("%d%d%d%d",&n,&m,&q,&s);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				scanf("%d",&gra[i][j]);
				lar[i][j][0][0]=gra[i][j];
				tot[i][j]=gra[i][j]+tot[i][j-1];
				if(gra[i][j]!=-1){
					l[i][j]=1;
					r[i][j]=1;
				    if(gra[i][j-1]!=-1)
						l[i][j]+=l[i][j-1];
				}
			}
		for(x=1;(1<<x)<=n;x++)
			for(i=1;i<=n-(1<<x)+1;i++)
				for(j=1;j<=m;j++)
					lar[i][j][x][0]=max(lar[i][j][x-1][0],lar[i+(1<<(x-1))][j][x-1][0]);
		for(y=1;(1<<y)<=m;y++)
			for(x=0;(1<<x)<=n;x++)
				for(i=1;i<=n-(1<<x)+1;i++)
					for(j=1;j<=m-(1<<y)+1;j++)
						lar[i][j][x][y]=max(lar[i][j][x][y-1],lar[i][j+(1<<(y-1))][x][y-1]);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
			  tot[i][j]+=tot[i-1][j];
			for(j=m;j>=1;j--)
				if((gra[i][j]!=-1)&&(gra[i][j+1]!=-1))
					r[i][j]+=r[i][j+1];
		}
		for(i=1;i<=m;i++)
			if(gra[1][i]!=-1)
				u[1][i]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++){
				if((gra[i][j]!=-1)&&(gra[i-1][j]!=-1))
					if(i!=1){
						if(r[i-1][j]<r[i][j])
							r[i][j]=r[i-1][j];
						if(l[i-1][j]<l[i][j])
							l[i][j]=l[i-1][j];
					}
				if(gra[i][j]!=-1)
					u[i][j]=u[i-1][j]+1;
			}
		do{
			q--;res=0;
			int z,z2,u3,d3,l3,r3,alf,bet,z1;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(i=x1;i<=x2;i++){
				for(j=y1;j<=y2;j++)
					if(gra[i][j]!=-1){
						u3=i-u[i][j]+1;d3=i;l3=j-l[i][j]+1;r3=j+r[i][j]-1;
						if(u3<x1)
							u3=x1;
						if(l3<y1)
							l3=y1;
						if(r3>y2)
							r3=y2;
						alf=0;bet=0;
						while((1<<(1+alf))<=d3-u3+1)
							alf++;
						while((1<<(1+bet))<=r3-l3+1)
							bet++;
						z1=max(lar[u3][l3][alf][bet],lar[u3][r3-(1<<bet)+1][alf][bet]);
						z2=max(lar[d3-(1<<alf)+1][l3][alf][bet],lar[d3-(1<<alf)+1][r3-(1<<bet)+1][alf][bet]);
						z=max(z1,z2)*(s-1);
						z+=tot[d3][r3]+tot[u3-1][l3-1];
						z-=tot[d3][l3-1]+tot[u3-1][r3];
						if(z>res)
							res=z;
					}
			}
		printf("%d\n",res);
		}while(q!=0);
	}while(t!=0);
	return 0;
}
