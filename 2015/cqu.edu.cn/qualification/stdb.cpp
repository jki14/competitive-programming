#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
char str1[100001],str2[100001];
int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	int T;
	cin>>T;

	while(T--)
	{
		scanf("%s%s",str1,str2);
		int a=0,b=0;
        int len=strlen(str1);
		for(int i=0;i<len;i++)
		{
			if (str1[i]<='9' && str1[i]>='0') a+=str1[i]-'0';
		}
        len=strlen(str2);
		for(int i=0;i<len;i++)
		{
			if(str2[i]<='9' && str2[i]>='0') b+=str2[i]-'0';
		}
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
