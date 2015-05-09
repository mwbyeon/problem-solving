// law of cosine
// a = b*cosC + c*cosB

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for ( int t=1 ; T-- ; ++t ) {
		printf("Scenario #%d:\n", t);
		double R, n;
		scanf("%lf %lf", &R, &n);
		double theta = 0.5*M_PI - (M_PI/n);
		double r = (R*cos(theta))/(1.0+cos(theta));
		printf("%.3lf\n\n", r);
	}
	return 0;
}
