/*	UVA 11609
 *	Created by Ziyi Tang
 *	N*2^(n-1)
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		for(int cas = 0; cas < test; cas++){
			BigInteger num = sc.nextBigInteger();
			BigInteger two = BigInteger.valueOf(2);
			BigInteger MOD = BigInteger.valueOf(1000000007);
			BigInteger teams = two.modPow(num.subtract(BigInteger.ONE),MOD);
			BigInteger res = teams.multiply(num);
			res = res.mod(MOD);
			System.out.printf("Case #%d: %d\n", cas+1, res.longValue());
		}
	}
}