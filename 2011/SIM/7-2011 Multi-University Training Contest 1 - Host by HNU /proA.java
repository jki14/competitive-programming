import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class proA{
	//I/O Defined
	private static Scanner cin = new Scanner (new BufferedInputStream(System.in));
	private static PrintWriter cout =n new PrintWriter (new BufferedOutputStream(System.out));
	
	//Size Defined
	private static final int maxn = 20;
	private static final int maxm = 110000;
	
	//Class Var
	private static int n;
	private static int [][]s = new int [maxn][maxm];
	private static BigInteger []a = new BigInteger [maxn];
	private static BigInteger [][]f = new BigInteger [maxm][maxn];
	private static BigInteger [][]w = new BigInteger [maxn][maxn];
	private static BigInteger [][]d = new BigInteger [maxn][maxn];
	
	//Functions
	private static int count(int x){
		int ret=0;
		for(;x;x>>=1)ret+=x&1;
		return ret;
	}
	
	public static void main(String[] args)throws Exception{
		
	}
}
