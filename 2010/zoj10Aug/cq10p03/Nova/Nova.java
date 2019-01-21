import java.util.Arrays;
import java.util.Scanner;

public class Nova implements Runnable {

	/**
	 * Created by momodi
	 * 
	 * this code will try to check data range.
	 */
	public static void main(String[] args) {
		new Thread(new Nova()).start();
	}
	int n, m, t;
	int[] lichx, lichy, lichr, licht, wispx, wispy, treex, treey, treer, now, match;
	boolean[] flag;
	boolean[][] adj;

	long sqr(long a) {
	    return a * a;
	}
	long dist2(int ax, int ay, int bx, int by) {
	    return sqr(ax - bx) + sqr(ay - by);
	}
	long cross(int ax, int ay, int bx, int by, int cx, int cy) {
	    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
	}
	long mul(int  ax, int ay, int bx, int by, int cx, int cy) {
	    return (bx - ax) * (cx - ax) + (by - ay) * (cy - ay);
	}

	boolean block(int a, int b, int c) {
	    if (sqr(cross(lichx[a], lichy[a], wispx[b], wispy[b], treex[c], treey[c])) > sqr(treer[c]) * dist2(lichx[a], lichy[a], wispx[b], wispy[b])) {
	        return false;
	    }
	    return mul(lichx[a], lichy[a], wispx[b], wispy[b], treex[c], treey[c]) >= 0 &&
	        mul(wispx[b], wispy[b], lichx[a], lichy[a], treex[c], treey[c]) >= 0;
	}

	boolean can_see(int a, int b) {
	    long d2 = sqr(lichx[a] - wispx[b]) + sqr(lichy[a] - wispy[b]);
	    if (d2 > sqr(lichr[a])) {
	        return false;
	    }
	    for (int i = 0; i < t; ++i) {
	        if (block(a, b, i)) {
	            return false;
	        }
	    }
	    return true;
	}
	boolean dfs(int v) {
	    for (int i = 0; i < m; ++i) {
	        if (adj[v][i] && flag[i] == false) {
	            flag[i] = true;
	            if (match[i] == -1 || dfs(match[i])) {
	                match[i] = v;
	                return true;
	            }
	        }
	    }
	    return false;
	}

	@Override
	public void run() {
		try {
			Scanner cin = new Scanner(System.in);
			int ca = cin.nextInt();
			rangeChecker(ca, 1, 20);
		    while (ca-- > 0) {
		    	n = cin.nextInt();
		    	m = cin.nextInt();
		    	t = cin.nextInt();
		    	rangeChecker(n, 0, 200);
		    	rangeChecker(m, 0, 200);
		    	rangeChecker(t, 0, 200);
		    	lichx = new int[n];
		    	lichy = new int[n];
		    	lichr = new int[n];
		    	licht = new int[n];
		    	wispx = new int[m];
		    	wispy = new int[m];
		    	treex = new int[t];
		    	treey = new int[t];
		    	treer = new int[t];
		    	
		        for (int i = 0; i < n; ++i) {
		        	lichx[i] = cin.nextInt();
		        	lichy[i] = cin.nextInt();
		        	lichr[i] = cin.nextInt();
		        	licht[i] = cin.nextInt();
		        	rangeChecker(lichx[i], -10000, 10000);
		        	rangeChecker(lichy[i], -10000, 10000);
		        	rangeChecker(lichr[i], 0, 10002);
		        	rangeChecker(licht[i], 0, 10002);
		        }
		        for (int i = 0; i < m; ++i) {
		        	wispx[i] = cin.nextInt();
		        	wispy[i] = cin.nextInt();
		        	rangeChecker(wispx[i], -10000, 10000);
		        	rangeChecker(wispy[i], -10000, 10000);
		        }
		        for (int i = 0; i < t; ++i) {
		        	treex[i] = cin.nextInt();
		        	treey[i] = cin.nextInt();
		        	treer[i] = cin.nextInt();
		        	rangeChecker(treex[i], -10000, 10000);
		        	rangeChecker(treey[i], -10000, 10000);
		        	rangeChecker(treer[i], 0, 10002);
		        }
		        adj = new boolean[n][m];
		        for (int i = 0; i < n; ++i) {
		            for (int j = 0; j < m; ++j) {
		                adj[i][j] = can_see(i, j);
		            }
		        }
		        int tot = 0;
		        int ans = 0;
		        match = new int[m];
		        Arrays.fill(match, -1);
		        now = new int[n];
		        while (tot < m) {
		            int mmin = Integer.MAX_VALUE;
		            int v = -1;
		            for (int i = 0; i < n; ++i) {
		            	if (now[i] < mmin) {
		            		mmin = now[i];
		                    v = i;
		                }
		            }
		            if (v == -1) {
		                break;
		            }
		            flag = new boolean[m];
		            if (dfs(v)) {
		                ans = now[v];
		                now[v] += licht[v];
		                ++tot;
		            } else {
		                now[v] = Integer.MAX_VALUE;
		            }
		        }
		        if (tot == m) {
		            System.out.println(ans);
		        } else {
		        	System.out.println(-1);
		        }
		    }
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	void rangeChecker(int a, int s, int t) throws Exception {
		if (a < s || a > t) {
			throw new Exception("Range Error");
		}
	}

}
