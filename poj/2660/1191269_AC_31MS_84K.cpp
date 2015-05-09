
#include <iostream>
#include <cmath>
using namespace std;

#define square(x)	(x)*(x)
 
typedef struct location {
	double x, y, z;
} loc;

double getDistance(loc& l1,loc& l2)
{
	return sqrt(square(l2.x-l1.x)+square(l2.y-l1.y)+square(l2.z-l1.z));
}

int main()
{
	int k, m, i, j, result;
	loc sat[100], tar, center={0.00, 0.00, 0.00};
	double range, distance;
	const double pi=3.1415926535, radius=20000.0/pi;
	
	while ( cin >> k >> m, k && m )
	{
		result = 0;
		for ( i=0 ; i<k ; i++ )
			cin >> sat[i].x >> sat[i].y >> sat[i].z;
		for ( i=0 ; i<m ; i++ ) {
			cin >> tar.x >> tar.y >> tar.z;
			for ( j=0 ; j<k ; j++ ) {
				distance = getDistance(center, sat[j]);
				range = sqrt(square(distance)-square(radius));
				distance = getDistance(tar, sat[j]);
				if ( range>=distance ) {
					result++;
					break;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}
				
			
