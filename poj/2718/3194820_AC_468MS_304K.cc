#include <iostream>
using namespace std;

int main()
{
	int T;
	char ch;
	int digits[11];
	scanf("%d ", &T);
	while ( T-- ) {
		int n = 0, res = INT_MAX, t1, t2;
		while ( (ch=getchar())!='\n' ) if ( isdigit(ch) ) digits[n++] = ch-'0';

		int k = n/2;
		do {
			if ( (digits[0]!=0 || k==1) && (digits[k]!=0 || n-k==1) ) {
				t1 = t2 = 0;
				for ( int i=0 ; i<k ; ++i ) t1 *= 10, t1 += digits[i];
				for ( int i=k ; i<n ; ++i ) t2 *= 10, t2 += digits[i];
				res <?= abs(t1-t2);
			}
		} while ( next_permutation(digits, digits+n) );

		printf("%d\n", res);
	}
	return 0;
}
