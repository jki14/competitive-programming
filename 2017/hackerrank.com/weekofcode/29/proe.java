import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

class Solver{
    private Scanner stdin;
    private PrintWriter stdout;
    private BigDecimal pi=new BigDecimal("3.14159265358979323846264338327950288419716939937510");
    
    private long getx(long y){
        return pi.multiply(BigDecimal.valueOf(y)).add(BigDecimal.valueOf(0.5)).longValue();
    }
    
    private BigDecimal dist(long y){
        return new BigDecimal(getx(y)).divide(BigDecimal.valueOf(y), 128, BigDecimal.ROUND_HALF_UP).subtract(pi).abs();
    }
    
    public void run(){
        stdin = new Scanner(new BufferedInputStream(System.in));
        stdout = new PrintWriter(new BufferedOutputStream(System.out));
        List<Long> steps = new ArrayList<Long>();
        steps.add(Long.valueOf(1));
        BigDecimal p=pi.subtract(pi.setScale(0, BigDecimal.ROUND_FLOOR));
        while(steps.get(steps.size()-1).compareTo(Long.valueOf(1000000000000000L))<0){
            long patch=steps.get(Math.max(steps.size()-2, 0));
            p=BigDecimal.ONE.divide(p, 128, BigDecimal.ROUND_HALF_UP);
            long length=p.longValue();
            p=p.subtract(BigDecimal.valueOf(length));
            
            for(long i=0; i<length && steps.get(steps.size()-1).compareTo(Long.valueOf(1000000000000000L))<0; i++){
                steps.add(Long.valueOf(steps.get(steps.size()-1)+patch));
                //stdout.printf("%d\n", steps.get(steps.size()-1));
            }
        }
        while(stdin.hasNext()){
            long curr=stdin.nextLong();
            long peak=stdin.nextLong();
            while(true){
                boolean flag=true;
                for(Long step : steps){
                    if(curr+step>peak)break;
                    if(dist(curr+step).compareTo(dist(curr))<0){
                        curr+=step;
                        flag=false;
                        break;
                    }
                }
                if(flag)break;
            }
            stdout.printf("%d/%d\n", getx(curr), curr);
        }
        stdin.close();
        stdout.close();
    }
}

public class proe{
    public static void main(String[] args)throws Exception{
        Solver solver = new Solver();
        solver.run();
    }
}
