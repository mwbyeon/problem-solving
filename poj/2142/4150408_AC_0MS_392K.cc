#include <iostream>
using namespace std;

int a, b, d;
int res_x, res_y;

void update(int x, int y) {
	if ( x < 0 || y < 0 ) return ;

	if ( res_x + res_y == x+y ) {
		if ( a*res_x+b*res_y > a*x+b*y ) {
			res_x = x;
			res_y = y;
		}
	}
	else {
		if ( res_x+res_y > x+y ) {
			res_x = x;
			res_y = y;
		}
	}
}

int main()
{
	while ( scanf("%d %d %d", &a, &b, &d), a ) {
		res_x = res_y = 987654321;

		int x, y;
		for ( x=0 ; (a*x+d)%b ; ++x );
		y = (a*x+d)/b;
		update(x,y);

		for ( x=0 ; (d-a*x)%b ; ++x );
		y = (d-a*x)/b;
		update(x,y);

		for ( y=0 ; (b*y+d)%a ; ++y );
		x = (b*y+d)/a;
		update(x,y);

		for ( y=0 ; (d-b*y)%a ; ++y );
		x = (d-b*y)/a;
		update(x,y);

		printf("%d %d\n", res_x, res_y);
	}
	return 0;
}	

