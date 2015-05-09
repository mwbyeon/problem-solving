import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for ( int t=1 ; t<=T ; ++t ) {
			int n = cin.nextInt();
			int k = (2*n+1)/3;
			int[] res_x = new int[k];
			int[] res_y = new int[k];

			int x = n-k+1, y = 1;
			for ( int i=0 ; i<k ; ++i ) {
				res_x[i] = x;
				res_y[i] = y;
				x++;
				y += 2;
				if ( x < y ) y = 2;
			}

			System.out.print(t + " " + n + " " + k );
			for ( int i=0 ; i<k ; ++i ) {
				if ( i%8==0 ) System.out.println("");
				System.out.print("[" + res_x[i] + "," + res_y[i] + "] ");
			}
			System.out.println("\n");	
		}
	}
}
