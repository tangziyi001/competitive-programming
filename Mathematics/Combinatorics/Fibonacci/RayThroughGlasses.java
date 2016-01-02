/*	UVA 10334
 *	Created by Ziyi Tang
 *	Basic Fib
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String args[]){
		BigInteger[] all = new BigInteger[1005];
		all[0] = BigInteger.ONE;
		all[1] = BigInteger.valueOf(2);
		for(int i = 2; i < 1001; i++){
			all[i] = all[i-1].add(all[i-2]);
		}
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String n = sc.next();
			int i = Integer.parseInt(n);
			System.out.println(all[i]);
		}
	}
}