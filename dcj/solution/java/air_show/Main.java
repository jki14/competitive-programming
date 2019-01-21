import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

class Interval {
	public int k, from, to;
	public long startTime, finishTime;
}

class Cache {
	/*
	 * private Map<Integer, Long>[] timeCache; private Map<Integer, Long>[]
	 * positionCache;
	 */

	public Cache() {
		/*
		 * this.timeCache = (Map<Integer, Long>[]) new Map[2];
		 * this.positionCache = (Map<Integer, Long>[]) new Map[2];
		 * this.timeCache[0] = new HashMap<Integer, Long>(); this.timeCache[1] =
		 * new HashMap<Integer, Long>(); this.positionCache[0] = new
		 * HashMap<Integer, Long>(); this.positionCache[1] = new
		 * HashMap<Integer, Long>();
		 */
	}

	public long getTime(int k, int p) {
		/*
		 * if (this.timeCache[k].containsKey(p)) { return
		 * this.timeCache[k].get(p).longValue(); } else { long foo =
		 * air_show.GetTime(k, p); timeCache[k].put(p, foo); return foo; }
		 */
		return air_show.GetTime(k, p);
	}

	public long getPosition(int k, int p) {
		/*
		 * if (this.positionCache[k].containsKey(p)) { return
		 * this.positionCache[k].get(p).longValue(); } else { long foo =
		 * air_show.GetPosition(k, p); this.positionCache[k].put(p, foo); return
		 * foo; }
		 */
		return air_show.GetPosition(k, p);
	}
}

class Solution {

	// LOCAL
	private void run() {
		int nodeId = message.MyNodeId();
		int nodes = message.NumberOfNodes();
		int tasks = (int) air_show.GetNumSegments();
		if (nodes > tasks) {
			nodes = tasks;
		}
		if (nodeId >= nodes)
			return;

		Cache cache = new Cache();

		int from = this.getFrom(tasks, nodes, nodeId);
		int to = from + this.getLength(tasks, nodes, nodeId);
		long[] timeSum = { 0l, 0l };
		for (int k = 0; k < 2; k++) {
			for (int i = from; i < to; i++) {
				timeSum[k] += cache.getTime(k, i);
			}
		}
		for (int node = 0; node < nodes; node++) {
			for (int k = 0; k < 2; k++) {
				message.PutLL(node, timeSum[k]);
			}
			message.Send(node);
		}
		long[][] prefixSum = new long[2][nodes];
		for (int node = 0; node < nodes; node++) {
			message.Receive(node);
			for (int k = 0; k < 2; k++) {
				prefixSum[k][node] = message.GetLL(node);
			}
		}
		for (int node = 1; node < nodes; node++) {
			for (int k = 0; k < 2; k++) {
				prefixSum[k][node] += prefixSum[k][node - 1];
			}
		}

		Interval[] intervalList = new Interval[nodes * 2];
		int[] pos = { 0, 0 };
		long[] nxt = new long[2];
		int offset = 0;
		while (pos[0] < nodes || pos[1] < nodes) {
			nxt[0] = nxt[1] = infl;
			for (int k = 0; k < 2; k++) {
				if (pos[k] < nodes) {
					nxt[k] = prefixSum[k][pos[k]];
				}
			}
			intervalList[offset] = new Interval();
			Interval interval = intervalList[offset++];
			interval.k = 0;
			if (nxt[interval.k] > nxt[interval.k ^ 1])
				interval.k ^= 1;
			interval.from = this.getFrom(tasks, nodes, pos[interval.k]);
			interval.to = interval.from + this.getLength(tasks, nodes, pos[interval.k]);
			interval.startTime = (pos[interval.k] > 0) ? prefixSum[interval.k][pos[interval.k] - 1] + 1l : 1l;
			interval.finishTime = prefixSum[interval.k][pos[interval.k]];
			pos[interval.k]++;
		}

		long startTime = (nodeId != 0) ? intervalList[(nodeId << 1) - 1].finishTime : 1l;
		long finishTime = intervalList[(nodeId << 1) + 1].finishTime;
		//stderr.printf("time interval %d->%d\n", startTime, finishTime);
		long safeDist = air_show.GetSafeDistance();
		int[] ans = { 0, 0 };
		int[] index = new int[2];
		long[] timePoint = { -1l, -1l };
		long[] duration = new long[2];
		long[][] endPoints = new long[2][2];
		long[] nextTime = new long[2];
		if (startTime < finishTime) {
			int intervalId = (nodes << 1) - 1;
			while (timePoint[0] == -1l || timePoint[1] == -1l) {
				if (timePoint[0] == -1l && intervalList[intervalId].k == 0
						&& intervalList[intervalId].startTime <= startTime) {
					timePoint[0] = intervalList[intervalId].startTime - 1l;
					index[0] = intervalList[intervalId].from;
					duration[0] = cache.getTime(0, index[0]);
					// endPoints[0][0] = cache.getPosition(0, index[0]);
					// endPoints[0][1] = cache.getPosition(0, index[0] + 1);
					nextTime[0] = timePoint[0] + duration[0];
				}
				if (timePoint[1] == -1l && intervalList[intervalId].k == 1
						&& intervalList[intervalId].startTime <= startTime) {
					timePoint[1] = intervalList[intervalId].startTime - 1l;
					index[1] = intervalList[intervalId].from;
					duration[1] = cache.getTime(1, index[1]);
					// endPoints[1][0] = cache.getPosition(1, index[1]);
					// endPoints[1][1] = cache.getPosition(1, index[1] + 1);
					nextTime[1] = timePoint[1] + duration[1];
				}
				intervalId--;
			}
			if (timePoint[0] >= startTime) {
				nextTime[0] = timePoint[0];
				index[0]--;
				duration[0] = cache.getTime(0, index[0]);
				timePoint[0] = nextTime[0] - duration[0];
			}
			while (nextTime[0] < startTime) {
				timePoint[0] = nextTime[0];
				index[0]++;
				duration[0] = cache.getTime(0, index[0]);
				// endPoints[0][0] = endPoints[0][1];
				// endPoints[0][1] = cache.getPosition(0, index[0] + 1);
				nextTime[0] = timePoint[0] + duration[0];
			}
                        endPoints[0][0] = cache.getPosition(0, index[0]);
			endPoints[0][1] = cache.getPosition(0, index[0] + 1);
			if (timePoint[1] >= startTime) {
				nextTime[1] = timePoint[1];
				index[1]--;
				duration[1] = cache.getTime(1, index[1]);
				timePoint[1] = nextTime[1] - duration[1];
			}
			while (nextTime[1] < startTime) {
				timePoint[1] = nextTime[1];
				index[1]++;
				duration[1] = cache.getTime(1, index[1]);
				// endPoints[1][0] = endPoints[1][1];
				// endPoints[1][1] = cache.getPosition(1, index[1] + 1);
				nextTime[1] = timePoint[1] + duration[1];
			}
                        endPoints[1][0] = cache.getPosition(1, index[1]);
			endPoints[1][1] = cache.getPosition(1, index[1] + 1);
			while (true) {
				int lhs = 0;
				if (nextTime[lhs] > nextTime[lhs ^ 1])
					lhs ^= 1;
				// stderr.printf("finishTime=%d, nextTime[0]=%d, nextTime[1]=%d,
				// index[0]=%d, index[1]=%d, lhs=%d\n", finishTime, nextTime[0],
				// nextTime[1], index[0], index[1], lhs);
				if (nextTime[lhs] >= finishTime)
					break;
				int rhs = lhs ^ 1;
                                //stderr.printf("check %d.%d.%d in %d.%d.%d -> %d.%d.%d\n", lhs, index[lhs]+1, nextTime[lhs], rhs, index[rhs], timePoint[rhs], rhs, index[rhs]+1, nextTime[rhs]);
				if (this.isDangerous(endPoints[lhs][1], endPoints[rhs][0], endPoints[rhs][1],
						nextTime[lhs] - timePoint[rhs], duration[rhs], safeDist)) {
					// stderr.printf("ans[%d]++\n", lhs);
					ans[lhs]++;
				}
				timePoint[lhs] = nextTime[lhs];
				index[lhs]++;
				duration[lhs] = cache.getTime(lhs, index[lhs]);
				endPoints[lhs][0] = endPoints[lhs][1];
				endPoints[lhs][1] = cache.getPosition(lhs, index[lhs] + 1);
				nextTime[lhs] = timePoint[lhs] + duration[lhs];
			}
		}

		if (nodeId != 0) {
			message.PutInt(0, ans[0]);
			message.PutInt(0, ans[1]);
			message.Send(0);
		} else {
			for (int node = 1; node < nodes; node++) {
				message.Receive(node);
				ans[0] += message.GetInt(node);
				ans[1] += message.GetInt(node);
				// stderr.printf("+node %d: %d %d\n", node, ans[0], ans[1]);
			}
			stdout.printf("%d %d\n", ans[0], ans[1]);
		}
	}

