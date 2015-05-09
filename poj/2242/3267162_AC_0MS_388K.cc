// http://www.ezformula.net/esne/aboard/addon.php?file=main_form_detail.php&fcode=1111334&bgrcode=&mgrcode

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c, s, r;
	while ( scanf("%lf %lf %lf %lf %lf %lf\n", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF ) {
		a = hypot(x2-x1, y2-y1);
		b = hypot(x3-x2, y3-y2);
		c = hypot(x1-x3, y1-y3);
		s = (a+b+c)*0.5;
		r = (a*b*c)/(4.0*sqrt(s*(s-a)*(s-b)*(s-c)));
		printf("%.2lf\n", 2.0*r*3.141592653589793);
	}

	return 0;
}
