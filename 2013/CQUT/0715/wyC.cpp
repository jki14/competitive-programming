#include<iostream>
using namespace std;

int p;
#define f (p>>1)
#define l (p<<1)
#define r (p<<1)+1
int heap[100010];//,tail;
int raid[100010];

class HEAP{
public:
	int tail;

	int getmax(const int p){
		int ret =p;
		if(l<=tail && heap[l]>heap[ret]) ret = l;
		if(r<=tail && heap[r]>heap[ret]) ret = r;
	}
	
	void push(const int &x,const int &y){
		heap[p=++tail] = x;
		raid[p]=y;
		while(f && heap[f]<heap[p]){
			swap(heap[f],heap[p]);
			swap(raid[f],raid[p]);
			p = f;
		}
	}
	
	void pop(){
		swap(heap[1],heap[tail]);
		swap(raid[1],raid[tail]);
//		cout << heap[tail] << " " << raid[tail] << endl;
		tail--; p=1; int q = getmax(p);
		while(p<=tail && p!=q ){
			swap(heap[p],heap[q]);
			swap(raid[p],raid[q]);
			p=q; q = getmax(p);
		}
	}
	int size(){
		return tail;
	}
};

struct Ans{
	int b;
	int m;
	int s;
	int nn;
};
Ans ans[40000];
int rr[100010][2];

int main()
{
	int n=0;
	cin >> n;
	
	int t=0, k=0, j=0;
	for(int i=0; i<n; ++i)
	{
		cin >> t;

		for(j=0; j<k; ++j)
		{
			if(t == rr[j][0])
			{	rr[j][1]++;	break;	}
		}
		if(j == k)
		{	rr[k][0] = t; rr[k][1]=1; k++;	}
	}

	HEAP heaps;
	for(int i=0; i<k; ++i)
		heaps.push(rr[i][1],rr[i][0]);
	
	int sum=0;
	int a[5],b[5];
	j=0;
	while(heaps.size()>=3)
	{
		for(int i=1; i<=3; ++i)
		{
			t = heaps.size();
			heaps.pop();
			a[i]=heap[t];b[i]=raid[t];
		}
		sum++;
		ans[j].b=b[1]; ans[j].m=b[2]; ans[j].s=b[3];
		j++;
		a[1]--; a[2]--; a[3]--;
		for(int i=1; i<=3; ++i)
			if(a[i]>0)
				heaps.push(a[i],b[i]);	
	}
	cout << sum << endl;
	for(int i=0; i<j; ++i)
	{
		if(ans[i].b<ans[i].m)	swap(ans[i].b,ans[i].m);
		if(ans[i].m<ans[i].s)
		{
			swap(ans[i].m,ans[i].s);
			if(ans[i].b<ans[j].m)	swap(ans[i].b,ans[i].m);
		}
		cout << ans[i].b << " " << ans[i].m << " " << ans[i].s << endl;
	}		
	return 0;
}
