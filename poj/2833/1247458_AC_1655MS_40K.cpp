
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n1, n2, n;
	while ( 1 ) 
	{
		scanf("%d %d %d ", &n1, &n2, &n);
		if ( n1==0 && n2==0 && n==0 ) return 0;

		int maxv[11];
		int minv[11];
		int tmp[22];
		int grade;

		int i, t=n1+n2;
		for ( i=0 ; i<t ; ++i )
			scanf("%d ", &tmp[i]);
			
		sort(tmp, &tmp[t]);
		for ( i=0 ; i<n2 ; ++i )
			minv[i] = tmp[i];
		for ( i=n2 ; i<t ; ++i )
			maxv[i-n2] = tmp[i];

		__int64 sum=0;
		t = n-n1-n2;
		for ( i=0 ; i<t ; ++i ) {
			scanf("%d ", &grade);
			if ( grade>=maxv[0] ) {
				sum += maxv[0];
				maxv[0] = grade;
				sort(maxv, &maxv[n1]);
			}
			else if ( grade<=minv[n2-1] ) {
				sum += minv[n2-1];
				minv[n2-1] = grade;
				sort(minv, &minv[n2]);
			}
			else {
				sum += grade;
			}
		}
		printf("%.6lf\n", (double)sum/(double)t);
	}
	return 0;
}
