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
            if (n == 1) {
                stdout.printf("Hello World\n");
            } else {
                int a = stdin.nextInt();
                int b = stdin.nextInt();
                stdout.printf("%d\n", a + b);
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