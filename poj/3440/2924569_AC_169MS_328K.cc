#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define sq(x) (x)*(x)

int main()
{
	int T;
	scanf("%d", &T);
	for ( int _T=1 ; _T<=T ; ++_T ) {
		double m, n, t, c;
		scanf("%lf %lf %lf %lf", &m, &n, &t, &c);

		double total = (t*m)*(t*n);
		double t2 = (t-c)*c*(m*(n-1)+n*(m-1)) + c*c*(m+n-2);
		double t4 = sq(0.5*c)*M_PI*(m-1)*(n-1);
		double t3 = c*c*(m-1)*(n-1)-t4;
		double t1 = total-t2-t3-t4;


		printf("Case %d:\n", _T);
		printf("Probability of covering 1 tile  = %.4lf", t1/total*100.0 ); puts("%");
		printf("Probability of covering 2 tiles = %.4lf", t2/total*100.0 ); puts("%");
		printf("Probability of covering 3 tiles = %.4lf", t3/total*100.0 ); puts("%");
		printf("Probability of covering 4 tiles = %.4lf", t4/total*100.0 ); puts("%");
		puts("");
	}
	return 0;
}
