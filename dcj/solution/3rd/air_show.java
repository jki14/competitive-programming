import static java.util.Arrays.sort;

import java.math.BigInteger;
import java.util.Comparator;

public class Main {

    static long c(long position, int i) {
        return (position >> (20 * i)) & ((1 << 20) - 1);
    }

    static BigInteger bigSqr(long x) {
        BigInteger bx = BigInteger.valueOf(x);
        return bx.multiply(bx);
    }
    
    static boolean tooClose(int safeDistance, long time, long position, long timeA, long positionA, long timeB, long positionB) {
        if (!(time >= timeA && time <= timeB && timeB - timeA <= 1000000000)) {
            throw new AssertionError();
        }
        long den = timeB - timeA;
        long mulA = timeB - time, mulB = time - timeA;
        long dX = c(positionA, 0) * mulA + c(positionB, 0) * mulB - c(position, 0) * den,
            dY = c(positionA, 1) * mulA + c(positionB, 1) * mulB - c(position, 1) * den,
            dZ = c(positionA, 2) * mulA + c(positionB, 2) * mulB - c(position, 2) * den;
        return bigSqr(dX).add(bigSqr(dY)).add(bigSqr(dZ)).compareTo(bigSqr(safeDistance * den)) < 0;
    }
    
    static final int MASTER = 0;

    public static void main(String[] args) {
        final int nodes = message.NumberOfNodes();
        int me = message.MyNodeId();
        int nn = (int) air_show.GetNumSegments();
        int safeDistance = (int) air_show.GetSafeDistance();
        int from = (int) ((long) nn * me / nodes);
        int to = (int) ((long) nn * (me + 1) / nodes);
        {
            int n = to - from;
            long sum1 = 0, sum2 = 0;
            for (int i = 0; i < n; i++) {
                sum1 += air_show.GetTime(0, from + i);
                sum2 += air_show.GetTime(1, from + i);
            }
            for (int i = 0; i < nodes; i++) {
                writeLong(i, sum1);
                writeLong(i, sum2);
                send(i);
            }
        }
        final long sums1[] = new long[nodes + 1];
        final long sums2[] = new long[nodes + 1];
        for (int i = 0; i < nodes; i++) {
            receive(i);
            sums1[i + 1] = sums1[i] + readLong(i);
            sums2[i + 1] = sums2[i] + readLong(i);
        }
        Integer events[] = new Integer[2 * nodes + 2];
        for (int i = 0; i < events.length; i++) {
            events[i] = i;
        }
        sort(events, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return Long.compare(o1 < nodes + 1 ? sums1[o1] : sums2[o1 - (nodes + 1)],
                    o2 < nodes + 1 ? sums1[o2] : sums2[o2 - (nodes + 1)]);
            }
        });
        int evFrom = events[2 * me + 1];
        int evTo = events[2 * me + 3];
        long sumFrom = evFrom < nodes + 1 ? sums1[evFrom] : sums2[evFrom - (nodes + 1)];
        if (sumFrom == 0) {
            sumFrom = 1;
        }
        long sumTo = evTo < nodes + 1 ? sums1[evTo] : sums2[evTo - (nodes + 1)];
        int ans1 = 0, ans2 = 0;
        if (sumFrom < sumTo) {
            int pos1, pos2;
            long time1, time2, ntime1, ntime2;
            for (pos1 = 1; pos1 < nodes + 1 && sums1[pos1] <= sumFrom; ++pos1) { }
            --pos1;
            time1 = sums1[pos1];
            pos1 = (int) ((long) nn * pos1 / nodes);
            while (true) {
                ntime1 = time1 + air_show.GetTime(0, pos1);
                if (ntime1 > sumFrom) {
                    break;
                }
                time1 = ntime1;
                ++pos1;
            }
            for (pos2 = 1; pos2 < nodes + 1 && sums2[pos2] <= sumFrom; ++pos2) { }
            --pos2;
            time2 = sums2[pos2];
            pos2 = (int) ((long) nn * pos2 / nodes);
            while (true) {
                ntime2 = time2 + air_show.GetTime(1, pos2);
                if (ntime2 > sumFrom) {
                    break;
                }
                time2 = ntime2;
                ++pos2;
            }
            long position1 = air_show.GetPosition(0, pos1);
            long nposition1 = air_show.GetPosition(0, pos1 + 1);
            long position2 = air_show.GetPosition(1, pos2);
            long nposition2 = air_show.GetPosition(1, pos2 + 1);
            boolean proc1 = time1 < sumFrom, proc2 = time2 < sumFrom;
            while (true) {
                if (!proc1 && time1 >= time2) {
                    if (time1 >= sumFrom && time1 < sumTo) {
                        if (tooClose(safeDistance, time1, position1, time2, position2, ntime2, nposition2)) {
                            ++ans1;
                        }
                    }
                    proc1 = true;
                }
                if (!proc2 && time2 >= time1) {
                    if (time2 >= sumFrom && time2 < sumTo) {
                        if (tooClose(safeDistance, time2, position2, time1, position1, ntime1, nposition1)) {
                            ++ans2;
                        }
                    }
                    proc2 = true;
                }
                if (ntime1 <= ntime2) {
                    if (!proc1) {
                        throw new AssertionError();
                    }
                    if (++pos1 >= nn || ntime1 >= sumTo) {
                        break;
                    }
                    time1 = ntime1;
                    position1 = nposition1;
                    ntime1 += air_show.GetTime(0, pos1);
                    nposition1 = air_show.GetPosition(0, pos1 + 1);
                    proc1 = false;
                } else {
                    if (!proc2) {
                        throw new AssertionError();
                    }
                    if (++pos2 >= nn || ntime2 >= sumTo) {
                        break;
                    }
                    time2 = ntime2;
                    position2 = nposition2;
                    ntime2 += air_show.GetTime(1, pos2);
                    nposition2 = air_show.GetPosition(1, pos2 + 1);
                    proc2 = false;
                }
            }
        }
        writeInt(MASTER, ans1);
        writeInt(MASTER, ans2);
        send(MASTER);
        if (me == MASTER) {
            ans1 = 0;
            ans2 = 0;
            for (int i = 0; i < nodes; i++) {
                receive(i);
                ans1 += readInt(i);
                ans2 += readInt(i);
            }
            System.out.println(ans1 + " " + ans2);
        }
    }

    static void writeByte(int target, int value) {
        message.PutChar(target, (char) (value & 0xff));
    }

    static void writeInt(int target, int value) {
        message.PutInt(target, value);
    }

    static void writeLong(int target, long value) {
        message.PutLL(target, value);
    }

    static void send(int target) {
        message.Send(target);
    }

    static void receive(int source) {
        message.Receive(source);
    }

    static int readByte(int source) {
        return message.GetChar(source) & 0xff;
    }

    static int readInt(int source) {
        return message.GetInt(source);
    }

    static long readLong(int source) {
        return message.GetLL(source);
    }
}
