import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class proB{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	private static final int N = 60;
	
	//Class Var
	private static int n,m;
	private static BigInteger ans;
	private static int []a = new int [N];
	private static BigInteger [][]f = new BigInteger [N][N];
	private static BigInteger []p = new BigInteger [N];
	private static BigInteger [][]c = new BigInteger [N][N];
	
	//Functions
	private static void P(){
		p[0]=BigInteger.ONE;
		for(int i=1;i<=50;i++)p[i]=p[i-1].multiply(BigInteger.valueOf(i));
	}
	
	private static void C(){
		for(int i=0;i<=50;i++)
			for(int j=0;j<=i;j++)
				c[i][j]=p[i].divide(p[j]).divide(p[i-j]);
	}
	
	public static void work(){
		
		//cout.printf("n=%d m=%d%n",n,m);

		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=BigInteger.ZERO;
		f[0][0]=BigInteger.ONE;
		
		for(int i=1;i<=m;i++){ a[i]=cin.nextInt(); }
		
		for(int i=1;i<=m;i++){
			for(int j=0;j<=a[i];j++){
				for(int k=0;k+j<=n;k++){
					if(f[i-1][k]==BigInteger.ZERO)continue;

					//cout.printf("i=%d j=%d k=%d%n",i,j,k);

					f[i][k+j]=f[i][k+j].add(c[k+j][j].multiply(f[i-1][k]));

					//cout.printf("f[%d][%d]=%s%n",i,k+j,f[i][k+j].toString());
				}
			}
		}
		
		/*for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
				cout.printf("f[%d][%d]=%s%n",i,j,f[i][j].toString());*/

		ans=f[m][n];
		
		cout.printf("%s%n",ans.toString());
	}
	
	public static void main(String[] args)throws Exception{
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		P();C();

		while(cin.hasNext()){
			n=cin.nextInt();
			m=cin.nextInt();
			if(n==0 && m==0)break;
			work();
		}
			
		cin.close();
		cout.close();
	}
}

