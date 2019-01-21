import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class p1426 {
	
	//public static PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out)); 	

	public static void main(String[] args) throws Exception{
		
		final int maxk = 101;
		final int maxd = 201;
		final BigInteger ten = BigInteger.TEN;
		
		int[] s=new int [maxk];
		int[] f=new int [maxd];
		int[][] r= new int [maxd][maxk];
		
		Scanner cin = new Scanner (new BufferedInputStream(System.in));
		//PrintWriter cout = new PrintWriter (System.out);
		
		int N,i,j,x,rem,tail;
		BigInteger n,m;
		
		while(cin.hasNextInt()){
			//System.out.printf("new Case!%n");
			//System.out.printf("new Case!%n");
			N = cin.nextInt();
			if(N==0)break;
			n = BigInteger.valueOf(N);
			m = BigInteger.ONE;
			for(i=0;i<maxk;i++){
				s[i]=m.mod(n).intValue();
				m=m.multiply(ten);
				//System.out.printf("s[%d]=%d%n",i,s[i]);
			}
			Arrays.fill(f, 0);
			//Arrays.fill(r, 0);
			for(i=0;i<maxd;i++)
				for(j=0;j<maxk;j++)
					r[i][j]=0;
			for(i=0;i<maxk;i++){
				if(f[s[i]]==0){
					//System.out.printf("rem=%d%n",s[i]);
					f[s[i]]=2;
					r[s[i]][i]=1;
				}
				for(j=1;j<N;j++){
					if(f[j]!=1)continue;
					rem=(j+s[i])%N;
					if(f[rem]==0){
						//System.out.printf("rem=%d%n",rem);
						f[rem]=2;
						for(x=0;x<maxk;x++)
							r[rem][x]=r[j][x];
						r[rem][i]=1;
					}
				}
				for(j=0;j<N;j++)if(f[j]==2)f[j]=1;
			}
			tail=maxk-1;
			while(r[0][tail]==0 && tail>0)tail--;
			//System.out.printf("tail=%d%n",tail);
			for(i=tail;i>=0;i--){
				System.out.printf("%d", r[0][i]);
			}
			System.out.printf("%n");
		}
	}
}
