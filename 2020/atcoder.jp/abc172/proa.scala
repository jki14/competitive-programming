object Main extends App {
    val stdin = new java.util.Scanner(new java.io.BufferedInputStream(System.in))
    val stdout = new java.io.PrintWriter(new java.io.BufferedOutputStream(System.out))

    while (stdin.hasNext()) {
        val foo = stdin.nextInt()
        val bar = foo + foo * foo + foo * foo * foo : java.lang.Integer
        stdout.printf("%d\n", bar)
    }

    stdin.close()
    stdout.close()
}
