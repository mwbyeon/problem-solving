#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	string line;
	for ( int T=1 ; cin >> line, line[0]!='E' ; ++T ) {
		int len = line.length();
		double x=0.0, y=0.0;
		int step = 0;
		char buf[4];

		for ( int i=0 ; i<len ; ++i ) {
			if ( isdigit(line[i]) ) {
				step *= 10;
				step += line[i]-'0';
			}
			else if ( isalpha(line[i]) ) {
				if ( isalpha(line[i+1]) ) {
					double dig = step/sqrt(2.0);
					if ( line[i]=='N' ) y += dig;
					if ( line[i]=='S' ) y -= dig;
					if ( line[i+1]=='E' ) x += dig;
					if ( line[i+1]=='W' ) x -= dig;
					++i;
				}
				else {
					if ( line[i]=='N' ) y += step;
					if ( line[i]=='S' ) y -= step;
					if ( line[i]=='E' ) x += step;
					if ( line[i]=='W' ) x -= step;
				}
			}
			else { // comma;
				step = 0;
			}
		}

		printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n",
				T, x, y, hypot(x,y));

		
	}
	return 0;
}

