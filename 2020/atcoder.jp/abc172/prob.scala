object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val lhs = stdin.next()
        val rhs = stdin.next()
        val foo = (p:Int) => lhs(p) == rhs(p) : Boolean
        val bar = (0 to lhs.length() - 1).filterNot(foo).size : java.lang.Integer
        stdout.printf("%d\n", bar)
    }

    stdin.close()
    stdout.close()
}
