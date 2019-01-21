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

#define maxn 210000
#define maxc 2

#define left chi[0]
#define right chi[1]

#define keynode data[data[root].chi[1]].chi[0]

const int inf=0x3fffffff;

struct node{
	int key,size;
	int rev,dlt,val;
	int chi[maxc],prev;

	void add(const int &d){
		if(!size)return;
		key+=d;
		dlt+=d;
		val+=d;
	}

	void reverse(){
		if(!size)return;
		rev^=1;
		swap(left,right);
	}
};

int arr[maxn];

int min(const int &x,const int &y){ return (x<y)?x:y; }

class CSplay{
	public:
		int root,null;
		int cnt,stk[maxn],tail;
		node data[maxn];

		void update(const int &p){
			data[p].size=data[data[p].left].size+data[data[p].right].size+1;
			data[p].val=min(data[p].key,min(data[data[p].left].val,data[data[p].right].val));
		}

		void trans(const int &p){
			if(data[p].dlt){
				data[data[p].left ].add(data[p].dlt);
				data[data[p].right].add(data[p].dlt);
				data[p].dlt=0;
			}
			if(data[p].rev){
				data[data[p].left ].reverse();
				data[data[p].right].reverse();
				data[p].rev=0;
			}
		}	

		int newnode(const int &var,const int &prev){
			int ret;
			if(tail)
				ret=stk[tail--];
			else
				ret=cnt++;
			data[ret].key=data[ret].val=var;
			data[ret].size=1;
			data[ret].dlt=data[ret].rev=0;
			data[ret].prev=prev;
			data[ret].left=data[ret].right=null;
			return ret;
		}

		void init(){
			cnt=tail=null=0;	
			null=newnode(inf,null);
			data[null].size=0;
			root=newnode(inf,null);
			data[root].right=newnode(inf,root);
			update(root);
		}

		int build(const int &l,const int &r,const int &prev){
			if(l>r)return null;
			int mid=(l+r)>>1;
			int ret=newnode(arr[mid],prev);
			data[ret].left  = build(l,mid-1,ret);
			data[ret].right = build(mid+1,r,ret);
			update(ret);
			return ret;
		}

		//pos=0 stand for zig, pos=1 stand for zag

		void rotate(int &p,const int &pos){int neg=!pos;
			int k=data[p].prev;
			trans(k);trans(p);
			data[k].chi[neg]=data[p].chi[pos];
			if(data[p].chi[pos]!=null){
				data[data[p].chi[pos]].prev=k;
			}
			data[p].prev=data[k].prev;
			if(data[k].prev!=null){
				data[data[k].prev].chi[k==data[data[k].prev].right]=p;
			}
			data[p].chi[pos]=k;
			data[k].prev=p;
			update(k);
			if(k==root)root=p;
		}
		
		void splay(int &p,const int &f){
			trans(p);
			while(data[p].prev!=f){
				if(data[data[p].prev].prev==f){
					rotate(p,data[data[p].prev].left==p);
					break;
				}
				int x=data[p].prev;
				int y=data[x].prev;
				int c=(x==data[y].left);
				if(p==data[x].chi[c]){
					rotate(p,!c);rotate(p,c);
				}else{
					rotate(x,c);rotate(p,c);
				}
			}
			update(p);

		}

		void select(int kth,const int &p){
			int cur=root;
			while(1){
				trans(cur);
				int path=data[data[cur].left].size;
				if(path==kth)break;
				if(path<kth){
					kth -= path+1;
					cur = data[cur].right;
				}else cur=data[cur].left;
			}	
			splay(cur,p);
		}

		void add(const int &u,const int &v,const int &w){
			select(u-1,null);
			select(v+1,root);
			data[keynode].add(w);
			int tmp=keynode;
			splay(tmp,null);
		}

		void reverse(const int &u,const int &v){
			select(u-1,null);
			select(v+1,root);
			data[keynode].reverse();	
		}

		void revolve(const int &u,const int &v,int d){
			int len=v-u+1;
			d=(d% len + len)%len;
			if(!d)return;
			if(d==1){
				del(v);
				insert(u-1,data[stk[tail]].key);
			}else{
				select(v-d+1,null);
				select(v+1,root);
				select(u-1,root);
				select(v,data[root].right);
				int p=data[data[root].left].right;
				data[data[root].left].right=null;
				update(data[root].left);
				data[data[data[root].right].left].right=p;
				data[p].prev=data[data[root].right].left;
				splay(p,null);
			}
		}

		void insert(const int &p,const int &val){
			select(p,null);
			select(p+1,root);
			keynode=newnode(val,data[root].right);
			update(data[root].right);
			int tmp=keynode;
			splay(tmp,null);
		}

		void del(const int &p){
			select(p,null);
			int oriroot=root;
			root=data[root].right;
			data[root].prev=null;
			select(0,null);
			data[root].left=data[oriroot].left;
			data[data[root].left].prev=root;
			update(root);
			stk[++tail]=oriroot;
		}

		int getval(const int &u,const int &v){
			select(u-1,null);
			select(v+1,root);
			return data[keynode].val;
		}

		void creat(const int &num){
			int tmp=build(1,num,null);
			keynode=tmp;
			data[tmp].prev=data[root].right;
			splay(tmp,null);
		}

		void debug(){
			printf("root==%d null==%d\n",root,null);
			vis(root);
		}
		void vis(const int &p){
			if(p==null)return;
			vis(data[p].left);
			printf("node %2d:\n    Left %2d, Right %2d, Prev %2d, Size %2d, Key %2d\n"
					,p,data[p].left,data[p].right,data[p].prev,data[p].size,data[p].key);
			vis(data[p].right);
		}
}spt;

#define len 30

int n,m;
char opt[len];

void work(){
	int i,u,v,w;
	for(i=1;i<=n;i++)scanf("%d",&arr[i]);
	spt.init();
	if(n){ spt.creat(n); }
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%s",opt);
		switch(opt[0]){
			case 'A':
				scanf("%d%d%d",&u,&v,&w);
				spt.add(u,v,w);
				break;
			case 'R':
				if(opt[3]=='E'){
					scanf("%d%d",&u,&v);
					spt.reverse(u,v);
				}else{
					scanf("%d%d%d",&u,&v,&w);
					spt.revolve(u,v,w);
				}
				break;
			case 'I':
				scanf("%d%d",&u,&w);
				spt.insert(u,w);
				break;
			case 'D':
				scanf("%d",&u);
				spt.del(u);
				break;
			case 'M':
				scanf("%d%d",&u,&v);
				printf("%d\n",spt.getval(u,v));
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

