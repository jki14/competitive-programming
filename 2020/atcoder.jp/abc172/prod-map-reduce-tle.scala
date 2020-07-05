object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val foo : Int = stdin.nextInt()
        var bar : java.lang.Long = (1 to foo).map(i => {
            val x : Long = i
            val k : Long = foo / x
            (x + x * k) * k / 2
        }).reduce(_ + _)
        stdout.printf("%d\n", bar.asInstanceOf[java.lang.Long])
    }

    stdin.close()
    stdout.close()
}
