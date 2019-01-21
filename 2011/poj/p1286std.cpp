#include <stdio.h>
#include <string.h>

typedef long long __int64;

__int64 pow(__int64 x, __int64 y)
{
 if(y == 0) return 1;
 if(y == 1) return x;
 
 if(y%2 == 0)
 {
  return pow(x, y/2) * pow(x,y/2);
 }
 else
 {
  return pow(x,y/2) * pow(x, y/2) * x;
 }

 return 0;
}

__int64 gcd(__int64 a, __int64 b)
{
 if(b == 0)
  return a;
 else
  return gcd(b, a%b);
}

__int64 polay1(__int64 n, __int64 k) 
//旋转
{
 __int64 i;
 __int64 sum = 0;
 for(i=1; i<=n; i++)
 {
  sum += pow(k , gcd(n, i)); 
 }
 return sum;
}

__int64 polay2(__int64 n, __int64 k)
{
 __int64 sum;
 if(n%2 == 0)
 {
  sum = pow(k, n/2+1) * (n/2);
  sum += pow(k, n/2) *(n/2);
 }
 else
 {
  sum = pow(k, n/2+1) * n;
 }
 return sum;
}

int main()
{
 //freopen("in.txt","r",stdin);
 __int64 n;
 __int64 sum;
 while(scanf("%lld", &n) && n!=-1)
 {
  if(n==0) 
  {
   printf("0\n");
   continue;
  }
  sum = polay1(n, 3);
  sum += polay2(n, 3);
  sum /= (n*2);
  printf("%lld\n", sum);
 }
 return 0;
}
