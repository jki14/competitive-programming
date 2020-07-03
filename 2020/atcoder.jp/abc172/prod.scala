object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val foo = stdin.nextInt()
        var bar : Long = 0
        for (i <- 1 to foo) {
            val x : Long = i
            val k : Long = foo / x
            bar += (x + x * k) * k / 2
        }
        stdout.printf("%d\n", bar.asInstanceOf[java.lang.Long])
    }

    stdin.close()
    stdout.close()
}
