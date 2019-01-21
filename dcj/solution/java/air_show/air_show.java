// Sample input 3, in Java.
public class air_show {
  public air_show() {
  }

  public static long GetNumSegments() {
    return 4L;
  }

  public static long GetSafeDistance() {
    return 1L;
  }

  public static long GetPosition(long airplane, long i) {
    if (airplane == 0L && i == 0L) return 10485770L;
    if (airplane == 0L && i == 1L) return 9437194L;
    if (airplane == 0L && i == 2L) return 8388618L;
    if (airplane == 0L && i == 3L) return 7340042L;
    if (airplane == 0L && i == 4L) return 10L;
    if (airplane == 1L && i == 0L) return 10485770L;
    if (airplane == 1L && i == 1L) return 3145738L;
    if (airplane == 1L && i == 2L) return 3145739L;
    if (airplane == 1L && i == 3L) return 2097163L;
    if (airplane == 1L && i == 4L) return 1048587L;
    throw new IllegalArgumentException("Invalid argument");
  }

  public static long GetTime(long airplane, long i) {
    if (airplane == 0L && i == 0L) return 1L;
    if (airplane == 0L && i == 1L) return 1L;
    if (airplane == 0L && i == 2L) return 1L;
    if (airplane == 0L && i == 3L) return 7L;
    if (airplane == 1L && i == 0L) return 7L;
    if (airplane == 1L && i == 1L) return 1L;
    if (airplane == 1L && i == 2L) return 1L;
    if (airplane == 1L && i == 3L) return 1L;
    throw new IllegalArgumentException("Invalid argument");
  }
}