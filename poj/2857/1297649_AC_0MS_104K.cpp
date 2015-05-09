
#include <iostream>
using namespace std;

enum { BLACK, WHITE };

double pw, ph; 
bool color;

bool get_color(double wid, double hei, double w, double h)
{
//	cout << "color " << color << endl;
	color = color==BLACK?WHITE:BLACK;
	if ( w<wid*pw ) {
		if ( h>hei*ph )	return color;
		else
			return get_color(wid*pw, hei*ph, w, h);
	}
	else {
		if ( h<hei*ph ) return color;
		else
			return get_color(wid*(1-pw), hei*(1-ph), w-wid*pw, h-hei*ph);
	}
}
	

int main()
{
	int n;
	double wid, hei, w, h;
	
	for ( int i=1 ; ; ++i )
	{
		cin >> wid >> hei >> pw >> ph;
		if ( wid==0 && hei==0 && pw==0 && ph==0 )
			return 0;

		cout << "Case " << i << ":" << endl;

		cin >> n;
		do {
			cin >> w >> h;
			color = WHITE;
			if ( get_color(wid, hei, w, h)==BLACK )
				cout << "black" << endl;
			else
				cout << "white" << endl;
		} while ( --n );
	}
}
