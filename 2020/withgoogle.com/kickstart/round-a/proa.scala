object Solution {
    def main(args: Array[String]): Unit = {
        val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
        val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

        for (caseId <- 1 to stdin.nextInt()) {
            val n = stdin.nextInt()
            val m = stdin.nextInt()
            val foo = (1 to n)
                .map(_ => stdin.nextInt())
                .sorted
                .scanLeft(0)(_ + _)
                .drop(1)
                .filter(w => w <= m)
                .size
            val bar = s"Case #$caseId: $foo\n" : java.lang.String
            stdout.printf(bar)
        }

        stdin.close()
        stdout.close()
    }
}
