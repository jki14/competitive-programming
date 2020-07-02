object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val n = stdin.nextInt()
        val m = stdin.nextInt()
        val c = stdin.nextLong()

        val lhs = Array.fill(n)(stdin.nextLong()).scanLeft(0L)(_ + _)
        val rhs = Array.fill(m)(stdin.nextLong()).scanLeft(0L)(_ + _)

        var p = 0
        var q = 0

        while (p + 1 <= n && lhs(p + 1) <= c) p += 1

        var foo = p
        while (p >= 0) {
            while (q + 1 <= m && lhs(p) + rhs(q + 1) <= c) q += 1
            foo = scala.math.max(foo, p + q)
            p -= 1
        }

        stdout.printf("%d\n", foo.asInstanceOf[java.lang.Integer])
    }

    stdin.close()
    stdout.close()
}
