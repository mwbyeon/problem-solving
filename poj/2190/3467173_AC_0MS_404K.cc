#include <iostream>
using namespace std;

int main()
{
	string isbn;
	cin >> isbn;
	int idx;
	for ( int i=0 ; i<10 ; ++i ) {
		if ( isdigit(isbn[i]) ) {
			isbn[i] -= '0';
		}
		else if ( isbn[i]=='X' ) {
			if ( i<9 ) {
				puts("-1");
				return 0;
			}
			isbn[i] = 10;
		}
		else {
			isbn[i] = 0;
			idx = i;
		}
	}
	int sum;
	for ( int i=0 ; i<10 ; ++i ) {
		isbn[idx] = i;
		sum = 0;
		for ( int j=0 ; j<10 ; ++j ) sum += isbn[j]*(10-j);
		if ( sum%11==0 ) {
			printf("%d\n", i);
			return 0;
		}
	}

	if ( idx==9 && (sum+1)%11==0 ) {
		puts("X");
		return 0;
	}

	puts("-1");
	return 0;
}
