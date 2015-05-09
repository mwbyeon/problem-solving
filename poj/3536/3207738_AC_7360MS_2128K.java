
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		int n = cin.nextInt();
		int a=1, b=1, c=1;
		int minv = Integer.MAX_VALUE;
		
		for ( int i=1 ; i*i<=n ; ++i ) {
			if ( n%i==0 ) {
				int nn = n/i;
				for ( int j=1 ; j*j<=nn ; ++j ) {
					if ( nn%j==0 ) {
						int surf = i*j+j*nn/j+i*nn/j;
						if ( surf < minv ) {
							minv = surf;
							a = i;
							b = j;
							c = nn/j;							
						}
					}
				}
			}
		}
		System.out.println(a+" "+b+" "+c);
	}
}
