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
            int threshold = stdin.nextInt();
            int foo = -1;
            for (int i = 0; i < n; ++i) {
                int x = stdin.nextInt();
                int y = stdin.nextInt();
                if (y <= threshold) {
                    if (foo == -1 || foo > x) {
                        foo = x;
                    }
                }
            }
            if (foo >= 0) {
                stdout.printf("%d\n", foo);
            } else {
                stdout.printf("TLE\n");
            }
        }

        this.stdin.close();
        this.stdout.close();
    }

    public static void main(String[] args) throws Exception {
        Main instance = new Main();
        instance.execute();
    }

}
