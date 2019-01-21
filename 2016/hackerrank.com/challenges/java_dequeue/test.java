import java.util.*;

class Solve {
	public static int run(List<Integer> array, int size){
		Map<Integer, Integer> hashmap=new HashMap<Integer, Integer>();
		int length=array.size(), ans=0, cur=0;
		for(int til=0; til<length; til++){
			if(til-size>=0){
				hashmap.put(array.get(til-size), hashmap.get(array.get(til-size))-1);
				if(hashmap.get(array.get(til-size))==0)cur--;
			}
			if(!hashmap.containsKey(array.get(til))){
				hashmap.put(array.get(til), 0);
			}
			hashmap.put(array.get(til), hashmap.get(array.get(til))+1);
			if(hashmap.get(array.get(til))==1)cur++;
			ans=Math.max(ans, cur);
		}
		return ans;
	}
}

public class test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		List<Integer> array=new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			int num = in.nextInt();
			array.add(Integer.valueOf(num));
		}
		System.out.println(Solve.run(array, m));
	}
}
