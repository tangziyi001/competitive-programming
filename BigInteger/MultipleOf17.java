/*	
 *	Created by Ziyi Tang
 */

import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		while(true){
			BigInteger a = sc.nextBigInteger();
			if (a.equals(BigInteger.ZERO)){
				break;
			}
			else{
				BigInteger mm = BigInteger.valueOf(17);
				BigInteger mod = a.mod(mm);
				if (mod == BigInteger.ZERO){
					System.out.println(1);
				}
				else{
					System.out.println(0);
				}
			}
		}
	}
}