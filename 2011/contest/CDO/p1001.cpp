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

#define N 21000
#define M 21000

#define LEN 20


int T;

int n,Q,m,q,t;
int ans[M];
int ax[M],ay[M],ak[M],aid[M];
int bx[M],bk[M],bid[M];

char opt[LEN];

struct myComp{
	bool operator () (const int &i,const int &j){
		return ay[i]<ay[j];
	}
};

set<int> s;
set<int>::iterator it,dit;

set<int,myComp> que;
set<int,myComp>::iterator jt,djt;


int acmp(const int &i,const int &j){
	if(ax[i]!=ax[j])return ax[i]<ax[j];
	if(ay[i]!=ay[j])return ay[i]<ay[j];
	return ak[i]<ak[j];
}

int bccmp(const int &i,const int &j){
	if(bx[i]!=bx[j])return bx[i]<bx[j];
	return bk[i]<bk[j];
}

void work(){
	int i,j,ap,bp,cd,ret;

	s.clear();que.clear();
	m=q=0;
	scanf("%d%d%d",&n,&Q,&t);
	while(Q--){
		scanf("%s",opt);
		if(opt[0]=='A'){
			scanf("%d%d",&ax[m],&ay[m]);
			ak[m]=aid[m]=m;m++;
		}else{
			scanf("%d",&bx[q]);
			bk[q]=m-1;bid[q]=q;q++;
		}
	}

	sort(aid,aid+m,acmp);
	sort(bid,bid+q,bccmp);

	//for(i=0;i<q;i++)printf("bid=%d,bx=%d,bk=%d\n",bid[i],bx[bid[i]],bk[bid[i]]);

	ap=bp=0;

	printf("Case %d:\n",T);
	for(i=1;i<=n;i++){

		printf("i=%d\n",i);

		for(jt=que.begin();jt!=que.end();){
			if(ay[(*jt)]>=i)break;
			
			printf("%d->%d out\n",ax[(*jt)],ay[(*jt)]);

			djt=jt;jt++;
			dit=s.find(*jt);s.erase(dit);
			que.erase(djt);
		}
		while(ap<m && ax[aid[ap]]<=i){

			printf("%d->%d in\n",ax[aid[ap]],ay[aid[ap]]);

			s.insert(aid[ap]);
			que.insert(aid[ap]);
			ap++;
		}
		if(bp<q && bx[bid[bp]]==i){
			j=bid[bp];cd=-1;ret=0;

			printf("j=%d\n",j);
			for(it=s.begin();it!=s.end();it++)printf("%d ",ak[(*it)]);printf("\n");

			for(it=s.begin();it!=s.end();it++){
				if(ak[(*it)]>bk[j]){
					ans[j]=ret;
					bp++;if(bp>=q || bx[bid[bp]]!=i)break;
					j=bid[bp];
				}
				if((*it)>cd){
					cd=(*it)+t-1;
					printf("(*it)=%d cd=%d\n",(*it),cd);
				}else ret++;
			}
			if(bx[j]==i)ans[j]=ret;
		}
	}

	for(i=0;i<q;i++)printf("%d\n",ans[i]);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

