#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
double r, h, d1, a1, d2, a2;
double sector_r, sector_l, sector_a, angle, distance, a;
while ( scanf("%lf %lf %lf %lf %lf %lf", &r, &h, &d1, &a1, &d2, &a2)!=EOF )
{
 sector_r = sqrt(pow(r,2)+pow(h,2));
 sector_l = 2*PI*r;
 sector_a = sector_l*360/(2*PI*sector_r);
 a = fabs(a1-a2)>180 ? 360-fabs(a1-a2) : fabs(a1-a2);
 angle = sector_a*a/360;
 distance = sqrt( pow(d1,2)+pow(d2,2)-(2*d1*d2*cos(2*PI*angle/360)) );

 printf("%.2f\n",distance);
}
return 0;
}

