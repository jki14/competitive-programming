#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

const int maxn=21000,maxt=10;

struct item
{
	int f,d;
	item()
	{
		f=0;d=0;
	}
};

int timer;
int n,m,maxs;
bool s[maxn];
map<int,item> g;
map<int,item>::iterator _g,_g0,_g1;
item tmp,_tmp;

item getf(int x)
{
	item res;
	map<int,item>::iterator _g;
	_g=g.find(x);
	if(_g==g.end())
	{
		res.d=-1;
		return res;
	}
	if((*_g).first!=(*_g).second.f)
	{
		res=getf((*_g).second.f);
		(*_g).second.f=res.f;
		(*_g).second.d=(*_g).second.d^res.d;
	}
	return (*_g).second;
}

bool insert(int x,int f,int v)
{
	_g0=g.find(f);_g1=g.find(x);
	if(_g0==g.end())
	{
		if(_g1==g.end())
		{
			tmp.f=f;
			tmp.d=0;
			g.insert(pair<int,item>(f,tmp));
			tmp.f=f;
			tmp.d=v;
			g.insert(pair<int,item>(x,tmp));
		}
		else
		{
			tmp=getf(x);
			if(tmp.f>f)
			{
				_g=g.find(tmp.f);
				(*_g).second.f=x;
				(*_g).second.d=tmp.d;
				(*_g1).second.f=f;
				(*_g1).second.d=v;
				tmp.f=f;
				tmp.d=0;
				g.insert(pair<int,item>(f,tmp));
			}
			else
			{
				tmp.d=tmp.d^v;
				g.insert(pair<int,item>(f,tmp));
			}
		}
	}
	else
	{
		if(_g1==g.end())
		{
			tmp.f=f;
			tmp.d=v;
			g.insert(pair<int,item>(x,tmp));
		}
		else
		{
			tmp=getf(x);_tmp=getf(f);
			if(tmp.f==_tmp.f)
			{
				if((tmp.d^_tmp.d^v)!=0)
					return false;
			}
			else
			{
				if(tmp.f>_tmp.f)
				{
					_g=g.find(tmp.f);
					(*_g).second.f=_tmp.f;
					(*_g).second.d=tmp.d^v^_tmp.d;
				}
				else
				{
					_g=g.find(_tmp.f);
					(*_g).second.f=tmp.f;
					(*_g).second.d=tmp.d^v^_tmp.d;
				}
			}
		}
	}
	return true;
}

bool getans()
{
	int i,res=0;
	for(i=maxs;i>=0;i--)
	{
		if(s[i])
		{
			tmp=getf(i);
			if(tmp.d<0)return false;
			if(tmp.f==i)
				return false;
			if(tmp.f==-1)
			{
				res^=tmp.d;
				s[i]=false;
			}
			else
			{
				s[tmp.f]=(s[tmp.f])?false:true;
				res^=tmp.d;
				s[i]=false;
			}
		}
	}
	printf("%d\n",res);
	return true;
}

bool doit()
{
	scanf("%d %d",&n,&m);
	if((!n)&&(!m))return false;
	printf("Case %d:\n",timer);
	char t[maxt],c;
	int p,q,v,k,x,i=0;
	bool still=true,imp;
	g.clear();maxs=LONG_MIN;
	while(m--)
	{
		scanf("%s",t);
		if(t[0]=='I')
		{
			i++;
			scanf("%d %d",&p,&q);
			scanf("%c",&c);
			//cout<<"th C=>"<<c<<"<"<<endl;
			if(c==' ')
				scanf("%d",&v);
			else
			{
				v=q;
				q=-1;
			}
			if(!still)continue;
			if(p==q)continue;
			if(p<q)
			{
				p=p^q;
				q=p^q;
				p=p^q;
			}
			if(p>maxs)maxs=p;
			//cout<<"I "<<p<<":"<<q<<"="<<v<<endl;
			if(!insert(p,q,v))
			{
				still=false;
				printf("The first %d facts are conflicting.\n",i);
			}
		}
		else
		{
			scanf("%d",&k);
			memset(s,0,sizeof(s));
			imp=false;
			while(k--)
			{
				scanf("%d",&x);
				if(!still)continue;
				if(x>maxs)
				{
					imp=true;
					continue;
				}
				if(s[x])
					s[x]=false;
				else
					s[x]=true;
			}
			if(!still)continue;
			if((imp)||(!getans()))
			{
				printf("I don't know.\n");
			}
		}
	}
	printf("\n");
	return true;
}

int main()
{
	timer=1;
	while(doit())timer++;
	return 0;
}
