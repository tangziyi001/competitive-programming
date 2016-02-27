// UVA 10689
import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String args[]){
		BigInteger fib[] = new BigInteger[15005];
		Scanner sc = new Scanner(System.in);
		String test_str = sc.next();
		int test = Integer.parseInt(test_str);
		for(int t = 0; t < test; t++){
			long a = Integer.parseInt(sc.next());
			long b = Integer.parseInt(sc.next());
			int n = Integer.parseInt(sc.next());
			int m = Integer.parseInt(sc.next());

			fib[0] = BigInteger.valueOf(a);
			fib[1] = BigInteger.valueOf(b);
			int idx = 0;
			if(m == 1){
				idx = n%60;
			}
			else if(m == 2){
				idx = n%300;
			}
			else if(m == 3){
				idx = n%1500;
			}
			else{
				idx = n%15000;
			}
			for(int i = 2; i < idx+1; i++){
				fib[i] = (fib[i-1].add(fib[i-2])).mod(BigInteger.valueOf(10000));
			}
			String re = fib[idx].toString();
			int sz = re.length();
			int num;
			if(sz <= m){
				num = Integer.parseInt(re);
			}
			else
			 	num = Integer.parseInt(re.substring(sz-m));
			System.out.println(num);
		}
	}
}