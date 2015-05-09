#include <iostream>
#include <algorithm>
using namespace std;

int first[16000000], second[16000000];

int main()
{
	int n;
	scanf("%d", &n);
	
	int num[n][4];
	for ( int i=0 ; i<n ; ++i ) scanf("%d %d %d %d", &num[i][0], &num[i][1], &num[i][2], &num[i][3]);
	
	int k = 0;
	for ( int i=0 ; i<n ; ++i )
		for ( int j=0 ; j<n ; ++j, ++k )
			first[k] = num[i][0]+num[j][1];
	
	sort(first, first+k);
	
	int res = 0;
	for ( int i=0 ; i<n ; ++i ) {
		for ( int j=0 ; j<n ; ++j ) {
			int sum = num[i][2]+num[j][3];
			int* p1 = lower_bound(first, first+k, -sum);
			int* p2 = upper_bound(first, first+k, -sum);
			res += p2-p1;
		}
	}

	printf("%d\n", res);
	
	
	
	return 0;

}
