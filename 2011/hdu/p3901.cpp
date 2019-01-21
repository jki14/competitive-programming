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

#define L 110000
#define N 25

char a[L],s[L],tmp[L];

int alen,slen,n,size[N];
int src[L],tar[L],from[N][L],reac[N][L];
int numr[N],head[N][L],tail[N][L];

//state表示断点状态，1->'?' 0->'*'
int fail[L],state[L],front,back;

void kmp(char *str,char *pat){
	/* Build Fail */
	memset(fail,0xff,sizeof(fail));
	for(int k,i=1;pat[i];i++){
		for(k=fail[i-1];k>=0 && pat[i]!=pat[k+1];)k=fail[k];
		if(pat[i]==pat[k+1])fail[i]=k+1;
	}
	
	/* kmp core */
	for(int i=0,j=0;str[i] && pat[j];){
		if(str[i]==pat[j]){
			i++;j++;
			if(pat[j]==0){
				//Find new result (-front & +back just for this problem)
				head[n][numr[n]]=i-j -front;
				tail[n][numr[n]]=i-1 +back;
				numr[n]++;
				//Prepare for next result
				j=fail[j-1]+1;
			}
		}else{ 
			if(!j)++i; else j=fail[j-1]+1;
		}
	}
}

void work(){
	/* Init */
	alen=strlen(a);slen=strlen(s);
	memset(numr,0,sizeof(numr));

	/* Case for Head & Tail */
	int hd,td,kd;hd=td=kd=0;

	/*由于b只需要为a的子集,固不需要此操作
	int e=max(alen,slen);
	for(int i=0;i<e;i++){
		if(s[i]=='*')break;
		if(s[i]!='?' && s[i]!=a[i]){
			printf("NO\n");
			return;
		}
	}

	for(int i=slen-1;1;i--){int j=alen-slen+i;
		if(s[i]=='*')break;
		if(i<0 || j<0 || (s[i]!='?' && s[i]!=a[i])){
			printf("NO\n");
			return;
		}
	}*/

	for(int i=0;i<slen;i++){
		if(s[i]!='*' && s[i]!='?'){
			kd=i;
			break;
		}
		if(s[i]=='?')hd++;
		/* for full ? or * string */
		if(i==slen-1){ 
			if(hd<=alen)
				printf("YES\n");
			else
				printf("NO\n");
			return;
		}
	}

	for(int i=slen-1;i>=0;i--){
		if(s[i]!='*' && s[i]!='?'){
			s[i+1]=0;
			break;
		}
		if(s[i]=='?')td++;
	}a[alen-td]=0;
	
	strcpy(a,a+hd);strcpy(s,s+kd);
	alen=strlen(a);slen=strlen(s);

	/* Core */
	front=back=n=0;
	for(int i=0,j=0;1;i++){
		if(i==slen){
			tmp[j]=0;state[n]=0;
			kmp(a,tmp);n++;
			break;
		}
		if(s[i]=='*'){
			if(!j)continue;
			tmp[j]=0;state[n]=j=0;
			kmp(a,tmp);front=back=0;n++;
			continue;
		}
		if(s[i]=='?'){
			if(!j){
				for(front=1;s[i+1]=='?';i++)front++;
			}else{
				for(back=1;s[i+1]=='?';i++)back++;
				tmp[j]=0;j=0;state[n]=(s[i+1]=='*')?0:1;
				kmp(a,tmp);front=back=0;n++;
			}
			continue;
		}
		tmp[j++]=s[i];
	}

	for(int i=0;i<n;i++)if(!numr[i]){
		printf("NO\n");
		return;
	}

	int num,k=0;
	memset(size,0,sizeof(size));
	for(int i=0;i<n;i++){
		if(state[i]){
			num=0;
			for(int j=0;j<numr[i];j++){
				/* binary search */
				int lef=0,rig=numr[i+1]-1,res=-1;
				while(lef<=rig){
					int mid=(lef+rig)>>1;
					if(head[i+1][mid]>tail[i][j]){
						if(!mid || head[i+1][mid-1]<=tail[i][j]){ res=mid;break; }
						rig=mid-1;
					}else lef=mid+1;
				}
				/* update */
				if(res!=-1 && head[i+1][res]==tail[i][j]+1){
					src[num]=head[i][j];
					tar[num]=tail[i+1][res];
					num++;
				}
			}

			if(!num){
				printf("NO\n");
				return;
			}else{
				numr[i+1]=num;
				for(int j=0;j<num;j++){ head[i+1][j]=src[j];tail[i+1][j]=tar[j]; }
			}
		}else{
			for(int j=0;j<numr[i];j++){
				from[k][size[k]]=head[i][j];
				reac[k][size[k]]=tail[i][j];
				size[k]++;
			}
			++k;
		}
	}

	/* Final Check */
	for(int i=0,right=-1;i<k;i++){
		for(int j=0;1;j++){
			if(j==size[i]){
				printf("NO\n");
				return;
			}
			if(from[i][j]>right){
				right=reac[i][j];
				break;
			}
		}
	}

	printf("YES\n");
}

int main(){
	while(scanf("%s%s",a,s)!=EOF)
		work();
	return 0;
}

