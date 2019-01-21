//package jp.atcoder.mujin_pc_2017;

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

class Solver{
    private Scanner stdin;
    private PrintWriter stdout;
    
    public void run(){
        stdin = new Scanner(new BufferedInputStream(System.in));
        stdout = new PrintWriter(new BufferedOutputStream(System.out));
        
        while(stdin.hasNextInt()){
            int n = stdin.nextInt();
            List<Integer> a = new ArrayList<Integer>(n);
            int curr=0;
            for(int i=1; i<=n; i++){
                int pos=stdin.nextInt();
                a.add(n-curr);
                curr=Math.max(curr, i-(pos+1)/2);
            }
            long ans=1L, prev=0L;
            long mod=1000000007;
            for(int i=n-1; i>=0; i--){
                //stdout.printf("a[%d]=%d\n", i, a.get(i));
                ans=ans*(a.get(i)-(n-i-1))%mod;
            }
            stdout.println(ans);
        }
        
        stdin.close();
        stdout.close();
    }
}

public class A {
    public static void main(String[] args)throws Exception{
        Solver solver = new Solver();
        solver.run();
    }
}
