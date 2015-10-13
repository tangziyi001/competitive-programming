import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			BigInteger b = sc.nextBigInteger();
			BigInteger p = sc.nextBigInteger();
			BigInteger m = sc.nextBigInteger();
			BigInteger re = b.modPow(p,m);
			System.out.println(re);
		}
	}
}