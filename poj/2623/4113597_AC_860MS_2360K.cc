#include <iostream>
using namespace std;

int main()
{
	double seq[250001];
	int n;
	scanf("%d", &n);
	for ( int i=0 ; i<n ; ++i ) scanf("%lf", seq+i);
	sort(seq, seq+n);

	if ( n%2 ) {
		printf("%.1lf\n", seq[n/2]);
	}
	else {
		printf("%.1lf\n", 0.5*(seq[n/2]-seq[(n-1)/2])+seq[(n-1)/2]);
	}

	return 0;
}

