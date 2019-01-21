#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
const int N=1e6+10;
using namespace std;
vector<int> c;
vector<int>:: iterator it;
char s1[N],s2[N];
int a[11],b[11];
int main(){
    int t;
    scanf("%d",&t);
    for (int z=1;z<=t;z++){
        scanf("%s",s1);
        scanf("%s",s2);
        printf("Case #%d: ",z);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int l1=strlen(s1);
        for (int i=0;i<l1;i++)
            a[s1[i]-'0']++;
        for (int i=0;i<l1;i++)
            b[s2[i]-'0']++;
        bool fl=false;
        for (int i=1;i<=9;i++){
            if (a[i]){
                fl=true;
                break;
            }
        }
        for (int i=1;i<=9;i++){
            if (b[i]){
                fl=true;
                break;
            }
        }
        if (!fl)    {
            printf("0\n");
            continue;
        }
        int m=9;
        for (int k=1;k<2;){
            bool flag=true;
            for (int i=1;i<=8;i++){
                if ((m-i>0)&&a[i]&&b[m-i]){
                    flag=false;
                    printf("%d",m);
                    a[i]--;
                    b[m-i]--;
                    break;
                }
                if (a[i]&&b[10+m-i]){
                    flag=false;
                    printf("%d",m);
                    a[i]--;
                    b[10+m-i]--;
                    break;
                }
            }
            if (flag)    m--;
            else k++;
if(k<0)return 1;
        }
        m=9;
        for (int k=1;k<l1;){
            bool flag=true;
            for (int i=0;i<=9;i++){
                if ((m-i>=0)&&a[i]&&b[m-i]){
                    flag=false;
                    printf("%d",m);
                    a[i]--;
                    b[m-i]--;
                    break;
                }
                if (a[i]&&b[10+m-i]){
                    flag=false;
                    printf("%d",m);
                    a[i]--;
                    b[10+m-i]--;
                    break;
                }
            }
            if (flag)    m--;
            else k++;
if(k<0)return 1;
        }
        printf("\n");
    }
    return 0;
}
