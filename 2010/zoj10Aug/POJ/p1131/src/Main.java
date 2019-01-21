import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
	
	public static BigDecimal eig=BigDecimal.valueOf(8);
	
	public static void work(){
		BigDecimal res=BigDecimal.ZERO;
		BigDecimal k=BigDecimal.ONE.divide(eig);
		String str=cin.next();
		for(int i=2;i<str.length();i++){
			res=res.add(k.multiply(BigDecimal.valueOf(str.charAt(i)-'0')));
			k=k.divide(eig);
		}
		System.out.println(str+" [8] = "+res.toString()+" [10]");
	}
	
	public static void main(String[] args){
		while(cin.hasNext()){
			work();
		}
	}
}