
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int b = cin.nextInt();
		int w = cin.nextInt();
		
		if ( b==0 && w==0 ) {
			System.out.println("Impossible");
			return;
		}
		if ( b > w ) {
			b ^= w; w ^= b; b ^= w;
		}
		
		int n = 0, t = 0, add = 0;
		while ( t+(n&1)<=w && t<=b ) {
			if ( n%2==1 ) add += 2;
			t += add;
			++n;
		}
		System.out.println(n-1);
	}
}
