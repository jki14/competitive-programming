import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	//private static final int maxn = 1100;
	
	//Class Var
	//private static int n;
	
	//Functions
	
	public static void work(){
		BigInteger x, y, z;
		String sx, sy;
		sx=cin.next();
		sy=cin.next();
		
		x=BigInteger.ZERO;
		for(int i=0; i<sx.length(); i++){
			x=x.shiftLeft(1);
			if(sx.charAt(i)=='1')x=x.add(BigInteger.ONE);
		}
		
		y=BigInteger.ZERO;
		for(int i=0; i<sy.length(); i++){
			y=y.shiftLeft(1);
			if(sy.charAt(i)=='1')y=y.add(BigInteger.ONE);
		}
		
		z=x.gcd(y);
		
		for(int i=z.bitLength()-1; i>=0; i--)
			if(z.testBit(i)){
				cout.printf("1");
			}else cout.printf("0");
		cout.printf("\n");
	}
	
	public static void main(String[] args)throws Exception{
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		//while(cin.hasNext()){
			//n=cin.nextInt();
			//work();
			int T=cin.nextInt();
			for(int i=1; i<=T;i++){
				cout.printf("Case #%d: ", i);
				work();
			}
		//}
		
		cin.close();
		cout.close();
	}
}
