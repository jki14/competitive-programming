#include<cstdio>
using namespace std;

#define maxn 110
#define maxm 11000
#define L 2

int n,m,q,ans;
int w[maxn][maxm],d[maxn][maxm];
int f[maxn][maxm],que[L][maxm],head[L],tail[L],val[L][maxm];

char cstr[maxn],ch;

int readsigned(){
	int ret,neg;

	do{
		ch = getchar() ;
	}while(ch!='-' && ch<'0');
        
	if (ch== '-'){
		neg=1;
                ret=0;
	}else{
		neg=0;
		ret=ch-'0';
	}
	while((ch=getchar())>='0'){
		ret=ret*10+ch-'0';
	}
	if(neg)return -ret;
	return ret;
}

int readunsigned(){
	int ret;

	do{
		ch = getchar() ;
	}while(ch<'0');
	ret=ch-'0';

	while((ch=getchar())>='0'){
		ret=ret*10+ch-'0';
	}
	
	return ret;
}

void putunsigned(const int &x){
	int k=x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	while(r--){
		putchar(cstr[r]);
	}
	putchar('\n');
}

void putsigned(const int &x){
	int k=x;	
	if(k<0){ putchar('-');k=-k; }
	putunsigned(k);
}

int main(){
	while(1){
		//scanf("%d%d%d",&n,&m,&q);
		n=readunsigned();
		m=readunsigned();
		q=readunsigned();

		if(n==0 && m==0 && q==0)break;
		
		int i,j,k;
		ans=0;n++;
	
		for(i=1;i<=n;i++){
			w[i][0]=0;
			for(j=1;j<=m;j++){
				//scanf("%d",&w[i][j]);
				w[i][j]=readsigned();
				w[i][j]+=w[i][j-1];
			}
		}
		for(i=1;i<=n;i++){
			d[i][0]=0;
			for(j=1;j<=m;j++){
				//scanf("%d",&d[i][j]);
				d[i][j]=readunsigned();
				d[i][j]+=d[i][j-1];
			}
		}
	
		for(j=0;j<=m;j++)f[0][j]=0;

		for(i=1;i<=n;i++){
			for(j=head[0]=head[1]=tail[0]=tail[1]=k=0;j<=m;j++){
				while(head[0]<tail[0] && d[i][j]-d[i][que[0][head[0]]]>q)head[0]++;
				while(head[1]<tail[1] && que[1][head[1]]<j)head[1]++;
			
				val[0][j]=f[i-1][j]-w[i][j];
				while(head[0]<tail[0] && val[0][que[0][tail[0]-1]]<=val[0][j])tail[0]--;
				que[0][tail[0]++]=j;
			
				while(k<=m && d[i][k]-d[i][j]<=q){
					val[1][k]=f[i-1][k]+w[i][k];
					while(head[1]<tail[1] && val[1][que[1][tail[1]-1]]<=val[1][k])tail[1]--;
					que[1][tail[1]++]=k++;
				}
			
				f[i][j]=val[0][que[0][head[0]]]+w[i][j];
				if(head[1]<tail[1] && f[i][j]<val[1][que[1][head[1]]]-w[i][j])
					f[i][j]=val[1][que[1][head[1]]]-w[i][j];
			}
		}

		for(j=0;j<=m;j++)if(ans<f[n][j])ans=f[n][j];
		//printf("%d\n",ans);
		putunsigned(ans);
	}
	return 0;
}

