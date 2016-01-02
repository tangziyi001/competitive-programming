/*
 *	UVA 10219
 *	Created by Ziyi Tang
 *  Combinatorial Formula C(n,k)
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static BigInteger com(long n,long k){
		BigInteger nom = BigInteger.ONE;
		BigInteger den = BigInteger.ONE;
		long count = k;
		for(long i = 0; i < count; i++){
			nom = nom.multiply(BigInteger.valueOf(n));
			den = den.multiply(BigInteger.valueOf(k));
			n--;
			k--;
		}
		return nom.divide(den);
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			long n = sc.nextLong();
			long k = sc.nextLong();
			if(k > n/k)
				k = n-k;
			BigInteger re = com(n,k);
			System.out.println(re.toString().length());
			
		}
	}
}