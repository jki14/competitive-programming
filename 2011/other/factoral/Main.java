import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main{
	private static Scanner cin;
	private static PrintWriter cout;
	
	private static final int maxn=1100000;
	
	private static int top,n;
	private static BigInteger [] f = new BigInteger[maxn];
	
	
	
	private static void init(){
		top=0;f[0]=BigInteger.ONE;
	}
	
	private static void work(){
		int i;
		for(i=top+1;i<=n;i++)
			f[i]=f[i-1].multiply(BigInteger.valueOf(i));
		cout.printf("%s\n",f[n].toString());
	}
	
	public static void main(String[] args)throws Exception{
		cin =new Scanner (new BufferedInputStream(System.in));
		cout =new PrintWriter (new BufferedOutputStream(System.out));
		
		init();
		
		while(cin.hasNextInt()){
			n=cin.nextInt();
			work();
		}

		cin.close();
		cout.close();	
	}
}
