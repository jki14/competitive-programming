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

#define maxn 1100000
#define maxc 2

#define left chi[0]
#define right chi[1]

#define keynode data[data[root].chi[1]].chi[0]

const int inf=0x3fffffff;

inline void swap(int &x, int &y){ x=x^y;y=x^y;x=x^y; }

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

inline int min(const int &x,const int &y){ return (x<y)?x:y; }

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
			//printf("add %d->%d %d\n",u,v,w);
                        select(u-1,null);
                        select(v+1,root);
                        data[keynode].add(w);
                        int tmp=keynode;
                        splay(tmp,null);
                }

                void insert(const int &p,const int &val){
			//printf("ins %d %d\n",p,val);
                        select(p,null);
                        select(p+1,root);
                        keynode=newnode(val,data[root].right);
                        update(data[root].right);
                        int tmp=keynode;
                        splay(tmp,null);
                }

                void del(const int &p){
			//printf("del %d\n",p);
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
			//printf("qry %d->%d\n",u,v);
                        select(u-1,null);
                        select(v+1,root);
                        return data[keynode].val;
                }

}spt;

#define len 30

int n,w,cor,tail;
int a[maxn];
char opt[len];

char ch,cstr[len];

int readsigned(){
        int ret,neg;

        do{
                ch = getchar() ;
        }while(ch!='-' && ch<'0');

        if ( ch == '-' ){
                neg = 1 ;
                ret = 0 ;
        }else{
                neg=0;
                ret = ch - '0' ;
        }
        while((ch = getchar()) >= '0'){
                ret = ret * 10 + ch - '0' ;
        }
        if (neg)return -ret;
        return ret;
}

void putsigned(const int &x){
        int k=(x<0)?-x:x,r=0;
        do{
                cstr[r++]=k%10+'0';
                k/=10;
        }while(k);
        if(x<0)putchar('-');
        while(r--){
                putchar(cstr[r]);
        }
        putchar('\n');
}

int main(){
	while(scanf("%d",&n)!=EOF){
       		spt.init();cor=tail=0;
        	for(int i=0;i<n;i++){
                	scanf("%s",opt);
                	switch(opt[0]){
                        	case 'I':
                                	w=readsigned();
                                	spt.insert(cor,cor?spt.getval(cor,cor):0);
					cor++;tail++;
					if(cor<=tail)
						spt.add(cor,tail,-w);
                                	break;
                        	case 'D':
					if(cor==0)break;
                                	spt.add(cor,tail,-(spt.getval(cor,cor)-(cor>1?spt.getval(cor-1,cor-1):0)));
					spt.del(cor);
					cor--;tail--;
                                	break;
                        	case 'L':
                                	if(cor>0)cor--;
                                	break;
                        	case 'R':
                                	if(cor<tail)cor++;
                                	break;
                        	case 'Q':
                                	w=readsigned();
                                	putsigned(-spt.getval(1,w));
                	}
        	}
	}
	return 0;
}
