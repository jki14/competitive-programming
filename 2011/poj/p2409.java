import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class p2409{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	private static final int maxn = 50;
	
	//Class Var
	private static int clr,len;
	private static BigInteger []p = new BigInteger [maxn];
	
	//Functions
	private static int gcd(int x,int y){
		if(y==0)return x;
		return gcd(y,x%y);
	}
	
	public static void work(){
		int i;
		
		if(len==0){	cout.printf("0\n");	}
		
		p[0]=BigInteger.ONE;
		for(i=1;i<=len;i++)p[i]=p[i-1].multiply(BigInteger.valueOf(clr));
		
		BigInteger turn = ((len&1)==1) ? p[(len>>1) + 1].multiply(BigInteger.valueOf(len)) : p[(len>>1)].add(p[(len>>1)+1]).multiply(BigInteger.valueOf(len/2));
		
		BigInteger rota = BigInteger.ZERO;
		for(i=1;i<=len;i++){
			rota=rota.add(p[gcd(i,len)]);
		}
		
		BigInteger ret = turn.add(rota).divide(BigInteger.valueOf(len<<1));
		
		cout.printf("%s%n", ret.toString());
	}
	
	public static void main(String[] args)throws Exception{
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		while(cin.hasNext()){
			clr=cin.nextInt();len=cin.nextInt();
			if(clr==0 && len==0)break;
			work();
		}
		
		cin.close();
		cout.close();
	}
}

