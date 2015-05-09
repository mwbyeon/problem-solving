
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

#define SQRT2 1.414213562

int main()
{
	int map_num;
	string line;
	int len, i, j;
	int dis;
	double x, y, sqrt_dis;
	string dir;
	
	for ( map_num=1 ; cin>>line, line!="END" ; ++map_num ) {
		len = line.length();
		x = y = 0.0;
		
		for ( i=0 ; i<len ; ) {
			for ( j=i; isdigit(line[j]) ; ++j );
			dis = atoi(line.substr(i,j-i).c_str());

			for ( i=j ; isupper(line[j]) ; ++j );
			dir = line.substr(i,j-i);

			if ( dir=="N" ) {
				y += dis;
			}
			else if ( dir=="NE" ) {
				x += dis/SQRT2;
				y += dis/SQRT2;
			}
			else if ( dir=="E" ) {
				x += dis;
			}
			else if ( dir=="SE" ) {
				x += dis/SQRT2;
				y -= dis/SQRT2;
			}
			else if ( dir=="S" ) {
				y -= dis;
			}
			else if ( dir=="SW" ) {
				x -= dis/SQRT2;
				y -= dis/SQRT2;
			}
			else if ( dir=="W" ) {
				x -= dis;
			}
			else if ( dir=="NW" ) {
				x -= dis/SQRT2;
				y += dis/SQRT2;
			}

			for ( i=j ; i<len && !isdigit(line[i]) ; ++i);
		}
		printf("Map #%d\n", map_num);
		printf("The treasure is located at (%.3f,%.3f).\n", x, y);
		printf("The distance to the treasure is %.3f.\n\n", sqrt(x*x+y*y));
	}
	return 0;
}
