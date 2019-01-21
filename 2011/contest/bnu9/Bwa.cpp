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

#define maxn 20
#define maxk 10000
#define maxl 100

int n,mk[maxn],vis[maxn],dis[maxn];
map<int,int> rank;
map<int,int>::iterator it;
char a[maxn][maxl],b[maxn][maxl];
char s[maxl],tmp[maxl];

void work(){
	scanf("%s",tmp);
	printf("%s\n",tmp);
	scanf("%d",&n);
	int i,j,k;k=0;
	for(i=0;i<n;i++)
		scanf("%s%s",a[i],b[i]);
	scanf("%s",s);
	memset(mk,0,sizeof(mk));
	memset(vis,0,sizeof(vis));
	rank.clear();
	for(i=0;i<(int)strlen(s);i++){
		//cout<<"!!!i="<<i<<"  mk[1]="<<mk[1]<<" rank.size()="<<rank.size()<<endl;
		memset(dis,0,sizeof(dis));
		for(it=rank.begin();it!=rank.end();it++){
			if(dis[(*it).second])continue;
			j=(*it).second;dis[j]=1;
			//cout<<"Try j="<<j<<endl;
			if(s[i]==a[j][mk[j]]){
				mk[j]++;
				if(!a[j][mk[j]]){
					printf("%s\n\n",b[j]);
					return;
				}
			}else{
				//cout<<b[j]<<" <OutOfMap At> "<< i <<endl;
				//cout<<"		because of s["<<i<<"]("<<s[i]<<")!=a["<<j<<"]["<<mk[j]<<"]("<<a[j][mk[j]]<<")"<<endl;	
				mk[j]=0;vis[j]=0;
				rank.erase(it);
			}
		}
		for(j=0;j<n;j++)if(!dis[j]){
			if(s[i]==a[j][mk[j]]){		
				if(!vis[j]){
					vis[j]=1;
					rank.insert(pair<int,int>(k++,j));
					//cout<<b[j]<<" <GetInMap At> "<< i <<endl;
				}
				mk[j]++;
				if(!a[j][mk[j]]){
					printf("%s\n\n",b[j]);
					return;
				}
			}else{
				mk[j]=0;
			}
		}
	}
	printf("Nothing Happened\n\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)
		work();
	return 0;
}
