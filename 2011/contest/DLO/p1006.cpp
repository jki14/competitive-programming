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

#define maxm 2100000

int n,m,K,num,tot;
int c[maxm],lowbit[maxm];
int a[maxm],ans[maxm],ANS;
int opt[maxm],tar[maxm],rm[maxm];

char str[10];

//#include<iostream>
//#include<sstream>
//#include<cstdio>
//#include<cstdlib>
//#include<cstring>
//#include<cmath>
//#include<ctime>
//#include<climits>
//#include<algorithm>
//#include<vector>
//#include<string>
//#include<set>
//#include<map>
//using namespace std;
//
//#define maxn 1100
//
//map<int,int> s;
//map<int,int>::iterator it;
//
//int n,m,ans;
//int x[maxn],y[maxn];
//int rgx[4][2],rgy[4][2];
//
//void work(){
//	int i,j,k,ret;ans=0;
//		rgx[0][0]=-m;rgy[0][0]=-m;
//			rgx[1][0]=-m;rgy[1][0]= 0;
//				rgx[2][0]= 0;rgy[2][0]=-m;
//					rgx[3][0]= 0;rgy[3][0]= 0;
//						rgx[0][1]= 0;rgy[0][1]= 0;
//							rgx[1][1]= 0;rgy[1][1]= m;
//								rgx[2][1]= m;rgy[2][1]= 0;
//									rgx[3][1]= m;rgy[3][1]= m;
//
//										for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
//											for(i=0;i<n;i++){
//													for(k=0;k<4;k++){ret=0;
//																for(j=0;j<n;j++){
//																				if((x[j]>=x[i]+rgx[k][0] && x[j]<=x[i]+rgx[k][1])
//																								&& (y[j]>=y[i]+rgy[k][0] && y[j]<=y[i]+rgy[k][1]))ret++;
//																											}
//																														ans=max(ans,ret);
//																																}
//																																	}
//																																		printf("%d\n",ans);
//																																		}
//
//																																		int main(){
//																																			while(scanf("%d%d",&n,&m)!=EOF)
//																																					work();
//																																						return 0;
//																																						}
//

void del(int x){
	for(;x<=num;x+=lowbit[x])c[x]--;
}

int que(int x){

	//printf("Que\n");

	//printf("lowbit[%d]=%d\n",x,lowbit[x]);

	int ret=0;
	for(;x;x-=lowbit[x]){
		//printf("lowbit[%d]=%d\n",x,lowbit[x]);
		ret+=c[x];
	}
	//printf("Que End\n");

	return ret;
}

void remove(const int &x){

	//printf("Remove %d\n",x);

	int l=1,r=num;
	while(l<=r){
		int mid=(l+r)>>1;
		//printf("a[mid]=%d\n",a[mid]);
		if(a[mid]==x){
			//printf("a[mid-1]=%d rm[mid-1]=%d rm[mid]=%d\n",a[mid-1],rm[mid-1],rm[mid]);
			if((a[mid-1]>x && rm[mid]==0) || (rm[mid-1]==1 && rm[mid]==0)){
				rm[mid]=1;
				del(mid);
				tot--;
				return;
			}
			if(rm[mid]==0)r=mid-1;else l=mid+1;
		}else{
			if(a[mid]>x)l=mid+1; else r=mid-1;
		}
	}
	while(1);
}

int find(){

	//printf("Find\n");

	int l=1,r=num,tmp;
	while(l<=r){
		int mid=(l+r)>>1;
		if((tmp=que(mid))==K){
			if(que(mid-1)<K)return a[mid];
			r=mid-1;
		}
		if(tmp<K)l=mid+1;else r=mid-1;
	}
	while(1)printf("	\n");
}

int cmp(const int &i,const int &j){ return i>j; }

void work(){
	int i;
	for(num=tot=i=0;i<n;i++){
		scanf("%s",str);
		if(str[0]=='Q'){
			opt[i]=1;
			continue;
		}
		opt[i]=0;scanf("%d",&a[++num]);
		tar[i]=a[num];tot++;
	}

	sort(a+1,a+num+1,cmp);a[0]=LONG_MAX;a[num+1]=LONG_MIN;
	memset(rm,0,sizeof(rm));

	for(i=0;i<=num;i++){
		c[i]=lowbit[i]=i&(-i);
	}
	
	ANS=0;
	for(i=n-1;i>=0;i--){
		if(opt[i]){
			ans[++ANS]=find();
		}else{
			remove(tar[i]);
		}
	}

	for(;ANS;ANS--){
		printf("%d\n",ans[ANS]);
	}

}

int main(){
	//for(int i=0;i<maxm;i++)lowbit[i]=i&(-i);
	while(scanf("%d%d",&n,&K)!=EOF)
		work();
	return 0;
}

