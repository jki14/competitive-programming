import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    private Scanner stdin;
    private PrintWriter stdout;

    public void execute() {
        this.stdin = new Scanner(new BufferedInputStream(System.in));
        this.stdout = new PrintWriter(new BufferedOutputStream(System.out));

        while (this.stdin.hasNext()) {
            int n = stdin.nextInt();
            int m = stdin.nextInt();
            int foo = 0;
            for (int i = 1; i * i <= m; ++i) {
                if (m % i != 0) continue;
                int j = m / i;
                if (i >= n) foo = Math.max(j, foo);
                if (j >= n) foo = Math.max(i, foo);
            }
            this.stdout.printf("%d\n", foo);
        }

        this.stdin.close();
        this.stdout.close();
    }

    public static void main(String[] args) throws Exception {
        Main instance = new Main();
        instance.execute();
    }

}