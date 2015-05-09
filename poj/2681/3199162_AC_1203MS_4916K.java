import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		int T = Integer.parseInt(cin.nextLine());
		for ( int t=1 ; t<=T ; ++t ) { 
			int[] cnt = new int[26];
			String word1 = cin.nextLine();
			String word2 = cin.nextLine();
			//System.out.println(word1 + " " + word2);
			int len1 = word1.length();
			int len2 = word2.length();
			for ( int i=0 ; i<len1 ; ++i ) cnt[word1.charAt(i)-'a']++;
			for ( int i=0 ; i<len2 ; ++i ) cnt[word2.charAt(i)-'a']--;
			int res = 0;
			for ( int i=0 ; i<26 ; ++i ) res += Math.abs(cnt[i]);
			System.out.println("Case #" + t + ":  " + res);
		}
	}
}
