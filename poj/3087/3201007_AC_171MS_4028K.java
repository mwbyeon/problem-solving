
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for ( int t=1 ; t<=T ; ++t ) {
			int c = cin.nextInt();
			String s1 = cin.next();
			String s2 = cin.next();
			String result = cin.next();
			String shuffle = new String();
			for ( int i=0 ; i<c ; ++i ) {
				shuffle += s2.charAt(i);
				shuffle += s1.charAt(i);
			}
			int res = 1;
			TreeSet<String> already = new TreeSet<String>();
			while ( shuffle.compareTo(result)!=0 ) {
				if ( already.contains(shuffle) ) {
					res = -1;
					break;
				}
				already.add(shuffle);
				String next = new String();
				for ( int i=0 ; i<c ; ++i ) {
					next += shuffle.charAt(i+c);
					next += shuffle.charAt(i);
				}
				shuffle = next;
				++res;
			}
			System.out.println(t + " " + res);			
		}
	}

}
