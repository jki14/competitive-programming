import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class proG{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	private static final int maxn = 250;
	
	//Class Var
	private static int T,n,m,res;
	private static BigInteger []f = new BigInteger [maxn];
	
	//Functions
	private static boolean tran(int u,int v){
		return f[v].testBit(u);
	}
	
	public static void work(){T++;
		int i,u,v;
		
		res=0;
		for(i=0;i<n;i++)f[i]=BigInteger.ONE.shiftLeft(i);
		
		for(i=0;i<m;i++){
			u=cin.nextInt();v=cin.nextInt();u--;v--;
			if(tran(v,u))
				res++;
			else
				f[u]=f[u].or(f[v]);

			//cout.printf("f[%d]=%s f[%d]=%s%n",u,f[u].toString(),v,f[v].toString());
		}
		
		cout.printf("%d. %d%n", T, res);
	}
	
	public static void main(String[] args)throws Exception{T=0;
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		while(true){
			n=cin.nextInt();m=cin.nextInt();
			if(n==0 && m==0)break;
			work();
		}
		
		cin.close();
		cout.close();
	}
}

