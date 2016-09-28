/*	Codeforces 716C - Plus and Square Root	
 *	Created by Ziyi Tang
 */

import java.util.Scanner;
import java.math.BigInteger;
public class PlusAndSquareRoot{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		long n = 0;
		n = sc.nextLong();
		BigInteger pre = BigInteger.valueOf(2);
		for(long i = 1; i <= n; i++){
			BigInteger ii = BigInteger.valueOf(i);
			BigInteger tmp = ii.pow(2);
			BigInteger now = tmp.add(ii);
			BigInteger ans = (now.pow(2).subtract(pre)).divide(ii);
			System.out.println(ans.toString()+",");
			pre = tmp.add(ii);
		}
	}
}