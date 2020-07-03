object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val foo = stdin.nextInt()
        var bar : scala.math.BigInt = 0
        for (i <- 1 to foo) {
            val x : scala.math.BigInt = i
            val k : scala.math.BigInt = foo / x
            bar += (x + x * k) * k / 2
        }
        stdout.printf("%s\n", bar.toString)
    }

    stdin.close()
    stdout.close()
}
