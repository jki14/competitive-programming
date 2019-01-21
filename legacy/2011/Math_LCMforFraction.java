//============================================================================
// Name        : LCMforFraction
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ3101(给定n个行星公转周期，询问连续两次行星连同恒星连成一条直线的最
//短间隔，即(0.5/(1/ti-1/ti+1))的最小公倍数, 分数的LCM即为:分子的LCM/分母的GCD
//============================================================================

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class p3101{
	//I/O Defined
	private static Scanner cin;
	private static PrintWriter cout;
	
	//Size Defined
	//private static final int maxn = 1100;
	
	//Class Var
	private static int n;
	
	//Functions
	
	public static void work(){
		int i;
		boolean first=true;
		BigInteger ans1,ans2,d;
		BigInteger []t = new BigInteger [n];
		BigInteger []a = new BigInteger [n];
		BigInteger []b = new BigInteger [n];
		
		
		for(i=0;i  <n;i++){ t[i]=cin.nextBigInteger(); }
		Arrays.sort(t);
		
		for(i=0;i+1<n;i++){ 
			a[i]=t[i].multiply(t[i+1]);
			b[i]=t[i+1].subtract(t[i]).multiply(BigInteger.valueOf(2));

			//cout.printf("t[i]=%s t[i+1]=%s a[i]=%s b[i]=%s\n",t[i].toString(),t[i+1].toString(),a[i].toString(),b[i].toString());
			d=a[i].gcd(b[i]);
			a[i]=a[i].divide(d);
			b[i]=b[i].divide(d);
		}
		
		ans1=BigInteger.valueOf(0);ans2=BigInteger.valueOf(1);
		for(i=0;i+1<n;i++){
			if(b[i]==BigInteger.ZERO)continue;
			if(first){first=false;
				ans1=a[i];ans2=b[i];
			}else{
				ans1=ans1.multiply(a[i]).divide(ans1.gcd(a[i]));
				ans2=ans2.gcd(b[i]);
			}
		}
		
		d=ans1.gcd(ans2);
		ans1=ans1.divide(d);
		ans2=ans2.divide(d);
		
		cout.printf("%s %s\n",ans1.toString(),ans2.toString());
	}
	
	public static void main(String[] args)throws Exception{
		cin = new Scanner (new BufferedInputStream(System.in));
		cout = new PrintWriter (new BufferedOutputStream(System.out));
		
		while(cin.hasNext()){
			n=cin.nextInt();
			work();
		}
		
		cin.close();
		cout.close();
	}
}
