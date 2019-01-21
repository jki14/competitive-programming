#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 300

#define P (a[j].first)
#define V (a[j].second)

typedef pair<double,int> PDI;

const double eps=1e-4;
const double inf=(double)LONG_MAX;
const double _inf=(double)LONG_MIN;

int T;
int D,c,n;
int f[maxn];
int mk[maxn];
map<int,int> s;
map<int,int>::iterator it;
vector<PDI> a;
PDI tmp;
double res,d,L,R,l,r,dL,dR,pL,pR;
double tail[maxn],head[maxn];

int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}

void work(){
	int i,j,k,sum;
	s.clear();res=0.0;
	scanf("%d%d",&c,&D);d=(double)D;
	while(c--){
		scanf("%d%d",&i,&j);
		it=s.find(i);
		if(it==s.end())
			s.insert(pair<int,int>(i,j));
		else
			(*it).second+=j;
	}
	a.clear();
	for(it=s.begin();it!=s.end();it++){
		tmp.first=(double)(*it).first;
		tmp.second=(*it).second;
		a.push_back(tmp);
		//cout<<"push "<<tmp.first<<" "<<tmp.second<<endl;
	}
	n=a.size();
	for(i=0;i<n;i++){ f[i]=i; }
	for(i=0;i<n;i++){k=find(i);sum=0;L=l=inf;R=r=_inf;dL=dR=0;
		for(j=k;j<n && find(j)==k;j++){
			double s=((double)sum)*d,t=((double)(sum+V-1))*d;
			//cout<<" s="<<s<<" t="<<t<<" P="<<P<<endl;
			l=min(l,s-P);
			r=max(r,t-P);
			if(L+dL>s){
				L=P;
				dL=s-P;
			}
			if(R+dR<t){
				R=P;
				dR=t-P;
			}
			sum+=V;
			//cout<<"j="<<j<<" find(j)="<<find(j)<<endl;
		}
		L=L+dL+(l-r)/2-l;
		R=R+dR+(r-l)/2-r;
		if(k && ((L-tail[find(k-1)])<(d-eps))){
			//cout<<"L="<<L<<" tail[find(k-1)]="<<tail[find(k-1)]<<" d="<<d<<endl;
			//printf("%.12lf < %.12lf\n",L-tail[find(k-1)],d+eps);
			f[k]=find(k-1);i--;continue;
		}
		tail[k]=R;
		//cout<<" l="<<l<<" r="<<r<<endl;
		res=max(res,fabs((r-l)/2));
	}
	//for(i=0;i<n;i++)cout<<"f["<<i<<"]="<<f[i]<<endl;
	printf("Case #%d: %.12lf\n",T,res);
}

int main(){
	freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

