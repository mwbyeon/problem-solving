import java.util.*;

public class Main {
	public static boolean nextPermutation(int[] perm, int beg, int end) {
		int i, j;
		for ( i=end-1 ; i-- > beg && perm[i] > perm[i+1] ; ) ;
		if ( i<beg ) return false;
		for ( j=end ; --j > i && perm[j] < perm[i] ; ) ;
		int t = perm[i]; perm[i] = perm[j]; perm[j] = t;
		for ( j=end ; --j > ++i ; ) {
			t = perm[i]; perm[i] = perm[j]; perm[j] = t;
		}
		return true;
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = Integer.parseInt(cin.nextLine());
		for ( int t=0 ; t<T ; ++t ) {
			String line = cin.nextLine();
			Scanner sin = new Scanner(line);
			int[] perm = new int[11];
			int n = 0;
			
			while ( sin.hasNext() ) perm[n++] = sin.nextInt();
			
			int res = Integer.MAX_VALUE;
			int div = n/2;
			
			do {
				if ( (div==1 || perm[0]!=0) && (n-div==1 || perm[div]!=0) ) {
					int t1 = 0, t2 = 0;
					for ( int i=0 ; i<div ; ++i ) {
						t1 *= 10;
						t1 += perm[i];
					}
					for ( int i=div ; i<n ; ++i ) {
						t2 *= 10;
						t2 += perm[i];
					}
					int diff = Math.abs(t1-t2);
					if ( diff < res ) res = diff;
				}
			} while ( nextPermutation(perm, 0, n) );
			System.out.println(res);
		}
	}
}
