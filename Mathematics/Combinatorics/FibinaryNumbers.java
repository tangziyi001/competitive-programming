/*	UVA 00763
 *	Created by Ziyi Tang
 *	Zeckedorf's theorem
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{
	
	public static void main(String args[]){
		BigInteger[] fib = new BigInteger[105];
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.valueOf(2);
		for(int i = 2; i < 101; i++){
			fib[i] = fib[i-1].add(fib[i-2]);
		}
		Scanner sc = new Scanner(System.in);
		String a = new String();
		String b = new String();
		int start = 0;
		while(sc.hasNext()){
			if(start != 0){
				System.out.println();
			}
			start++;
			BigInteger aval = BigInteger.ZERO;
			a = sc.next();
			//System.out.println(a);
			int sz = a.length();
			for(int i = sz-1; i >= 0; i--){
				if(a.substring(i,i+1).equals("1")){
					aval = aval.add(fib[sz-1-i]);
				}
			}
			//System.out.println(aval);

			BigInteger bval = BigInteger.ZERO;
			b = sc.next();
			//System.out.println(b);
			sz = b.length();
			for(int i = sz-1; i >= 0; i--){
				if(b.substring(i,i+1).equals("1")){
					bval = bval.add(fib[sz-1-i]);
				}
			}
			//System.out.println(bval);
			BigInteger num = aval.add(bval);
			//System.out.println(num);
			String c = new String("");
			int flag = 0;
				for(int i = 100; i >= 0; i--){
					if(num.compareTo(fib[i]) >= 0){
						num = num.subtract(fib[i]);
						c += "1";
						flag = 1;
					}
					else if(flag == 1){
						c+="0";
					}
				}
			
			if((aval.add(bval)).equals(BigInteger.ZERO)){
				System.out.println(0);
			}else{
				System.out.println(c);
			}
			
		}
	}
}