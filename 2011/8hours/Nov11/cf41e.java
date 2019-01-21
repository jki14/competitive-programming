import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	private static final int N = 110;
	private static final int maxn = 100;
	
	//Class Var
	private static int n;
	private static BigInteger []a = new BigInteger [N];
	private static BigInteger []bit = new BigInteger [N];
	
	public static void work(){

		BigInteger zero = BigInteger.ZERO;
		BigInteger one =  BigInteger.ONE;
		BigInteger full = bit[n].subtract(BigInteger.ONE);
		
		int ans=n*(n-1)/2;
		for(int i=0;i<n;i++)a[i]=full.xor(one.shiftLeft(i));
		
		while(true){
			int best,u,v;best=u=v=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(!a[i].testBit(j))continue;
					//if(i==0 && j==1)System.out.printf("that=%s%n",a[i].and(bit[j]).toString());
					int bitcnt=a[i].and(a[j]).bitCount();
					if(bitcnt>best){
						best=bitcnt;
						u=i;v=j;
					}
				}
			}
			if(best==0)break;ans--;
			//System.out.printf("best=%d u=%d v=%d a[u]=%s a[v]=%s bit[u]=%s bit[v]=%s %n",best,u,v,a[u].toString(),a[v].toString(),bit[u].toString(),bit[v].toString());
			a[u]=a[u].clearBit(v);a[v]=a[v].clearBit(u);
		}
		
		cout.printf("%d%n",ans);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(!a[i].testBit(j))continue;
				cout.printf("%d %d%n",i+1,j+1);
			}
		}
	}
	
	public static void main(String[] args)throws Exception{
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		for(int i=0;i<=maxn;i++)bit[i]=BigInteger.ONE.shiftLeft(i);
		
		while(cin.hasNext()){
			n=cin.nextInt();
			if(n==0)break;
			work();
		}
		
		cin.close();
		cout.close();
	}
}

