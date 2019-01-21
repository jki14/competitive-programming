#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 110000
#define S 1100000

#define L (i<<1)+1
#define R (i<<1)+2

int n,m;
int cc[S],cp[S];

void update(const int &i){
	cp[i]=cp[L]+cp[R];
}

void build(const int &i,const int &l,const int &r){
	if(l!=r){int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		update(i);cc[i]=0;
	}else cp[i]=cc[i]=0;
}
void modif(const int &i,const int &l,const int &r,const int &u,const int &v);
void clear(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r || cc[i])return;
	if(u<=l && r<=v){
		cc[i]=1;cp[i]=0;
	}else{int mid=(l+r)>>1;
		if(cp[i]==r-l+1){
			modif(L,l,  mid,1,n);
			modif(R,mid+1,r,1,n);
			update(i);
		}
		clear(L,l,  mid,u,v);
		clear(R,mid+1,r,u,v);
		update(i);
	}
}

void modif(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r)return;
	if(cc[i] && l!=r){int mid=(l+r)>>1;
		clear(L,l,  mid,1,n);
		clear(R,mid+1,r,1,n);
		update(i);
	}
	cc[i]=0;
	if(u<=l && r<=v){
		cp[i]=r-l+1;
	}else{int mid=(l+r)>>1;	
		if(cp[i]==r-l+1){
			modif(L,l,  mid,1,n);
			modif(R,mid+1,r,1,n);
			update(i);
		}
		modif(L,l,  mid,u,v);
		modif(R,mid+1,r,u,v);
		update(i);
	}
}

int  query(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<u || v<l || u>r || cc[i])return 0;int ret;
	if(u<=l && r<=v){
		ret=cp[i];
	}else{int mid=(l+r)>>1;
		if(cp[i]==r-l+1){
			modif(L,l,  mid,1,n);
			modif(R,mid+1,r,1,n);
			update(i);
		}	
		ret=query(L,l,  mid,u,v)+query(R,mid+1,r,u,v);
	}
	//if(!i)printf("Q(%d,%d)=%d\n",u-1,v-1,ret);
	return ret;
}

int fndL(const int &x,const int &y){
	int lef=x,rig=n;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(mid-x+1-query(0,1,n,x,mid)!=0){
			if(mid==x || mid-x-query(0,1,n,x,mid-1)==0)return mid;
			rig=mid-1;
		}else lef=mid+1;
	}
	return -2;
}

int estR(){
	int lef=1,rig=n;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(n-mid+1-query(0,1,n,mid,n)){
			if(mid==n || !(n-mid-query(0,1,n,mid+1,n)))return mid;
			lef=mid+1;
		}else rig=mid-1;
	}
	return -1;
}

int fndR(const int &x,const int &y){
	if(n-x+1-query(0,1,n,x,n)<y)return estR();
	int lef=x,rig=n;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(mid-x+1-query(0,1,n,x,mid)>=y){
			if(mid==x || mid-x-query(0,1,n,x,mid-1)<y)return mid;
			rig=mid-1;
		}else lef=mid+1;
	}
	return -1;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		build(0,1,n);
		for(int i=0;i<m;i++){
			int opt,x,y;
			scanf("%d%d%d",&opt,&x,&y);x++;
			if(opt==1){
				if(!y || query(0,1,n,x,n)==n-x+1)
					printf("Can not put any one.\n");
				else{
					int lef=fndL(x,y),rig=fndR(x,y);
					printf("%d %d\n",lef-1,rig-1);
					modif(0,1,n,x,rig);
				}
			}else{y++;
				printf("%d\n",query(0,1,n,x,y));
				clear(0,1,n,x,y);
			}
		}
		printf("\n");
	}
	return 0;
}
