import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	
	public static BigInteger[] catalan,c;
	public static BigInteger modd;

    public static void main(String[] args) throws Exception{
    	int i,n;
    	
    	modd=BigInteger.valueOf(1);
    	for(i=0;i<100;i++)modd=modd.multiply(BigInteger.valueOf(10));
    	
    	catalan=new BigInteger[11000];
    	c=new BigInteger[11000];
    	
    	catalan[0]=BigInteger.valueOf(1);
    	//for(i=1;i<=5000;i++)catalan[i]=catalan[i-1]*(4*i-2)/(i+1);
    	for(i=1;i<=5100;i++){
    		catalan[i]=catalan[i-1].multiply(BigInteger.valueOf(4*i-2));
    		catalan[i]=catalan[i].divide(BigInteger.valueOf(i+1));
    		//catalan[i]=catalan[i].mod(modd);
    	}
    	for(i=1;i<=5100;i++)catalan[i]=catalan[i].mod(modd);
    	Scanner cin =new Scanner (new BufferedInputStream(System.in));
    	while(cin.hasNextInt()){
    		n=cin.nextInt();c[0]=BigInteger.valueOf(1);
    		//for(i=1;i<=N;i++)C[i]=C[i-1]*(N-i+1)/i;
    		for(i=1;i<=n;i++){
    			c[i]=c[i-1].multiply(BigInteger.valueOf(n-i+1));
    			c[i]=c[i].divide(BigInteger.valueOf(i));
    			//c[i]=c[i].mod(modd);
    		}
    		for(i=1;i<=n;i++)c[i]=c[i].mod(modd);
    		BigInteger ans=BigInteger.valueOf(0),x;
    		//ans+=P((N-i)/2+2,N)/P(2,(N-i)/2)/P(2,i);
    		for (i=(n&1);i<=n;i+=2){
    			x=c[i].multiply(catalan[(n-i)/2]);
    			ans=ans.add(x);
    			ans=ans.mod(modd);
    		}
    		System.out.println(ans.toString());
    	}
    }
}

/*
#include <cstdio>

#include <cstdio>

int catalan[5001];
int N,ans;
int C[10001];

int main()
{
	int i;
	catalan[0]=1;
	for(i=1;i<=5000;i++)catalan[i]=catalan[i-1]*(4*i-2)/(i+1);
	while(scanf("%d",&N)!=EOF)
	{
		C[0]=1;
		for (i=1;i<=N;i++)C[i]=C[i-1]*(N-i+1)/i;
		ans=0;
			for (i=N%2;i<=N;i+=2)
			{
				ans+=C[i]*catalan[(N-i)/2];
			}

			printf("%d\n",ans);
	}
	return 0;
}

*/