	boolean isDangerous(long pnt, long from, long to, long x, long y, long safeDist) {
		if (x < 0l || x > y)
			throw new AssertionError();
		BigInteger cap = BigInteger.valueOf(safeDist * y);
		BigInteger d0 = BigInteger.valueOf((y - x) * this.decodePosition(from, 0) + x * this.decodePosition(to, 0)
				- y * this.decodePosition(pnt, 0));
		BigInteger d1 = BigInteger.valueOf((y - x) * this.decodePosition(from, 1) + x * this.decodePosition(to, 1)
				- y * this.decodePosition(pnt, 1));
		BigInteger d2 = BigInteger.valueOf((y - x) * this.decodePosition(from, 2) + x * this.decodePosition(to, 2)
				- y * this.decodePosition(pnt, 2));
		return d0.multiply(d0).add(d1.multiply(d1)).add(d2.multiply(d2)).compareTo(cap.multiply(cap)) < 0;
	}

	long decodePosition(long code, int offset) {
		return (code >> (20 * offset)) & ((1l << 20) - 1l);
	}

	// GLOBAL
	public void exec() {
		this.stdin = new Scanner(new BufferedInputStream(System.in));
		this.stdout = new PrintWriter(new BufferedOutputStream(System.out));
		this.stderr = System.err;
		this.run();
		this.stdin.close();
		this.stdout.close();
		this.stderr.close();
	}

	final private static long infl = 0x3f3f3f3f3f3f3f3fl;

	private int getFrom(int tasks, int nodes, int nodeId) {
		return tasks / nodes * nodeId + (((nodeId) < (tasks % nodes)) ? nodeId : (tasks % nodes));
	}

	private int getLength(int tasks, int nodes, int nodeId) {
		return tasks / nodes + ((nodeId < (tasks % nodes)) ? 1 : 0);
	}

	private Scanner stdin;
	private PrintWriter stdout;
	private PrintStream stderr;
}

public class Main {
	public static void main(String[] args) {
		Solution solution = new Solution();
		solution.exec();
	}
}
