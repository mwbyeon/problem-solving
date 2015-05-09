
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	const double pi = 3.1415926536;
	double ax, ay, a, bx, by, b, c, arad, brad, asec, bsec, s, tri, area=0;


	cin >> ax >> ay >> a >> bx >> by >> b;

	c = sqrt ( pow(ax-bx,2)+pow(ay-by,2) );

	if ( a+b <= c )	area = 0;
	else if ( a+c <= b ) area = a*a*pi;
	else if ( b+c <= a ) area = b*b*pi;
	else {
		arad = acos((a*a+c*c-b*b)/(2*a*c))*2;
		brad = acos((b*b+c*c-a*a)/(2*b*c))*2;

		asec = a*a*arad/2;
		bsec = b*b*brad/2;

		s = (a+b+c)/2;
		tri = sqrt(s*(s-a)*(s-b)*(s-c));

		area = asec+bsec-2*tri;
	}
	printf("%.3lf\n",area);
	//cout << area << endl;
}