#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

#define maxl 123
#define maxn 12345
#define maxo 1234567

#define type (*it).first.t
#define author (*it).second
#define inf (*it).first
#define id (*it).first.t

#define xx (*jt).second.x
#define yy (*jt).second.y

struct opr{
	int x,y,t;
	bool operator <(const opr &a)const{
		return x<a.x || (x==a.x && y<a.y);
	}
	opr(){ }
	opr(const int &a,const int &b,const int &c){ x=a;y=b;t=c; }
};

struct line{
	int aut,x,y;
	line(){ }
	line(const int &a,const int &b,const int &c){ aut=a;x=b;y=c; }
};

int n;
map<opr,int> s;
map<opr,int>::iterator it;
map<int,line> l;
map<int,line>::iterator jt;
vector<int> a[maxn];
char nam[maxn][maxl];
int d[maxn],rx[maxn],ry[maxn];

void work(){
	int i,j,k;
	int x,y,t;
	int n1,n2,n3,n4,n5,n6;
	char str[maxl],strx[maxl],stry[maxl];
	s.clear();l.clear();
	d[0]=LONG_MIN;
	memset(rx,0,sizeof(rx));
	memset(ry,0,sizeof(ry));
	for(i=1;i<=n;i++){
		scanf("%s%d%d",nam[i],&d[i],&k);a[i].clear();
		for(j=0;j<k;j++){
			scanf("%s %s %s",strx,stry,str);
			sscanf(strx,"[%d/%d/%d",&n1,&n2,&n3);
			sscanf(stry,"%d:%d:%d]",&n4,&n5,&n6);
			if(str[1]=='Y')
				t=-2;
			else{
				if(str[1]=='U')
					t=-1;
				else
					scanf("%d",&t);
			}
			x=n1*10000+n2*100+n3;
			y=n4*10000+n5*100+n6;
			//cout<<" x="<<x<<" y="<<y<<" t="<<t<<" str="<<str<<endl;
			s.insert(pair<opr,int>(opr(x,y,t),i));
			//cout<<" s.size="<<s.size()<<endl;
			if(t>=0)l[t]=line(0,0,0);
			//cout<<" l.size="<<l.size()<<endl;
		}
	}
	for(it=s.begin();it!=s.end();it++){
		//cout<<":type="<<type<<endl;
		if(type==-2){
			rx[author]=inf.x;
			ry[author]=inf.y;
		}else{
			if(type>=0){
				a[author].push_back(id);
			}else{
				//cout<<"::updata"<<endl;
				for(i=0;i<(int)a[author].size();i++){
					if(d[l[a[author][i]].aut]<d[author]){
						l[a[author][i]].aut=author;
						l[a[author][i]].x=inf.x;
						l[a[author][i]].y=inf.y;
					}
					else{
						if(rx[author]>l[a[author][i]].x
						|| (rx[author]==l[a[author][i]].x && ry[author]>l[a[author][i]].y)){
							l[a[author][i]].aut=author;
							l[a[author][i]].x=inf.x;
							l[a[author][i]].y=inf.y;
						}
					}
				}
				a[author].clear();
			}
		}
	}
	for(jt=l.begin();jt!=l.end();jt++){
		printf("%d [",(*jt).first);

		n1=(int)xx/10000;xx%=10000;
		if(((int)n1/1000)>0)
		printf("%d/",n1);
		else if(((int)n1/100)>0)
			printf("0%d/",n1);
		else if(((int)n1/10)>0)
			printf("00%d/",n1);
		else
			printf("000%d/",n1);

		n2=(int)xx/100;xx%=100;
		if(((int)n2/10)>0)
			printf("%d/",n2);
		else
			printf("0%d/",n2);

		n3=xx;
		if(((int)n3/10)>0)
			printf("%d ",n3);
		else
			printf("0%d ",n3);

		n4=(int)yy/10000;yy%=10000;
		if(((int)n4/10)>0)
			printf("%d:",n4);
		else
			printf("0%d:",n4);

		n5=(int)yy/100;yy%=100;
		if(((int)n5/10)>0)
			printf("%d:",n5);
		else
			printf("0%d:",n5);

		n6=yy;
		if(((int)n6/10)>0)
			printf("%d]",n6);
		else
			printf("0%d]",n6);

		printf(" BY %s\n",nam[(*jt).second.aut]);
	}
	printf("END\n");
}

int main(){
	while(scanf("%d",&n) && n!=0)
		work();
	return 0;
}
