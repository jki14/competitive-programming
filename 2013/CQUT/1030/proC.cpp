#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define B 2
#define S 1100000
#define C 3100000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=0x3f3f3f3f;
const int neg=0xc0c0c0c0;

char a[B][S],s[5];

int n,m;
int c[C];

inline int max(const int &x,const int &y){ return x>y?x:y; }

void update(const int &i){ if(c[L]==c[R])c[i]=c[L]; }

void modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &w){

	//if(!i)printf("modify(%d->%d)==%d\n",u,v,w);

	if(u>v || v<l || u>r)return;
	if(u<=l && r<=v){
		c[i]=w;
	}else{int mid=(l+r)>>1;
		if(c[i]!=neg){
			modify(L,l,  mid,0,n-1,c[i]);
			modify(R,mid+1,r,0,n-1,c[i]);
			c[i]=neg;
		}
		modify(L,l,  mid,u,v,w);
		modify(R,mid+1,r,u,v,w);
		update(i);
	}
}

int  querry(const int &i,const int &l,const int &r,const int &p){
	//if(!i)printf("querry(%d->%d) %d\n",l,r,p);
	if(p<l || p>r)return neg;
	if(c[i]!=neg){
		return c[i];
	}else{
		//if(l==r)while(1);
		int mid=(l+r)>>1;
		return max(querry(L,l,  mid,p),
			   querry(R,mid+1,r,p));
	}
}

int find(const int &x){
	int l=0,r=n-1;
	while(l<=r){int mid=(l+r)>>1;
		if(querry(0,0,n-1,mid)>=x){
			if(mid==0 || querry(0,0,n-1,mid-1)<x)return mid;
			r=mid-1;
		}else l=mid+1;
	}
	return 0;
}

/*int find2(const int &x){
	int l=0,r=n-1;
	while(l<=r){int mid=(l+r)>>1;
		if(querry(0,0,n-1,mid)>=x){
			if(mid==0 || querry(0,0,n-1,mid-1)<x)return mid;
			r=mid-1;
		}else l=mid+1;
	}
	return 0;

}*/

//void debug(){ for(int i=0;i<n;i++)printf(" %d",querry(0,0,n-1,i));printf("\n"); }

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case %d:\n",_T);
		scanf("%s%s",a[0],a[1]);n=min(strlen(a[0]),strlen(a[1]));
		
		memset(c,0xc0,sizeof(c));
		for(int i=n-1;i>=0;i--){
			if(a[0][i]!=a[1][i]){
				modify(0,0,n-1,i,i,i-1);
				continue;
			}
			int tail=i;while(i>0 && a[0][i-1]==a[1][i-1])i--;
			modify(0,0,n-1,i,tail,tail);
		}
		
		//debug();

		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int k;scanf("%d",&k);
			if(k==1){
				int x,y,p;
				scanf("%d%d%s",&x,&p,s);x--;y=x^1;
				//printf("change %d %d %c\n",x,p,s[0]);
				if(p>=n)continue;
				if(a[x][p]!=a[y][p] && s[0]==a[y][p]){
					int head=p>0?find(p-1):0,tail=p<n-1?querry(0,0,n-1,p+1):p;
					modify(0,0,n-1,head,tail,tail);
				}else if(a[x][p]==a[y][p] && s[0]!=a[y][p]){
					int head=min(find(p),p),tail=p;
					modify(0,0,n-1,head,tail,p-1);
					//printf("modify %d->%d==%d\n",head,tail,p-1);
				}
				a[x][p]=s[0];
				//debug();
			}else{
				int p;scanf("%d",&p);
				printf("%d\n",querry(0,0,n-1,p)-p+1);
			}
		}
	}
}
