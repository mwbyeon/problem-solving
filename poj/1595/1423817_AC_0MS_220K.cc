

#include <iostream>
#include <cstdio>
using namespace std;

int prime[200], pc;
bool che[1001];
int n, c, cnt;

void find_prime()
{
	pc = 1;
	prime[0] = 1;
	memset(che, true, sizeof(che));
	
	for ( int i=2 ; i<1001 ; ++i ) {
		if ( che[i] ) {
			prime[pc++] = i;
			for ( int j=i+i ; j<1001 ; j+=i )
				che[j] = false;
		}
	}
}

void print_prime()
{
	int beg, end, i;
	cnt=0;
	for ( i=0 ; i<pc ; ++i )
		if ( prime[i]<=n )
			cnt++;

	if ( cnt&1 ) { // odd
		if ( cnt<c*2-1 ) {
			beg = 0;
			end = cnt;
		}
		else {
			beg = cnt/2-c+1;
			end = cnt-beg;
		}
	}
	else { // even
		if ( cnt<c*2 ) {
			beg = 0;
			end = cnt;
		}
		else {
			beg = cnt/2-c;
			end = cnt-beg;
		}
	}
	printf("%d %d: ", n, c);
	for ( i=beg ; i<end ; ++i )
		printf("%d ", prime[i]);
	printf("\n\n");
}

int main()
{
	find_prime();
	
	for ( ; cin >> n >> c ; )
		print_prime();
	return 0;
}
