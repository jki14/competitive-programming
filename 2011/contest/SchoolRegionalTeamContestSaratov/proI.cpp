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

#define N 310000

const int m = 10;

const int g[m][m]={ { 6,2,4,4,3,4,5,3,6,5 },
		    { 2,2,1,2,2,1,1,2,2,2 },
		    { 4,1,5,4,2,3,4,2,5,4 },
		    { 4,2,4,5,3,4,4,3,5,5 },
		    { 3,2,2,3,4,3,3,2,4,4 },
		    { 4,1,3,4,3,5,5,2,5,5 },
		    { 5,1,4,4,3,5,6,2,6,5 },
		    { 3,2,2,3,2,2,2,3,3,3 },
		    { 6,2,5,5,4,5,6,3,7,6 },
		    { 5,2,4,5,4,5,5,3,6,6 } };

void check(){
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]!=g[j][i])printf("waring! g[%d][%d]!=g[%d][%d]\n",i,j,j,i);
}

char s[N];

int a[N],n;

int pnt(const int &x){ return (x+(n>>1))%n; }

void work(){
	/* INIT */
	n=strlen(s);
	for(int i=0;i<n;i++){ a[i]=s[i]-'0'; }
	
	/* CORE */
	for(int i=n-1;i>=0;i--){int p=pnt(i);
		int x=a[i],y=a[p];
		//printf("x=%d y=%d\n",x,y);
		for(int k=x+1;k<m;k++){
			if(g[k][y]>g[x][y]){
				int det=g[k][y]-g[x][y];a[i]=k;

				if(p>i){
					for(int k=0;k<m;k++){
						if(g[k][a[i]]>g[a[p]][a[i]]){
							det+=g[k][a[i]]-g[a[p]][a[i]];
							a[p]=k;
						}
					}
				}

				for(int j=i+1;det && j<n;j++){int p=pnt(j);
					int x=a[j],y=a[p];

					
					//printf("x2=%d y2=%d\n",x,y);
					for(int k=0;k<x;k++){
						//printf("k=%d det=%d g[k][y]=%d g[x][y]=%d\n",k,det,g[k][y],g[x][y]);
						if(det>g[x][y]-g[k][y]){
							det-=g[x][y]-g[k][y];a[j]=k;
							
							if(p>j){
								for(int k=0;k<m;k++){
									if(g[k][a[j]]>g[a[p]][a[j]]){
										det+=g[k][a[j]]-g[a[p]][a[j]];
										a[p]=k;
									}
								}
							}else if(p>i){
								for(int k=0;k<a[p];k++){
									if(det>g[a[p]][a[j]]-g[k][a[j]]){
										det-=g[a[p]][a[j]]-g[k][a[j]];a[p]=k;
										break;
									}
								}
							}

							break;
						}
					}
				}
				
				/* Print Out */
				for(int j=0;j<n;j++)printf("%d",a[j]);
				printf("\n");

				return;
			}
		}
	}
	
	/* No Result */
	printf("-1\n");
}

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	check();
	while(scanf("%s",s)!=EOF)
	/*scanf("%s",s);*/work();
	fclose(stdin);fclose(stdout);
	return 0;
}

