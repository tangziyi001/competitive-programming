/*	
 *	UVA 10541
 *	Created by Ziyi Tang
 *  C (The number of white squares + 1, The number of black numbers)
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{

	public static BigInteger comb(long n, long k){
		if(n-k < k)
			k = n-k;
		long count = k;
		BigInteger nom = BigInteger.ONE;
		BigInteger den = BigInteger.ONE;
		for(long i = 0; i < count; i++){
			nom = nom.multiply(BigInteger.valueOf(n));
			den = den.multiply(BigInteger.valueOf(k));
			n--;k--;
		}
		return nom.divide(den);
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for(int t = 0; t < test; t++){
			long n = sc.nextLong();
			long k = sc.nextLong();
			long sumb = 0;
			for(int i = 0; i < k; i++){
				long tmp = sc.nextLong();
				sumb+=tmp;
			}
			long pos = n-sumb+1;
			if(pos < k)
				System.out.println(0);
			else{
				BigInteger re = comb(pos,k);
				System.out.println(re);
			}

		}
	}
}