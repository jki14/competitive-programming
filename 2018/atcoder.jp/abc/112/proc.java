import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    private class Altitude {
        private int x;
        private int y;
        private int h;

        public Altitude() {
            this.x = 0;
            this.y = 0;
            this.h = 0;
        }

        public int getX() {
            return this.x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return this.y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public int getH() {
            return this.h;
        }

        public void setH(int h) {
            this.h = h;
        }
    }

    private Scanner stdin;
    private PrintWriter stdout;

    public void execute() {
        this.stdin = new Scanner(new BufferedInputStream(System.in));
        this.stdout = new PrintWriter(new BufferedOutputStream(System.out));

        while (this.stdin.hasNext()) {
            int n = stdin.nextInt();
            Altitude[] a = new Altitude[100];
            for (int i = 0; i < n; ++i) {
                a[i] = new Altitude();
                a[i].setX(this.stdin.nextInt());
                a[i].setY(this.stdin.nextInt());
                a[i].setH(this.stdin.nextInt());
            }
            Altitude foo = new Altitude();
            for (int x = 0; x <= 100; ++x) {
                boolean done = false;
                for (int y = 0; y <= 100; ++y) {
                    foo.setX(x);
                    foo.setY(y);
                    foo.setH(0);
                    for (int i = 0; i < n; ++i) {
                        if (a[i].getH() > 0) {
                            foo.setH(a[i].getH() + Math.abs(foo.getX() - a[i].getX()) + Math.abs(foo.getY() - a[i].getY()));
                            break;
                        }
                    }
                    if (foo.getH() > 0) {
                        done = true;
                        for (int i = 0; i < n; ++i) {
                            if (Math.max(foo.getH() - Math.abs(foo.getX() - a[i].getX()) - Math.abs(foo.getY() - a[i].getY()), 0) != a[i].getH()) {
                                done = false;
                                break;
                            }
                        }
                    }
                    if (done)
                        break;
                }
                if (done)
                    break;
            }
            this.stdout.printf("%d %d %d\n", foo.getX(), foo.getY(), foo.getH());
        }

        this.stdin.close();
        this.stdout.close();
    }

    public static void main(String[] args) throws Exception {
        Main instance = new Main();
        instance.execute();
    }

}