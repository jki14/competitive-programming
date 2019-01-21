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

#define maxn 1100000

int n,m,M,len;
char a[maxn],b[maxn];
int fail[maxn];

void makefail(){
	int i,k,head;head=-1;k=0;M=m;
	while(k<m && b[k]=='*'){ m--;k++; }
	//printf("prev:");puts(b);
	for(i=0;i+k<M;i++)b[i]=b[i+k];b[m]=0;
	//printf("k=%d\n",k);
	//printf("next:");puts(b);
	for(i=1,fail[0]=k=head;i<m;i++){
		if(b[i]=='*'){
			fail[i+1]=k=head=i;i++;
			continue;
		}
		while(k!=head && b[k+1]!='?' && b[i]!=b[k+1])k=fail[k];
		if(b[k+1]=='?' || b[i]==b[k+1])k++;
		fail[i]=k;
	}
}

int missx(int x){
	//printf("missx X=%d\n",x);
	if(m>0 && b[m-1]!='*' && x>=m)return 0;
	for(;x<m;x++){
		//printf("%c",b[x]);
		if(b[x]!='*'){
			//printf("\n");
			return 0;
		}
	}
	//printf("\n");
	return 1;
}

int first(){
	int i,j;
	if(m<M)return 1;
	for(i=j=0;i<m && j<n;i++,j++){
		if(b[j]=='*')return 1;
		if(b[j]!='?' && a[i]!=b[j])return 0;
	}
	return 1;
}

void work(){
	int i,j;
	n=strlen(a);
	m=strlen(b);
	makefail();
	//for(i=0;i<m;i++)printf("%c",b[i]);
	//printf("\n");
	//for(i=0;i<m;i++)printf("fail[%d]=%d\n",i,fail[i]);
	for(i=j=0;i<n && j<m;i++,j++){
		if(b[j]=='*'){
			i--;
			
			//printf("vis * change i to %d j=%d\n",i,j);

			continue;
		}
		if(b[j]!='?' && a[i]!=b[j]){
			
			//printf("Path %c %c ",a[i],b[j]);

			j=fail[j];
			
			//printf("fail change j to %d\n",j);	
		}
	}
	//printf("i=%d j=%d\n",i,j);
	if(first()&&((i==n && j==m)||(missx(j))))
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	while(scanf("%s%s",a,b)!=EOF)
		work();
	return 0;
}

